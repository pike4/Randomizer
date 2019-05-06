/*
 * printMenu.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */

#include "part103.h"

char* menuOptions[] = {"Roll Dice", "Compute the area of a circle",
		"Compute the volume of a cube", "Graphing Calculator", "Exit" };

void printMenu()
{
	printf("\n\n");

	printf("Select an option:\n\n");
	for(int i = 0; i < NUM_OPTIONS; i++)
	{
		printf("%d - %s\n", i+1, menuOptions[i]);
	}
	printf("\n");
}
