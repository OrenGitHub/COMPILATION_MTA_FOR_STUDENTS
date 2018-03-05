/***********************/
/* FILE NAME: Parser.c */
/***********************/

/*****************/
/* INCLUDE FILES */
/*****************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "util.h"
#include "Stack.h"
#include "Parser.h"
#include "ErrorMsg.h"
#include "Tokens.h"

/********************/
/* GLOBAL VARIABLES */
/********************/
Stack s;
int tok=0;
int status=1;
int readToken=1;
string entry=NULL;

/********************/
/* GLOBAL VARIABLES */
/********************/
YYSTYPE aalval;

/****************************/
/* EXTERNAL LEXING FUNCTION */
/****************************/
int aalex(void);

#define NUM_DERIVIATION_RULES 5
char *RULES[NUM_DERIVIATION_RULES]=
{
	"S->E$",
	"E->{L}",
	"E->x=i",
	"L->L;E",
	"L->E"
};

char LEFT_SIDE_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	'S',
	'E',
	'E',
	'L',
	'L'
};

int LENGTH_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	2,/* S->E$  */
	3,/* E->{L} */
	3,/* E->x=i */
	3,/* L->L;E */
	1 /* L->E   */
};

int ConvertTokenToIndex(int token)
{
	switch (token) {
	case (LBRACE):    return 0;
	case (RBRACE):    return 1;
	case (ID):        return 2;
	case (INT):       return 3;
	case (ASSIGN):    return 4;
	case (SEMICOLON): return 5;
	case (0):         return 6;
	default:          return -1;
	}
}

char ConvertTokenToChar(int token)
{
	switch (token) {
	case (LBRACE):    return '{';
	case (RBRACE):    return '}';
	case (ID):        return 'x';
	case (INT):       return 'i';
	case (ASSIGN):    return '=';
	case (SEMICOLON): return '-';
	case (0):         return '$';
	default:          return  0 ;
	}
}

int ConvertCharToIndex(char c)
{
	switch (c) {
	case ('{'): return  0;
	case ('}'): return  1;
	case ('x'): return  2;
	case ('i'): return  3;
	case ('='): return  4;
	case ('-'): return  5;
	case ('$'): return  6;
	case ('E'): return  7;
	case ('L'): return  8;
	default:    return -1;
	}
}

void Shift(void)
{
	int state=0;

	/**********************/
	/* Compute Next State */
	/**********************/
	state=atoi(entry+1);

	/********/
	/* Push */
	/********/
	Push(&s,state,ConvertTokenToChar(tok));
	
	/*******************/
	/* Read next token */
	/*******************/
	tok=aalex();
	
	/*******************/
	/* print the stack */
	/*******************/
	PrintStack(&s);
}

void Reduce(int rule_number)
{
	int i=0;
	int state=0;

	/**********************************************************/
	/* Pop the stack the length of the right side of the rule */
	/**********************************************************/
	for (i=0;i<LENGTH_DERIVIATION_RULES[rule_number];i++)
	{
		Pop(&s);
	}

	/**********************/
	/* Compute Next State */
	/**********************/
	entry=table[Top(&s)->state][ConvertCharToIndex(LEFT_SIDE_DERIVIATION_RULES[rule_number])];

	/******************************************/
	/* Only goto states are possible here ... */
	/******************************************/
	assert((*entry) == 'g');
	state=atoi(entry+1);

	/************************************/
	/* Push left side variable on stack */
	/************************************/
	Push(&s,state,LEFT_SIDE_DERIVIATION_RULES[rule_number]);

	/*******************/
	/* print the stack */
	/*******************/
	PrintStack(&s);
}

int Parse()
{
	/**************/
	/* Init Stack */
	/**************/
	s.c=0;
	s.state=0;
	s.next=NULL;

	/*******************/
	/* print the stack */
	/*******************/
	PrintStack(&s);

	/***********************/
	/* Get the first token */
	/***********************/
	tok=aalex();
	
	while (1) {

		/***********************/
		/* extract table entry */
		/***********************/
		entry=table[Top(&s)->state][ConvertTokenToIndex(tok)];

		switch (*entry) {
		
		case ('s'):

			// Shift
			Shift();
			break;

		case ('r'):

			// Reduce
			Reduce(atoi(entry+1));
			break;

		case ('a'):
			
			// Accept
			return 1;

		case (0):

			// Error
			return 0;
		}
	}

	return 0;
}
