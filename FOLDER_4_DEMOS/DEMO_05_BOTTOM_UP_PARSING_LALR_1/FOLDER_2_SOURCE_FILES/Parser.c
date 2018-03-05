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

#define NUM_DERIVIATION_RULES 6
char *RULES[NUM_DERIVIATION_RULES]=
{
	"S->E$",
	"E->A",
	"E->xb",
	"A->aAb",
	"A->B",
	"B->x"
};

char LEFT_SIDE_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	'S',
	'E',
	'E',
	'A',
	'A',
	'B'
};

int LENGTH_DERIVIATION_RULES[NUM_DERIVIATION_RULES]=
{
	2,/* S->E$, */
	1,/* E->A   */
	2,/* E->xb  */
	3,/* A->aAb */
	1,/* A->B   */
	1 /* B->x   */
};

int ConvertTokenToIndex(int token)
{
	switch (token) {
	case (SMALLa): return 0;
	case (SMALLb): return 1;
	case (SMALLx): return 2;
	case (0):      return 3;
	default:       return -1;
	}
}

int ConvertCharToIndex(char c)
{
	switch (c) {
	case ('a'): return  0;
	case ('b'): return  1;
	case ('x'): return  2;
	case ('$'): return  3;
	case ('E'): return  4;
	case ('A'): return  5;
	case ('B'): return  6;
	default:    return -1;
	}
}

char ConvertTokenToChar(int token)
{
	switch (token) {
	case (SMALLa): return 'a';
	case (SMALLb): return 'b';
	case (SMALLx): return 'x';
	case (0):      return '$';
	default:       return  0 ;
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
