#define _XOPEN_SOURCE 500 // Needed to use nftw(). No alternative found.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <ftw.h>
#include <unistd.h>
#include <omp.h>

#define MAX_PATH_LENGTH 256

const char *romPath = "mzm_us_baserom.gba";
const char *databasePath = "database.txt";
const char *dataPath = "data/";

void create_directories(const char *filePath)
{
    // NOTE: filePath contains the full path for a given data asset.
    // This function creates its full directory hierarchy.
    const char *lastSlash = strrchr(filePath, '/');
    size_t dirPathLen = lastSlash - filePath + 1;

    char *dirPath = (char *)malloc((dirPathLen + 1) * sizeof(char));
    if (dirPath == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Retrieve the directory filePath from the fila filePath:
    strncpy(dirPath, filePath, dirPathLen);
    dirPath[dirPathLen] = '\0';

    // Create directory hierarchy
    char *p = strdup(dirPath);
    char *sep = strchr(p + 1, '/');
    while(sep != NULL)
    {
        *sep = '\0';
        mkdir(p, 0755);
        *sep = '/';
        sep = strchr(sep + 1, '/');
    }

    free(p);
    free(dirPath);
}

int remove_file_or_directory(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    int rv = remove(fpath);

    if (rv)
    {
    	// If found an error, print to stderr with errno:
        perror(fpath);
	exit(EXIT_FAILURE);
    }

    return rv;
}

void str_split(const char *s, char del, char ***result)
{
    int count = 0;
    const char *p = s;
    while (*p != '\0')
    {
        if (*p == del)
            count++;
        p++;
    }
    count++; // Add 1 to get last substring

    *result = (char **)malloc(count * sizeof(char *));
    size_t idx = 0;
    const char *start = s;
    p = s;
    while (*p != '\0')
    {
        if (*p == del)
        {
            size_t len = p - start;
            (*result)[idx] = (char *)malloc((len + 1) * sizeof(char));
            strncpy((*result)[idx], start, len);
            (*result)[idx][len] = '\0';
            idx++;
            start = p + 1;
        }
        p++;
    }
    // Last substring:
    size_t len = p - start;
    (*result)[idx] = (char *)malloc((len + 1) * sizeof(char));
    strncpy((*result)[idx], start, len);
    (*result)[idx][len] = '\0';
}

int main()
{
    FILE *romFile = fopen(romPath, "rb");
    if (!romFile)
    {
        fprintf(stderr, "The ROM file (%s) does not exist.\n", romPath);
        exit(EXIT_FAILURE);
    }
    fclose(romFile);

    FILE *databaseFile = fopen(databasePath, "r");
    if (!databaseFile)
    {
        fprintf(stderr, "The database file (%s) does not exist.\n", databasePath);
        exit(EXIT_FAILURE);
    }

    // Declare important variables:
    int nthreads = omp_get_num_procs();
    char **database;
    size_t databaseSize = 0;

    #pragma omp parallel sections
    {
        // Concurrently delete previously extracted data, if any:
        #pragma omp section
        {
            struct stat st;
            if (stat(dataPath, &st) == 0)
	    {
                printf("Deleting old files...\n");
                nftw(dataPath, remove_file_or_directory, 10, FTW_DEPTH | FTW_PHYS);
            }
        }

        // Concurrently parse the database file:
        #pragma omp section
        {
            printf("Using %d parallel threads.\n", nthreads);

            // Get number of database entries:
            char line[MAX_PATH_LENGTH];
            while (fgets(line, sizeof(line), databaseFile) != NULL)
            {
                if (line[0] == '#' || line[0] == '\n')
                    continue;
                databaseSize++;
            }
            rewind(databaseFile);

            // Create and populate database array:
            database = (char **)malloc(databaseSize * sizeof(char *));

            size_t i = 0;
            while (fgets(line, sizeof(line), databaseFile) != NULL)
            {
                if (line[0] == '#' || line[0] == '\n')
                    continue;
		database[i] = (char *)malloc(MAX_PATH_LENGTH * sizeof(char));
		strcpy(database[i++], line);
            }
        }
    }
    fclose(databaseFile);

    printf("Extracting data...\n");
    // Parallely extract all data across all available CPU threads:
    #pragma omp parallel
    {
    //int tid = omp_get_thread_num();
    //printf("Thread %d started.\n", tid);

    // Each thread has an open copy of the ROM:
    FILE *romFile = fopen(romPath, "rb");
    if (!romFile)
    {
        fprintf(stderr, "Error opening ROM file.\n");
        exit(EXIT_FAILURE);
    }

    #pragma omp for
    for (size_t i = 0; i < databaseSize; ++i)
    {
        char **split;
        str_split(database[i], ';', &split);

        // Extract data:
        char *name = split[0];
        int length = atoi(split[1]);
        int size = atoi(split[3]);
        int address = strtol(split[2], NULL, 16);

        printf("Extracting %s\n", name);
        char filePath[MAX_PATH_LENGTH];
        snprintf(filePath, sizeof(filePath), "%s%s", dataPath, name);

	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split[3]);
	free(split);

	create_directories(filePath);
        char *data = (char *)malloc(length * size);
        if (!data)
        {
            fprintf(stderr, "Error allocating data buffer.\n");
            fclose(romFile);
            exit(EXIT_FAILURE);
        }

        FILE *outFile = fopen(filePath, "wb");
        if (!outFile)
        {
            fprintf(stderr, "Error opening output file %s.\n", filePath);
            fclose(romFile);
            exit(EXIT_FAILURE);
        }

        fseek(romFile, address, SEEK_SET);
        fread(data, size, length, romFile);
        fwrite(data, size, length, outFile);

        fclose(outFile);
        free(data);
    }
    fclose(romFile);
    }

    for (size_t i = 0; i < databaseSize; ++i)
        free(database[i]);
    free(database);

    return 0;
}
