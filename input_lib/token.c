/*
 * token.c
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */

#include "token.h"
#include "input_lib.h"
#include "func.h"

#include <string.h>

char tokBuf[200];
char numBuf[50];
int ind;
int tokBufLen;
token curTok;

token getToken()
{
	token ret;

	while(tokBuf[ind] == ' ' || tokBuf[ind] == '\n') {
		ind++;
	}

	if(ind >= tokBufLen) {
		ret.type = TOK_END;
		curTok = ret;
		return ret;
	}

	char curC = tokBuf[ind];
	if(cIsNum(curC))
	{
		int numInd = 0;
		while(cIsNum(curC) || curC == '.') {
			numBuf[numInd++] = tokBuf[ind++];
			curC = tokBuf[ind];
		}
		numBuf[numInd] = 0;
		ind--;

		if(strDecimal(numBuf)) {
			ret.type = TOK_NUM;
			ret.val = strtod(numBuf, 0);
		}
		else {
			ret.type = TOK_OTHER;
		}
	}

	// COS
	else if(!strncmp("cos", &tokBuf[ind], 3)) {
		ret.type = TOK_COS;
		ind += 2;
	}

	// SIN
	else if(!strncmp("sin", &tokBuf[ind], 3)) {
		ret.type = TOK_SIN;
		ind += 2;
	}

	// TAN
	else if(!strncmp("tan", &tokBuf[ind], 3)) {
		ret.type = TOK_TAN;
		ind += 2;
	}

	// MULT
	else if(curC == '*') {
		ret.type = TOK_MULT;
	}

	// DIV
	else if(curC == '/') {
		ret.type = TOK_DIV;
	}

	else if(curC == '+') {
		ret.type = TOK_PLUS;
	}

	else if(curC == '-') {
		ret.type = TOK_MINUS;
	}

	else if(curC == '(') {
		ret.type = TOK_LPAREN;
	}

	else if(curC == ')') {
		ret.type = TOK_RPAREN;
	}

	else if(curC == '^') {
		ret.type = TOK_EXP;
	}

	else if(curC == 'x') {
		ret.type = TOK_VAR;
	}

	else {
		ret.type = TOK_OTHER;
	}

	ind++;

	curTok = ret;

	return ret;
}
