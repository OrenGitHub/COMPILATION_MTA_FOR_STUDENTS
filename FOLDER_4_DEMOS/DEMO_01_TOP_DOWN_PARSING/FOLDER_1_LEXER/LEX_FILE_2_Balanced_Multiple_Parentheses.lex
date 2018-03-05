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
LBRACK	"["
RBRACK	"]"
LBRACE	"{"
RBRACE	"}"
		
/*********/
/* RULES */
/*********/
%%
{WHITE_SPACE}		{adjust(); continue;}
{LINE_TERMINATOR}	{adjust(); ErrorMsg_Newline(); continue;}
{LPAREN}			{adjust(); ErrorMsg_Log("("); return LPAREN;}
{RPAREN}			{adjust(); ErrorMsg_Log(")"); return RPAREN;}
{LBRACK}			{adjust(); ErrorMsg_Log("["); return LBRACK;}
{RBRACK}			{adjust(); ErrorMsg_Log("]"); return RBRACK;}
{LBRACE}			{adjust(); ErrorMsg_Log("{"); return LBRACE;}
{RBRACE}			{adjust(); ErrorMsg_Log("}"); return RBRACE;}
.					{
						adjust();
						ErrorMsg_Error(
							ErrorMsg_tokPos,
							"\n\nERROR >> Unknown character(s): %s\n\n",
							aatext);
					}
