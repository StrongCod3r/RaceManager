#ifndef _VWR_MENU_H_
#define _VWR_MENU_H_

#include "races.h"
#include "runners.h"

// Displays the Race Viewer main menu with the available operations
char vwrMenu_mainMenu();

// Displays a list with all the races registered in the database.
int vwrMenu_listAll();

// It displays the current race information.
char vwrMenu_information(tRace * race);

// Sub-method to display the current race information.
void vwrMenu_raceInformation(tRace * race);

// Requests the user parameters in order to subscribe to a race
tRunner * vwrMenu_subscribe();

// Displays the list of races a user has registered to.
int vwrMenu_filterRaces();

#endif