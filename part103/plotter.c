/*
 * plotter.c
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */
#include "part103.h"
#include "plotter.h"
#include <math.h>

#define MAX_STEPS 120
#define FUNCTION_RANGE 100

int graph[100][100];
double solutions[120];

int top = 101, bottom = 101;

void plotFunction()
{
	printf("Plot a function\n");
	printf("Enter the function to be plotted (Allowable symbols: "
			"+, -, *, /, x, ^, (, ), cos, sin, tan)\n");

	printf("y = ");
	func* me;
	getFunc(&me);

	if(me->type == 12) {
		printf("Invalid function\n");
	}

	else
	{
		for(int i = -50; i < 50; i++) {
			solutions[i + 50] = resolve(me, i);
		}

		printGraph();
	}

	freeFunc(me);
}

void populateGraph()
{
	top = 101;
	bottom = 101;

	for(int i = 49; i > -50; i--)
	{
		for(int j = -50; j < 50; j++)
		{
			int cur = round(solutions[j+50]);
			if(cur == i) {
				if(top == 101 || i > top) {
					top = i;
				}

				if(bottom == 101 || i < bottom) {
					bottom = i;
				}

				graph[i+50][j+50] = 1;
			}
			else {
				graph[i+50][j+50] = 0;
			}
		}
	}
}

void printGraph()
{
	populateGraph();

	int max = top + 3;
	int min = bottom - 3;

	if(max > 49) {
		max = 49;
	}

	if(min < -49) {
		min = -49;
	}

	for(int i = max; i > min; i--)
	{
		printLabel(i);

		for(int j = -50; j < 50; j++)
		{
			if(graph[i+50][j+50])
			{
				printf("X");
			}
			else if(i == 0)
			{
				printf("=");
			}
			else if(j == 0)
			{
				printf("|");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void printLabel(int y)
{
	printf("|");
	if(y % 5) {
		printf("      ");
	}

	else {
		printf("y=%03d ", y);
	}

	printf("|  ");
}
