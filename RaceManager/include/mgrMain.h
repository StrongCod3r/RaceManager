#ifndef _MGRMAIN_H_
#define _MGRMAIN_H_

#include "races.h"

// Displays the Race Manager main menu
void mgrMain_displayMenu();

// Create a new race
void mgrMain_newRace();

// Display all the registered races
void mgrMain_listRaces();

// Display the list of runners that are already registered in the race.
void mgrMain_listRunners(tRace * race);

// Introduce the time for each runner to complete the race
void mgrMain_updateTimes(tRace * race);

#endif