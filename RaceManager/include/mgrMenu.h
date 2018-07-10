#ifndef _MGR_MENU_H_
#define _MGR_MENU_H_

#include "races.h"

// Displays the Race Manager main menu with the available operations
char mgrMenu_mainMenu();

// Requests the parameters to add a new race
tRace * mgrMenu_newRace();

// Displays a list with all the races registered in the database.
int mgrMenu_listAll();

// It displays the current race information.
int mgrMenu_information(tRace * race);

#endif