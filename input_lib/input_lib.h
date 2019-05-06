/*
 * input_lib.h
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */

#ifndef INPUT_LIB_H_
#define INPUT_LIB_H_

#include <stdio.h>
#include "func.h"

int strDecimal(char* str);
int strInt(char* str);
void getInput(char* buf, int size);
int getInt(int *ret);
int getDouble(double* ret);
int getFunc(func** f);

void flushStdIn();

int getSaveChoice();

#define cIsNum(X) ((X >= '0') && (X <= '9'))

#endif /* INPUT_LIB_H_ */
