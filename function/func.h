/*
 * func.h
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */

#ifndef _FUNC_H_
#define _FUNC_H_

#include <math.h>
#include <stdlib.h>

#define FUNC_PLUS		0
#define FUNC_MINUS		1
#define FUNC_MULT		2
#define FUNC_DIV		3
#define FUNC_EXP		4
#define FUNC_VAR		5
#define FUNC_NUM		6
#define	FUNC_COS		7
#define FUNC_SIN		8
#define FUNC_TAN		9
#define FUNC_LPAREN		10
#define FUNC_RPAREN		11
#define FUNC_OTHER		12


typedef struct _func
{
	int type;
	double val;

	struct _func* l;
	struct _func* r;
} func;

func* newFunc(int _type, double _val);

void freeFunc(func* f);

double resolve(func* f, double x);

#endif
