/*
 * main.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */
#include "input_lib.h"
#include "part103.h"

struct addrTest
{
	int a;
	int b;
};

void printAddr(struct addrTest a, struct addrTest b)
{
	printf("&a: %x, &a.a: %x, &a.b: %x, &b: %x, &b.a: %x, &b.b: %x\n", &a, &a.a, &a.b, &b, &b.a, &b.b);
}

int main()
{
	int choice = 0;
	srand(time(0));

	struct addrTest a, b;
	printAddr(a, b);

	while(choice != EXIT)
	{
		printMenu();

		if(getInt(&choice) == -1 || choice < 1 || choice > 5)
		{
			printf("Invalid selection\n");
		}

		else
		{
			switch(choice)
			{
			case DICE:
				dice();
				break;
			case CALC_CUBE:
				calcCube();
				break;
			case CALC_CIRCLE:
				calcCircle();
				break;
			case CUSTOM:
				plotFunction();
				break;
			}
		}
	}
}
