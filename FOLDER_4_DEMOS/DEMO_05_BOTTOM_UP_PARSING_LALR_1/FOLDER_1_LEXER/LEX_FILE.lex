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
SMALLa	"a"
SMALLb	"b"
SMALLx	"x"
		
/*********/
/* RULES */
/*********/
%%
{WHITE_SPACE}		{adjust(); continue;}
{LINE_TERMINATOR}	{adjust(); ErrorMsg_Newline(); continue;}
{SMALLa}			{adjust(); ErrorMsg_Log("a"); return SMALLa;}
{SMALLb}			{adjust(); ErrorMsg_Log("b"); return SMALLb;}
{SMALLx}			{adjust(); ErrorMsg_Log("x"); return SMALLx;}
.					{
						adjust();
						ErrorMsg_Error(
							ErrorMsg_tokPos,
							"\n\nERROR >> Unknown character(s): %s\n\n",
							aatext);
					}
