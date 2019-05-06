/*
 * calcCube.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */
#include "part103.h"

void calcCube()
{
	double choice = 0;
	int quit = 0;
	char buf[50] = {0};

	double lengths[100] = {0};
	double volumes[100] = {0};
	char formatBuf[150] = {0};

	int count = 0;

	printf("Calculates the area of a cube\n");

	while(!quit) {
		printf("\nEnter the side length as a decimal. q to quit\n");

		getInput(buf, 50);

		if(strDecimal(buf)) {
			choice = strtod(buf, 0);

			if(choice <= 0) {
				printf("Side length must be greater than 0\n");
			} else {
				lengths[count] = choice;
				volumes[count] = choice * choice * choice;
				printf("Volume: %lf\n", volumes[count++]);
			}
		} else if(!strcmp(buf, "q\n")) {
			quit = 1;
		} else {
			printf("Invalid input\n");
		}
	}

	if(getSaveChoice()) {
		printf("Saved to %s\n", cubeOutFile);

		FILE* out = fopen(cubeOutFile, "w");

		if(out)
		{
			for(int i = 0; i < count; i++) {
				sprintf(formatBuf, "%02d - Side Length: %lf\t=\tVolume: %lf\n", i, lengths[i], volumes[i]);

				fwrite(formatBuf, strlen(formatBuf), 1, out);
			}

			fclose(out);
		}

		else
		{
			printf("Could not open out file\n Reason: %s", strerror(errno));
		}
	}
}
