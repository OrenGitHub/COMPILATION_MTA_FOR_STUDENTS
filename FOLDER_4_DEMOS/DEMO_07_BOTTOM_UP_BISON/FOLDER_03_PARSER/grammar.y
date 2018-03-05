%{
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"
#include "ErrorMsg.h"

/**********/
/* ALLOCA */
/**********/
#define alloca malloc

/*******************/
/* LEXING FUNCTION */
/*******************/
int aalex(void);

/******************/
/* ERROR FUNCTION */
/******************/
void aaerror(char *s)
{
	ErrorMsg_Error(ErrorMsg_tokPos,"%s",s);
}

/************/
/* AST ROOT */
/************/
int ROOT;

%}

/********************************************************************************/
/* This union is a C replacement for an abstract class representing an AST node */
/********************************************************************************/
%union
{
	union
	{
		int ival;
	}
	gval;
}

/*************/
/* TERMINALS */
/*************/
%token <gval> INT
%token <gval> PLUS
%token <gval> MINUS
%token <gval> TIMES
%token <gval> DIVIDE
%token <gval> LPAREN
%token <gval> RPAREN

/*****************/
/* NON TERMINALS */
/*****************/
%type <gval> program
%type <gval> E

/******************************/
/* ASSOCIATIVITY & PRECEDENCE */
/******************************/
%left MINUS,PLUS
%left TIMES,DIVIDE

/**************/
/* START HERE */
/**************/
%start program

%%

program:	E					{ROOT = $1.ival;}

E:			INT					{$$.ival = $1.ival          ;}
			| LPAREN E RPAREN	{$$.ival = $2.ival          ;}
			| E MINUS  E		{$$.ival = $1.ival - $3.ival;}
			| E PLUS   E		{$$.ival = $1.ival + $3.ival;}
			| E TIMES  E		{$$.ival = $1.ival * $3.ival;}
			| E DIVIDE E		{$$.ival = $1.ival / $3.ival;}

%%

