/*
 * parse.c
 *
 *  Created on: Mar 22, 2019
 *      Author: root
 */
#include "token.h"
#include "parse.h"
#include "func.h"

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

#include "input_lib.h"

func* parseExpr()
{
	ind = 0;
	getToken();

	func* ret = parseAddn();
	getToken();

	if(curTok.type != TOK_END) {
		ret->type = TOK_OTHER;
	}

	return ret;
}

func* parseAddn()
{
	func* ret = 0;

	func* l = parseMuln();
	func* r = 0;
	if(curTok.type == TOK_PLUS || curTok.type == TOK_MINUS) {
		int opType = (curTok.type == TOK_PLUS)? FUNC_PLUS:FUNC_MINUS;
		getToken();
		r = parseAddn();
		ret = malloc(sizeof(func));
		ret->type = opType;
		ret->l = l;
		ret->r = r;
	}

	else {
		ret = l;
	}

	if(l->type == TOK_OTHER || (r && r->type == TOK_OTHER)) {
		ret->type = TOK_OTHER;
	}

	return ret;
}

func* parseMuln()
{
	func* ret = 0;
	func* l = parseExp();
	func* r = 0;
	if(curTok.type == TOK_MULT || curTok.type == TOK_DIV) {
		int opType = (curTok.type == TOK_MULT)? FUNC_MULT:FUNC_DIV;
		getToken();
		r = parseMuln();
		ret = malloc(sizeof(func));
		ret->type = opType;
		ret->l = l;
		ret->r = r;
	}

	else {
		ret = l;
	}

	if(l->type == TOK_OTHER || (r && r->type == TOK_OTHER)) {
		ret->type = TOK_OTHER;
	}

	return ret;
}

func* parseExp()
{
	func* ret = 0;
	func* l = parseTerm();
	func* r = 0;
	if(curTok.type == TOK_EXP) {
		getToken();
		r = parseTerm();
		ret = malloc(sizeof(func));
		ret->type = TOK_EXP;
		ret->l = l;
		ret->r = r;
	}

	else {
		ret = l;
	}

	if(l->type == TOK_OTHER || (r && r->type == TOK_OTHER)) {
		ret->type = TOK_OTHER;
	}

	return ret;
}

func* parseTerm()
{

	func *ret = malloc(sizeof(func)), *l = 0;
	ret->type = TOK_OTHER;
	if(curTok.type == TOK_COS || curTok.type == TOK_SIN || curTok.type == TOK_TAN) {
		int opType = 0;

		if(curTok.type == TOK_COS) {
			opType = FUNC_COS;
		} else if(curTok.type == TOK_SIN) {
			opType = FUNC_SIN;
		} else {
			opType = FUNC_TAN;
		}

		getToken();
		if(curTok.type != TOK_LPAREN) {
			printf("expected a (");
			return ret;
		}
		getToken();

		l = parseAddn();

		if(l->type == TOK_OTHER) {
			return ret;
		}

		if(curTok.type != TOK_RPAREN) {
			printf("expected a )\n");
			return ret;
		}

		ret->l = l;
		ret->type = opType;

		printf("TRIG\n");
	}

	else if(curTok.type == TOK_NUM) {
		ret->val = curTok.val;
		ret->type = FUNC_NUM;

		getToken();
	}

	else if(curTok.type == TOK_VAR) {
		ret->type = FUNC_VAR;
		getToken();
	}

	else if(curTok.type == TOK_LPAREN) {
		getToken();
		free(ret);
		ret = parseAddn();

		if(curTok.type != TOK_RPAREN) {
			ret->type = TOK_OTHER;
			return ret;
		}

		else {
			getToken();
		}
	}

	return ret;
}
