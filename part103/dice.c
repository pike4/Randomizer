/*
 * dice.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */

#include "part103.h"

void dice()
{
	int quit = 0, numDice = 0, numSides = 0, numRolls = 0;

	char buf[200];

	printf("Roll Some Dice\n");

	while(!quit)
	{
		printf("Enter the number of dice or q to quit\n");

		getInput(buf, 200);
		if(strInt(buf))
		{
			numDice = strtol(buf, NULL, 10);

			if(errno == ERANGE) {
				printf("Overflow occured\n");
				continue;
			}

			if(numDice < 1) {
				printf("Number of dice must be greater than 0\n");
				continue;
			}
		}
		else if(!strcmp(buf, "q\n")) {
			break;
		}
		else {
			printf("Invalid input\n");
			continue;
		}

		printf("Enter the number of sides for each die\n");
		if(getInt(&numSides)) {
			printf("Invalid input\n");
			continue;
		}

		if(numSides < 4) {
			printf("Impossible number of sides\n");
			continue;
		}

		printf("Enter the number of times each die will be rolled\n");
		if(getInt(&numRolls)) {
			printf("Invalid input\n");
			continue;
		}

		if(numRolls < 1) {
			printf("Dice must be rolled at least once\n");
			continue;
		}

		for(int i = 0; i < numDice; i++) {
			printf("Die %d\n", i);
			for(int j = 0; j < numRolls; j++) {
				int roll = (rand() % numSides) + 1;
				printf("\tRoll %d: %d\n", j, roll);
			}
			printf("\n");
		}
	}


}
