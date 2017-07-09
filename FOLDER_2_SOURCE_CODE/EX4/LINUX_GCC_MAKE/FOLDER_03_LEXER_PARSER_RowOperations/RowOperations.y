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
#include "FILE_01_util.h"
#include "FILE_09_RowOperations_ErrorMsg.h"
#include "FILE_12_RowOperations_AST.h"

/**********/
/* ALLOCA */
/**********/
#define alloca malloc

/*******************/
/* LEXING FUNCTION */
/*******************/
int bblex(void);

/******************/
/* ERROR FUNCTION */
/******************/
void bberror(char *s)
{
	RowOperations_ErrorMsg_Error(RowOperations_ErrorMsg_tokPos,"%s",s);
}

/************/
/* AST ROOT */
/************/
AST_RowOpList RowOperations_AST_ROOT;

%}

/********************************************************************************/
/* This union is a C replacement for an abstract class representing an AST node */
/********************************************************************************/
%union
{
	union
	{
		int							row;
		int							op;
		int							ival;
		float						fval;
		string						sval;
		Fraction					Number;
		AST_RowOp					RowOp;
		AST_RowOpList				RowOpList;
		AST_Ri_Swap_Rj				Ri_Swap_Rj;
		AST_Ri_Equals_cRi			Ri_Equals_cRi;
		AST_Ri_Equals_Ri_Plus_cRj	Ri_Equals_Ri_Plus_cRj;
	}
	gval;
}

/*************/
/* TERMINALS */
/*************/
%token <gval> INT
%token <gval> FLOAT
%token <gval> STRING
%token <gval> LPAREN
%token <gval> RPAREN
%token <gval> LBRACK
%token <gval> RBRACK
%token <gval> L_ARROW
%token <gval> PLUS
%token <gval> MINUS
%token <gval> TIMES
%token <gval> DIVIDE
%token <gval> LR_ARROW
%token <gval> ROW

/*****************/
/* NON TERMINALS */
/*****************/
%type <gval> op
%type <gval> RowOp
%type <gval> Number
%type <gval> program
%type <gval> RowOpList

/***************/
/*  START HERE */
/***************/
%start program

%%

program:	RowOpList						{RowOperations_AST_ROOT = $1.RowOpList;}

RowOpList:	RowOp RowOpList					{$$.RowOpList = AST_Alloc_RowOpList($1.RowOp,$2.RowOpList);}
			| RowOp							{$$.RowOpList = AST_Alloc_RowOpList($1.RowOp,NULL);}			

Number:		INT DIVIDE INT					{$$.Number = New_Fraction($1.ival,$3.ival);}
			| INT							{$$.Number = New_Fraction($1.ival,1);}

op:			PLUS							{$$.op =  1;}
			| MINUS							{$$.op = -1;}

RowOp:		ROW LR_ARROW ROW 				{$$.RowOp = AST_Alloc_Ri_Swap_Rj($1.row,$3.row);}
			| ROW L_ARROW ROW op Number ROW	{$$.RowOp = AST_Alloc_Ri_Equals_Ri_Plus_cRj($1.row,$4.op,$5.Number,$6.row);}
			| ROW L_ARROW ROW op ROW		{$$.RowOp = AST_Alloc_Ri_Equals_Ri_Plus_cRj($1.row,$4.op,AST_Alloc_Number(1,1),$5.row);}
			| ROW L_ARROW Number ROW		{$$.RowOp = AST_Alloc_Ri_equals_cRi($1.row,$3.Number);}
%%

	
