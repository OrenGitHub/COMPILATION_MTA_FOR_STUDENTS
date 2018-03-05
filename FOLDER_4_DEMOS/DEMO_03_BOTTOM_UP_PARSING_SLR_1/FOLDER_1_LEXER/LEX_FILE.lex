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
/* PROVIDE aawrap */
/******************/
int aawrap(void)
{
	charPos=1;
	return 1;
}

/**************************/
/* CONTROL ERROR MESSAGES */
/**************************/
void adjust(void)
{
	ErrorMsg_tokPos = charPos;
	charPos += aaleng;
}

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

/**********/
/* BINOPS */
/**********/
PLUS	"+"
MINUS	"-"
TIMES	"*"
DIVIDE	"/"

/*******/
/* INT */
/*******/
DIGIT			[0-9]
NON_ZERO_DIGIT	[1-9]
LETTER			[a-zA-Z_]
INT				"0"|({NON_ZERO_DIGIT}({DIGIT}*))
		
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
						ErrorMsg_Log("INT(%d)",aalval.gval.ival);
						return INT;
					}

