/*
 * part103.h
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */

#ifndef PART103_H_
#define PART103_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>

#include "input_lib.h"
#include "func.h"

#define NUM_OPTIONS 5

#define DICE		1
#define CALC_CIRCLE	2
#define CALC_CUBE	3
#define CUSTOM		4
#define	EXIT		5

extern const char* circleOutFile;
extern const char* cubeOutFile;

void printMenu();
void calcCircle();
void calcCube();
void dice();
void plotFunction();

#endif /* PART103_H_ */
