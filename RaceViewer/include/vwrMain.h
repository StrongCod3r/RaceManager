#ifndef _VWRMAIN_H_
#define _VWRMAIN_H_

#include "races.h"

// Displays the Race Viewer main menu
void vwrMain_displayMenu();

// Display all the registered races
void vwrMain_listRaces();

// Display extended information of the race.
void vwrMain_showInfo(tRace * race);

// Subscribe to the race
void vwrMain_subscribe(tRace * race);

// Display the list of runners that are already registered in the race.
void vwrMain_listRunners(tRace * race);

// Display the times sorted from minimum to maximum for every runner that has ran the race.
void vwrMain_listTimes(tRace * race);

#endif