/*
 * input_lib.c
 *
 *  Created on: Mar 21, 2019
 *      Author: root
 */
#include "input_lib.h"
#include "func.h"
#include "token.h"
#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// A line from stdin to the buffer indicated by buf. Maximum of (size-1) characters
void getInput(char* buf, int size)
{
	int charsRead = 0;
	int curChar = 0;

	while (1)
	{
		curChar = getchar();
		charsRead++;

		if (charsRead > size)
		{
			ungetc(curChar, stdin);
			break;
		}

		if (curChar == EOF || curChar == 0)
		{
			break;
		}

		*buf = curChar;
		buf++;

		if (curChar == '\n')
		{
			break;
		}
	}

	*buf = 0;

	flushStdIn();
}

// Get an int from stdin, returns 0 if valid, -1 otherwise
int getInt(int *ret)
{
	char inBuf[100];

	fgets(inBuf, 100, stdin);
	flushStdIn();

	if(strInt(inBuf)) {
		int tmp = strtol(inBuf, 0, 10);

		*ret = tmp;
		return 0;
	}

	else {
		return -1;
	}
}

// Get a double from stdin, returns 0 if valid, -1 otherwise
int getDouble(double *ret)
{
	char inBuf[100];

	fgets(inBuf, 100, stdin);
	flushStdIn();

	if(strDecimal(inBuf)) {
		int tmp = strtod(inBuf, 0);

		*ret = tmp;
		return 0;
	}

	else {
		return -1;
	}
}

// Return 1 if string is properly formatted decimal number, 0 otherwise
int strDecimal(char* str)
{
	int dot = 0, ind = 0;

	if(!str) {
		return 0;
	}

	while(str[ind] != 0) {
		if(ind != 0 && str[ind] == '-') {
			return 0;
		}
		else if(str[ind] == '\n' || str[ind] == ' ') {
			break;
		}
		else if(str[ind] == '.') {
			// Return False if string starts with dot,
			// or if there is more than one dot in string
			if(ind == 0 || dot == 1) {
				return 0;
			} else {
				dot = 1;
			}
		}

		else if(!cIsNum(str[ind]) && str[ind] != '-') {
			return 0;
		}

		++ind;
	}

	// Return false if empty string or number ends with a decimal point
	if(ind == 0 || str[ind-1] == '.') {
		return 0;
	} else {
		return 1;
	}
}

// Return 1 if string is properly formatted integer, 0 otherwise
int strInt(char* str)
{
	int ind = 0;

	if(!str) {
		return 0;
	}

	while(str[ind] != 0) {
		if(ind != 0 && str[ind] == '-') {
			return 0;
		}
		else if(str[ind] == '\n' || str[ind] == ' ') {
			break;
		}
		else if(!cIsNum(str[ind]) && str[ind] != '-') {
			return 0;
		}

		++ind;
	}

	if(ind == 0) {
		return 0;
	} else {
		return 1;
	}
}

// Flush standard input
void flushStdIn()
{
	int flags = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, O_NONBLOCK);

	while(getchar() != EOF) {}

	fcntl(0, F_SETFL, flags);
}

char cur = 0;
int ind = 0;
int status = 0;

// Parse a function to be stored in the given pointer.
int getFunc(func** f)
{
	getInput(tokBuf, 200);
	tokBufLen = strlen(tokBuf);

	*f = parseExpr();

	return (*f)->type == 12;
}

int getSaveChoice()
{
	char buf[5];
	int ret = 0;

	while(1)
	{
		printf("Save results to disk? [yn] ");
		getInput(buf, 5);

		if(!strncmp("y\n", buf, 2)) {
			ret = 1;
			break;
		} else if(!strncmp("n\n", buf, 2)) {
			ret = 0;
			break;
		} else {
			printf("Invalid input\n");
		}
	}

	return ret;
}
