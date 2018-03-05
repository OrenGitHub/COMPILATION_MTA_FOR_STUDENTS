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
#include "FILE_02_Fraction.h"
#include "FILE_07_MatReader_AST.h"
#include "FILE_04_MatReader_ErrorMsg.h"

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
	MatReader_ErrorMsg_Error(MatReader_ErrorMsg_tokPos,"%s",s);
}

/************/
/* AST ROOT */
/************/
Matrix MatReader_AST_ROOT;

%}

/********************************************************************************/
/* This union is a C replacement for an abstract class representing an AST node */
/********************************************************************************/
%union
{
	union
	{
		int			ival;
		float		fval;
		string		sval;
		AST_Mat		Mat;
		AST_RowVec	RowVec;
		Fraction	Number;
	}
	gval;
}

/*************/
/* TERMINALS */
/*************/
%token <gval> INT
%token <gval> SEMICOLON
%token <gval> SEMICOLON
%token <gval> LBRACK
%token <gval> RBRACK
%token <gval> MINUS
%token <gval> DIVIDE

/*****************/
/* NON TERMINALS */
/*****************/
%type <gval> RowVec2
%type <gval> RowVec3
%type <gval> RowVec4
%type <gval> MatWith1Rows
%type <gval> MatWith2Rows
%type <gval> MatWith3Rows
%type <gval> Number
%type <gval> program

/**************/
/* START HERE */
/**************/
%start program

%%

program:		LBRACK MatWith1Rows RBRACK		{MatReader_AST_ROOT = $1.Mat;}
				| LBRACK MatWith2Rows RBRACK	{MatReader_AST_ROOT = $1.Mat;}
				| LBRACK MatWith3Rows RBRACK	{MatReader_AST_ROOT = $1.Mat;}

Number:			INT DIVIDE INT					{$$.Number = New_Fraction($1.ival,$3.ival);}
				| INT							{$$.Number = New_Fraction($1.ival,1);}

RowVec2:		Number Number					{$$.RowVec = AST_Alloc_RowVec2($1.Number,$2.Number);}
RowVec3:		Number Number Number			{$$.RowVec = AST_Alloc_RowVec3($1.Number,$2.Number,$3.Number);}
RowVec4:		Number Number Number Number		{$$.RowVec = AST_Alloc_RowVec4($1.Number,$2.Number,$3.Number,$4.Number);}

MatWith1Rows:	RowVec2		{$$.Mat = AST_Alloc_Mat1x2($1.RowVec);}
				| RowVec3	{$$.Mat = AST_Alloc_Mat1x3($1.RowVec);}
				| RowVec4	{$$.Mat = AST_Alloc_Mat1x4($1.RowVec);}

MatWith2Rows:	RowVec2	SEMICOLON RowVec2	{$$.Mat = AST_Alloc_Mat2x2($1.RowVec,$3.RowVec);}
				| RowVec3 SEMICOLON RowVec3	{$$.Mat = AST_Alloc_Mat2x3($1.RowVec,$3.RowVec);}
				| RowVec4 SEMICOLON RowVec4	{$$.Mat = AST_Alloc_Mat2x4($1.RowVec,$3.RowVec);}

MatWith3Rows:	RowVec2	SEMICOLON RowVec2 SEMICOLON RowVec2		{$$.Mat = AST_Alloc_Mat3x2($1.RowVec,$3.RowVec,$5.RowVec);}
				| RowVec3 SEMICOLON RowVec3 SEMICOLON RowVec3	{$$.Mat = AST_Alloc_Mat3x3($1.RowVec,$3.RowVec,$5.RowVec);}
				| RowVec4 SEMICOLON RowVec4 SEMICOLON RowVec4	{$$.Mat = AST_Alloc_Mat3x4($1.RowVec,$3.RowVec,$5.RowVec);}

%%

	
