#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <stdio.h>

#include "races.h"
#include "runners.h"

#define RACEMGR_LIB_VERSION 3
#define OPS_RACES_FILE "Logs/races.txt"
#define OPS_RUNNERS_FILE "Logs/runners.txt"
#define OPS_TIMES_FILE "Logs/times.txt"

// Gets the library version
int ops_getVersion();

// Creates a new race and saves the information
raceError ops_createRace(tRace * race);

// Saves the races list into a file, so the information can be retrieved at any time
void ops_saveRacesInformation(tRace * firstRace);

// Appends the current race information into a races file.
void ops_saveRace(FILE * outputFile, tRace * race);

// Retrieves the information of the races previously stored on the file
void ops_loadRacesInformation(tRace * firstRace);

// Loads the information of an individual race
int ops_loadRace(FILE * inputFile, tRace * race);

// Appends a new register into the users' file whenever he subscribes into a race.
void ops_saveSubscription(tRace * race, tRunner * runner);

// Provides the list of runners that are currently registered to a race.
tRunner * ops_loadRunnersList(tRace * race);

// Checks if a runner is already registered to a race.
int ops_isRunnerInRace(tRace * race, char * dni);

// Provides the list of runners that has ran a race with their time
tRunner * ops_loadTimesList(tRace * race);

// Fills the time information into a runner struct.
void ops_getRunnerTime(tRace * race, tRunner * runner);

// Sorts the runners list by registered time. The runner that has ran the race in less time is first.
tRunner * ops_sortListByTime(tRunner * runnersList);

#endif