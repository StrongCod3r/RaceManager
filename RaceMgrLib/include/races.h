#ifndef _RACES_H_
#define _RACES_H_

#define MAX_NAME_LENGTH 128
#define MAX_LOCATION_LENGTH 128
#define MAX_NUM_OF_RACES 128
#define MIN_RACE_DISTANCE 400
#define MAX_RACE_DISTANCE 100000
#define MIN_RACE_YEAR 2016
#define MAX_RACE_YEAR 2018
#define NUM_OF_PROVINCES 4

typedef enum
{
	RACE_NOERR,
	RACE_ALREADY_EXISTS,
	INVALID_NAME,
	INVALID_LOCATION,
	INVALID_PROVINCE,
	INVALID_DISTANCE,
	INVALID_DATETIME
} raceError;


typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
} tDateTime;

typedef struct sRace
{
	char name[MAX_NAME_LENGTH];
	char province[MAX_LOCATION_LENGTH];
	char location[MAX_LOCATION_LENGTH];
	int distance;
	tDateTime dateTime;
	struct sRace * nextRace;
} tRace;

tRace * races_firstRace;

// Gets the latest stored race.
tRace * races_getLastRace();

// Contains common functionality when initializing a new race struct
void races_initializeRaceStruct(tRace * race);

// Gets the race given its index in the list
tRace * races_getRace(int index);
 
// Creates a new race into the database
raceError races_addNewRace(tRace * race);

// Transforms the error value enumerate into a string
char * races_errMsg(raceError err);

// Verifies the name is valid
raceError races_checkName(char * name);

// Verifies the province is valid
raceError races_checkProvince(char * province);

// Verifies the location is valid
raceError races_checkLocation(char * location);

// Verifies the distance is valid
raceError races_checkDistance(int distance);

// Verifies the dateTime is valid
raceError races_checkDateTime(tDateTime dateTime);

#endif
