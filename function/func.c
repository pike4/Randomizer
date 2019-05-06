/*
 * func.c
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */

#include "func.h"
#include <math.h>
#include <stdio.h>

// Allocate and return a new empty func object
func* newFunc(int _type, double _val)
{
	func* ret = malloc(sizeof(func));

	ret->type = _type;
	ret->val = _val;

	ret->l = 0;
	ret->r = 0;

	return ret;
}

// Free the given func and its descendants
void freeFunc(func* f)
{
	if(f->l) {
		freeFunc(f->l);
	}

	if(f->r) {
		freeFunc(f->r);
	}

	free(f);
}

// Resolve the value of the given function
double resolve(func* f, double x)
{
	double dividend = 0;

	switch(f->type)
	{
	case FUNC_PLUS:
		return resolve(f->l, x) + resolve(f->r, x);
	case FUNC_MINUS:
		return resolve(f->l, x) - resolve(f->r, x);
	case FUNC_MULT:
		return resolve(f->l, x) * resolve(f->r, x);
	case FUNC_DIV:
		dividend = resolve(f->r, x);
		if(dividend == 0) {
			return 0;
		}
		else {
			return resolve(f->l, x) / dividend;
		}
	case FUNC_EXP:
		return pow(resolve(f->l, x), resolve(f->r, x));
	case FUNC_VAR:
		return x;
	case FUNC_NUM:
		return f->val;
	case FUNC_COS:
		return cos(resolve(f->l, x));
	case FUNC_SIN:
		return sin(resolve(f->l, x));
	case FUNC_TAN:
		return tan(resolve(f->l, x));
	default:
		return 0;
	}
}
