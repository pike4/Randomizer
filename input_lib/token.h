/*
 * token.h
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "func.h"
#include <stdio.h>

extern char tokBuf[200];
extern int ind;
extern int tokBufLen;

#define TOK_PLUS	0
#define TOK_MINUS	1
#define TOK_MULT	2
#define TOK_DIV		3
#define TOK_EXP		4
#define TOK_VAR		5
#define TOK_NUM		6
#define	TOK_COS		7
#define TOK_SIN		8
#define TOK_TAN		9
#define TOK_LPAREN	10
#define TOK_RPAREN	11
#define TOK_OTHER	12
#define TOK_END		13

typedef struct _token
{
	double val;
	int type;
}token;

extern token curTok;

token getToken();

#endif /* TOKEN_H_ */
