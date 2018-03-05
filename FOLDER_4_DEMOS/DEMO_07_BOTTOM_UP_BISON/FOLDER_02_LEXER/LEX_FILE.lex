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
#include "util.h"
#include "ErrorMsg.h"
#include "Parser.h"

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
INT		"0"|[1-9][0-9]*
		
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
						ErrorMsg_Log(">> ERROR");
					}

