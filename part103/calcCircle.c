/*
 * calcCircle.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */

#include "part103.h"

char buf[100];
char formatBuf[150];

double radii[50];
double areas[50];

int count;

void calcCircle()
{
	int quit = 0;
	count = 0;

	printf("Calculate the area of a circle\n");

	while(!quit)
	{
		printf("Enter the radius of the circle or q to quit\n");

		getInput(buf, 100);

		if(strDecimal(buf))
		{

			double radius = strtod(buf, 0);
			if(radius < 0) {
				printf("Radius cannot be negative\n");
			}

			else {
				double area = radius * radius * 3.14159265359;
				radii[count] = radius;
				areas[count++] = area;

				printf("\t Area: %lf\n", area);
			}
		}

		else if(!strncmp(buf, "q\n", 2))
		{
			quit = 1;
		}

		else
		{
			printf("Invalid input\n");
		}

		count =  count % 50;
		printf("\n");
	}

	if(getSaveChoice()) {
		printf("Saved results to %s\n", circleOutFile);

		FILE* out = fopen(circleOutFile, "w");

		if(out)
		{
			for(int i = 0; i < count; i++) {
				sprintf(formatBuf, "%02d - Radius: %lf\t-\tArea: %lf\n", i, radii[i], areas[i]);

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
