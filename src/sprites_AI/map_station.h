#ifndef MAP_STATION_AI
#define MAP_STATION_AI

#define MAP_STATION_POSE_IDLE 0x9
#define MAP_STATION_POSE_DO_NOTHING 0xF
#define MAP_STATION_POSE_GRABBING_SAMUS 0x23
#define MAP_STATION_POSE_DOWNLOADING 0x25
#define MAP_STATION_POSE_DOWNLOADED 0x27
#define MAP_STATION_POSE_WAIT_FOR_MESSAGE 0x29
#define MAP_STATION_POSE_DELAY_BEFORE_RETRACTING 0x2B
#define MAP_STATION_POSE_RETRACTING 0x2D
#define MAP_STATION_POSE_RETRACTED 0x2F

// Map station part

#define MAP_STATION_PART_POSE_IDLE 0x9
#define MAP_STATION_PART_POSE_DOWNLOADING 0x23
#define MAP_STATION_PART_POSE_DOWNLOADED 0x25

#define MAP_STATION_PART_BACK_SCREEN 0x0
#define MAP_STATION_PART_FRONT_SCREEN 0x1

void MapStationInit(void);
void MapStationIdle(void);
void MapStationCheckSamusGrabbedAnimEnded(void);
void MapStationDownloading(void);
void MapStationSpawnMessage(void);
void MapStationWaitForMessage(void);
void MapStationDelayBeforeRetracting(void);
void MapStationRetracting(void);
void MapStation(void);
void MapStationPart(void);

#endif /* MAP_STATION_AI */