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
LBRACE	"{"
RBRACE	"}"

/**********/
/* BINOPS */
/**********/
ASSIGN		"="
SEMICOLON	";"

/*******/
/* INT */
/*******/
DIGIT			[0-9]
NON_ZERO_DIGIT	[1-9]
INT				"0"|({NON_ZERO_DIGIT}({DIGIT}*))

/******/
/* ID */
/******/
LETTER			[a-zA-Z_]
ID				{LETTER}+
		
/*********/
/* RULES */
/*********/
%%
{WHITE_SPACE}		{adjust(); continue;}
{LINE_TERMINATOR}	{adjust(); ErrorMsg_Newline(); continue;}
{LBRACE}			{adjust(); ErrorMsg_Log("{"); return LBRACE;}
{RBRACE}			{adjust(); ErrorMsg_Log("}"); return RBRACE;}
{ASSIGN}			{adjust(); ErrorMsg_Log("="); return ASSIGN;}
{SEMICOLON}			{adjust(); ErrorMsg_Log(";"); return SEMICOLON;}
{ID}				{
						adjust();
						aalval.gval.sval=String(aatext);
						ErrorMsg_Log("ID(%s)",aalval.gval.sval);
						return ID;
					}
{INT}				{
						adjust();
						aalval.gval.ival=atoi(aatext);
						ErrorMsg_Log("INT(%d)",aalval.gval.ival);
						return INT;
					}

