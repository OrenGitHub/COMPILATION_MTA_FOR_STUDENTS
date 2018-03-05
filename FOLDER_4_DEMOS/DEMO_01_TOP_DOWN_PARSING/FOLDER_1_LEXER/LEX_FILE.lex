%{
/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "ErrorMsg.h"
#include "Tokens.h"
#include "util.h"

/**************************/
/* CONTROL ERROR MESSAGES */
/**************************/
static int charPos=1;

/******************/
/* PROVIDE aaWRAP */
/******************/
int aawrap(void)
{
	charPos=1;
	return 1;
}

/**************************/
/* CONTROL ERROR MESSAGES */
/**************************/
static void adjust(void)
{
	ErrorMsg_tokPos = charPos;
	charPos += aaleng;
}

/***********/
/* YYSTYPE */
/***********/
YYSTYPE aalval;

%}

/*****************/
/* UNIQUE PREFIX */
/*****************/
%option prefix="aa"

/********************/
/* COMMON REGEXP(s) */
/********************/

/**********/
/* SPACES */
/**********/
WHITE_SPACE		" "|\t
LINE_TERMINATOR	\n

/***************/
/* PARENTHESES */
/***************/
LPAREN	"("
RPAREN	")"

/********************/
/* BINARY OPERATORS */
/********************/
PLUS	"+"
MINUS	"-"
TIMES	"*"
DIVIDE	"/"

/*******/
/* INT */
/*******/
INT	[0-9]+
		
/*********/
/* RULES */
/*********/
%%
{WHITE_SPACE}		{adjust(); continue;}
{LINE_TERMINATOR}	{adjust(); ErrorMsg_Newline(); continue;}
{LPAREN}			{adjust(); ErrorMsg_Log("("); return LPAREN;}
{RPAREN}			{adjust(); ErrorMsg_Log(")"); return RPAREN;}
{PLUS}				{adjust(); ErrorMsg_Log("+"); return PLUS;}
{MINUS}				{adjust(); ErrorMsg_Log("-"); return MINUS;}
{TIMES}				{adjust(); ErrorMsg_Log("*"); return TIMES;}
{DIVIDE}			{adjust(); ErrorMsg_Log("/"); return DIVIDE;}
{INT}				{
						adjust();
						aalval.gval.ival=atoi(aatext);
						ErrorMsg_Log("INT(%d) ",aalval.gval.ival);
						return INT;
					}
.					{
						adjust();
						ErrorMsg_Error(
							ErrorMsg_tokPos,
							"\n\nERROR >> Unknown character(s): %s\n\n",
							aatext);
					}
