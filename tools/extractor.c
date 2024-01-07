#define _XOPEN_SOURCE 500 // Needed to use nftw(). No alternative found.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <ftw.h>
#include <unistd.h>
#include <omp.h>

#define MAX_PATH_LENGTH 128

const char *romPath = "mzm_us_baserom.gba";
const char *databasePath = "database.txt";
const char *dataPath = "data/";

/*
 * Custom implementation of atoi() for decimal numbers, since atoi() seems to
 * segfault on some systems for some reason.
 *
 * This function converts a string into the 32-bit integer number it represents.
 *
 * This function is not general, and makes some assumptions about its input
 * string that are true for this particular case:
 *  - it assumes it represents a decimal number
 *  - it assumes the represented number fits in the 32-bit range
 *  - it assumes the string only contains valid numeric characters, and ends
 *    with a null terminator. It assumes it does not contain newline characters.
 */
int stoi_dec(const char *s)
{
	int n = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		n *= 10;
		n += s[i] - '0';
	}

	return n;
}

/*
 * Custom implementation of atoi() for hexadecimal numbers, since atoi() seems
 * to segfault on some systems for some reason.
 *
 * This function converts a string into the 32-bit integer number it represents.
 *
 * This function is not general, and makes some assumptions about its input
 * string that are true for this particular case:
 *  - it assumes it represents a hexadecimal number
 *  - it assumes the string starts with "0x"
 *  - it assumes the represented number fits in the 32-bit range
 *  - it assumes the string only contains valid hex characters, and ends
 *    with a null terminator. It assumes it does not contain newline characters.
 */
int stoi_hex(const char *s)
{
	int n = 0;
	for (int i = 2; s[i] != '\0'; ++i)
	{
		n *= 16;
		int digit = s[i] - '0';
		if (digit > 9) digit += -('a' - '0') + 10;
		n += digit;
	}

	return n;
}

/*
 * Creates the entire directory hierarchy for the given file path, if it does
 * not exist yet.
 */
void create_directories(const char *filePath)
{
	// NOTE: filePath contains the full path of a given extracted data asset.
	// This function creates its full directory hierarchy.
	const char *lastSlash = strrchr(filePath, '/');
	size_t dirPathLen = lastSlash - filePath + 1;

	char *dirPath = (char *)malloc((dirPathLen + 1) * sizeof(char));
	if (dirPath == NULL)
	{
		fprintf(stderr, "Memory allocation error for path %s.\n", filePath);
		exit(EXIT_FAILURE);
	}

	// Retrieve the directory path from the complete file path:
	strncpy(dirPath, filePath, dirPathLen);
	dirPath[dirPathLen] = '\0';

	// Create directory hierarchy:
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

/*
 * Function passed to nftw() to recursively remove all files and directories
 * under a given path.
 * It basically does the "removing" part of "rm -rf".
 * fpath is a specific file or empty directory. It cannot be a non-empty
 * directory (i.e. does not work recursively). nftw() passes the files and
 * directories in the correct order so that a path (parent of fpath) is
 * recursively removed.
 * All the other arguments (sb, typeflag, ftwbuf) are needed as specified by
 * nftw(), but are unused in this function.
 */
int remove_file_or_directory(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
	int rv = remove(fpath);

	if (rv)
	{
		// If an error is found, print to stderr with errno value:
		perror(fpath);
		exit(EXIT_FAILURE);
	}

	return rv;
}

/* 
 * Splits a string (s) by a given delimiter (del) into a preallocated
 * buffer (result), without allocating new memory. result should be properly
 * allocated to store all of the substrings.
 * s is edited as a byproduct of calling this function. None of the elements
 * stored in result should be freed, only s.
 */
void str_split(char *s, char del, char **result)
{
	size_t idx = 0;
	char *start = s;
	char *p = s;
	while (*p != '\0')
	{
		if (*p == del)
		{
			*p = '\0'; // Change delimiter to NULL terminator in-place.
			result[idx] = start;
			idx++;
			start = p + 1;
		}
		p++;
	}
	// Last substring:
	result[idx] = start;
}

int main(void)
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
	char *database;
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
				// Basically a "rm -rf dataPath":
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
			database = (char *)malloc(databaseSize * MAX_PATH_LENGTH * sizeof(char));
			if (database == NULL)
			{
				fprintf(stderr, "Error allocating buffer for the database\n.");
				exit(EXIT_FAILURE);
			}

			size_t i = 0;
			while (fgets(line, sizeof(line), databaseFile) != NULL)
			{
				if (line[0] == '#' || line[0] == '\n')
					continue;
				strcpy(&database[i++ * MAX_PATH_LENGTH], line);
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
			char *split[4];
			str_split(&database[i * MAX_PATH_LENGTH], ';', split);

			// Extract data:
			char *name = split[0];
			int length = stoi_dec(split[1]);
			int size = split[3][0] - '0';
			int address = stoi_hex(split[2]);

			printf("Extracting %s\n", name);
			char filePath[MAX_PATH_LENGTH];
			snprintf(filePath, sizeof(filePath), "%s%s", dataPath, name);

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
	free(database);

	return 0;
}
