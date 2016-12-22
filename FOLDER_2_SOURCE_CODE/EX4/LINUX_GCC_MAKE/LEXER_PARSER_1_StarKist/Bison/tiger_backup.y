%{
#include <stdio.h>
#include <stdlib.h>
#include "../../../Compiler/HEADER_FILES/util.h"
#include "../../../Compiler/HEADER_FILES/errormsg.h"
#include "../../../Compiler/HEADER_FILES/symbol.h" 
#include "../../../Compiler/HEADER_FILES/absyn.h"

#define alloca malloc

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}


%union
{
	int			pos;
	int			ival;
	float		fval;
	string		sval;
	A_var		var;
	A_exp		exp;
	A_dec		dec;
	A_decList	decList;
	A_expList	expList;
	A_fieldList	fieldList;

	struct
	{
		union
		{
			int			ival;
			float		fval;
			string		sval;
			A_var		var;
			A_exp		exp;
			A_dec		dec;
			A_decList	decList;
			A_expList	expList;
			A_fieldList	fieldList;
		}
		gval;
	}
	xval;
}

%token <xval> INT
%token <xval> FLOAT
%token <xval> STRING
%token <xval> ID
%token <xval> COMMA
%token <xval> COLON
%token <xval> SEMICOLON
%token <xval> LPAREN
%token <xval> RPAREN
%token <xval> LBRACK
%token <xval> RBRACK
%token <xval> LBRACE
%token <xval> RBRACE
%token <xval> ARROW
%token <xval> PLUS
%token <xval> MINUS
%token <xval> TIMES
%token <xval> DIVIDE
%token <xval> EQ
%token <xval> NEQ
%token <xval> LT
%token <xval> LE
%token <xval> GT
%token <xval> GE
%token <xval> AND
%token <xval> OR
%token <xval> ASSIGN
%token <xval> ARRAY
%token <xval> IF
%token <xval> THEN
%token <xval> ELSE
%token <xval> WHILE
%token <xval> FOR
%token <xval> TO
%token <xval> DO
%token <xval> LET
%token <xval> IN
%token <xval> END
%token <xval> OF 
%token <xval> BREAK
%token <xval> NIL
%token <xval> FUNCTION
%token <xval> VAR
%token <xval> TYPE 

%type <xval> exp
%type <xval> OpExp
%type <xval> CallExp
%type <xval> IfThenExp
%type <xval> ForExp
%type <xval> ListExpComma
%type <xval> ListExpSemicolon
%type <xval> variable
%type <xval> AssignExp
%type <xval> SequenceExp
%type <xval> LetExp
%type <xval> TypeFields
%type <xval> TypeDeclaration
%type <xval> VariableDeclaration
%type <xval> FunctionDeclaration
%type <xval> AllocateArrayExp
%type <xval> AllocateRecordExp
%type <xval> declaration
%type <xval> declarations
%type <xval> program

%left DO
%left THEN
%left ASSIGN
%left OR AND
%left EQ NEQ LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE

%start program

%%

program:				exp											{absyn_root = $1.gval.exp;}

exp:					INT											{$$.gval.exp = A_IntExp(EM_tokPos,$1.gval.ival);}
						| FLOAT										{$$.gval.exp = A_FloatExp(EM_tokPos,$1.gval.fval);}
						| STRING									{$$.gval.exp = A_StringExp(EM_tokPos,$1.gval.sval);}
						| variable									{$$.gval.exp = A_VarExp(EM_tokPos,$1.gval.var);}
						| SequenceExp								{$$.gval.exp = $1.gval.exp;}
						| LPAREN exp RPAREN							{$$.gval.exp = $2.gval.exp;}
						| LetExp									{$$.gval.exp = $1.gval.exp;}
						| ForExp									{$$.gval.exp = $1.gval.exp;}
						| IfThenExp									{$$.gval.exp = $1.gval.exp;}
						| AssignExp									{$$.gval.exp = $1.gval.exp;}
						| OpExp										{$$.gval.exp = $1.gval.exp;}
						| CallExp									{$$.gval.exp = $1.gval.exp;}

OpExp:					exp		PLUS	exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_plusOp,   $1.gval.exp, $3.gval.exp);}
						| exp	MINUS	exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_minusOp,  $1.gval.exp, $3.gval.exp);}
						| exp	TIMES	exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_timesOp,  $1.gval.exp, $3.gval.exp);}
						| exp	DIVIDE	exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_divideOp, $1.gval.exp, $3.gval.exp);}
						| exp	EQ		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_eqOp,     $1.gval.exp, $3.gval.exp);}
						| exp	NEQ		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_neqOp,    $1.gval.exp, $3.gval.exp);}
						| exp	LT		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_ltOp,     $1.gval.exp, $3.gval.exp);}
						| exp	LE		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_leOp,     $1.gval.exp, $3.gval.exp);}
						| exp	GT		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_gtOp,     $1.gval.exp, $3.gval.exp);}
						| exp	GE		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_geOp,     $1.gval.exp, $3.gval.exp);}
						| exp	AND		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_andOp,    $1.gval.exp, $3.gval.exp);}
						| exp	OR		exp							{$$.gval.exp = A_OpExp(EM_tokPos, A_orOp,     $1.gval.exp, $3.gval.exp);}

IfThenExp:				IF exp THEN exp								{$$.gval.exp = A_IfExp(EM_tokPos,$2.gval.exp,$4.gval.exp,NULL);}

ForExp:					FOR ID ASSIGN exp TO exp DO exp				{$$.gval.exp = A_ForExp(EM_tokPos,S_Symbol($2.gval.sval),$4.gval.exp,$6.gval.exp,$8.gval.exp);}

ListExpSemicolon:		exp SEMICOLON ListExpSemicolon				{$$.gval.expList = A_ExpList($1.gval.exp,$3.gval.expList);}
						| exp SEMICOLON exp							{$$.gval.expList = A_ExpList($1.gval.exp,A_ExpList($3.gval.exp,NULL));}

ListExpComma:			exp COMMA ListExpComma						{$$.gval.expList = A_ExpList($1.gval.exp,$3.gval.expList);}
						| exp										{$$.gval.expList = A_ExpList($1.gval.exp,NULL);}

SequenceExp:			LPAREN ListExpSemicolon RPAREN				{$$.gval.exp = A_SeqExp(EM_tokPos,$2.gval.expList);}

TypeFields:				ID COLON ID COMMA TypeFields				{$$.gval.fieldList = A_FieldList(A_Field(EM_tokPos,S_Symbol($1.gval.sval),S_Symbol($3.gval.sval)),$5.gval.fieldList);}
						| ID COLON ID								{$$.gval.fieldList = A_FieldList(A_Field(EM_tokPos,S_Symbol($1.gval.sval),S_Symbol($3.gval.sval)),NULL);}

TypeDeclaration:		TYPE ID EQ ID								{$$.gval.dec = A_NameTypeDec(  EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($4.gval.sval));}
						| TYPE ID EQ ARRAY OF ID					{$$.gval.dec = A_ArrayTypeDec( EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($6.gval.sval));}
						| TYPE ID EQ LBRACE TypeFields RBRACE		{$$.gval.dec = A_RecordTypeDec(EM_tokPos,S_Symbol($2.gval.sval),$5.gval.fieldList);}

AllocateArrayExp:		ID LBRACK INT RBRACK OF NIL					{$$.gval.exp = A_AllocateArrayExp(EM_tokPos,S_Symbol($1.gval.sval),$3.gval.ival,0);}
						| ID LBRACK INT RBRACK OF INT				{$$.gval.exp = A_AllocateArrayExp(EM_tokPos,S_Symbol($1.gval.sval),$3.gval.ival,$6.gval.ival);}
						| ID LBRACK INT RBRACK OF FLOAT				{$$.gval.exp = A_AllocateArrayExp(EM_tokPos,S_Symbol($1.gval.sval),$3.gval.ival,2);}

AllocateRecordExp:		ID LBRACE ListExpComma RBRACE				{$$.gval.exp = A_AllocateRecordExp(EM_tokPos,S_Symbol($1.gval.sval),$3.gval.expList);}

VariableDeclaration:	VAR ID COLON ID								{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($4.gval.sval),NULL);}
						| VAR ID ASSIGN exp							{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),NULL,					$4.gval.exp);}
						| VAR ID ASSIGN AllocateArrayExp			{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),NULL,					$4.gval.exp);}
						| VAR ID ASSIGN AllocateRecordExp			{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),NULL,					$4.gval.exp);}
						| VAR ID COLON ID ASSIGN exp				{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($4.gval.sval),$6.gval.exp);}
						| VAR ID COLON ID ASSIGN AllocateArrayExp	{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($4.gval.sval),$6.gval.exp);}
						| VAR ID COLON ID ASSIGN AllocateRecordExp	{$$.gval.dec = A_VarDec(EM_tokPos,S_Symbol($2.gval.sval),S_Symbol($4.gval.sval),$6.gval.exp);}

FunctionDeclaration:	FUNCTION ID LPAREN RPAREN EQ exp						{$$.gval.dec = A_FunDec(EM_tokPos,S_Symbol($2.gval.sval),NULL,NULL,$6.gval.exp);}
						| FUNCTION ID LPAREN RPAREN COLON ID EQ exp				{$$.gval.dec = A_FunDec(EM_tokPos,S_Symbol($2.gval.sval),NULL,S_Symbol($6.gval.sval),$8.gval.exp);}
						| FUNCTION ID LPAREN TypeFields RPAREN EQ exp			{$$.gval.dec = A_FunDec(EM_tokPos,S_Symbol($2.gval.sval),$4.gval.fieldList,NULL,$7.gval.exp);}
						| FUNCTION ID LPAREN TypeFields RPAREN COLON ID EQ exp	{$$.gval.dec = A_FunDec(EM_tokPos,S_Symbol($2.gval.sval),$4.gval.fieldList,S_Symbol($7.gval.sval),$9.gval.exp);}

declaration:			TypeDeclaration											{$$.gval.dec = $1.gval.dec;}
						| VariableDeclaration									{$$.gval.dec = $1.gval.dec;}
						| FunctionDeclaration									{$$.gval.dec = $1.gval.dec;}

declarations:			declaration declarations								{$$.gval.decList = A_DecList($1.gval.dec,$2.gval.decList);}
						| declaration											{$$.gval.decList = A_DecList($1.gval.dec,NULL);}

LetExp:					LET declarations IN exp END								{$$.gval.exp = A_LetExp(EM_tokPos,$2.gval.decList,$4.gval.exp);}

variable:				ID														{$$.gval.var = A_SimpleVar(EM_tokPos,S_Symbol($1.gval.sval));}
						| variable ARROW ID										{$$.gval.var = A_FieldVar(EM_tokPos,$1.gval.var,S_Symbol($3.gval.sval));}
						| variable LBRACK exp RBRACK							{$$.gval.var = A_SubscriptVar(EM_tokPos,$1.gval.var,$3.gval.exp);}

AssignExp:				variable ASSIGN exp										{$$.gval.exp = A_AssignExp(EM_tokPos,$1.gval.var,$3.gval.exp);}
						| variable ASSIGN AllocateArrayExp						{$$.gval.exp = A_AssignExp(EM_tokPos,$1.gval.var,$3.gval.exp);}
						| variable ASSIGN AllocateRecordExp						{$$.gval.exp = A_AssignExp(EM_tokPos,$1.gval.var,$3.gval.exp);}

CallExp:				ID LPAREN RPAREN										{$$.gval.exp = A_CallExp(EM_tokPos,S_Symbol($1.gval.sval),NULL);}
						| ID LPAREN ListExpComma RPAREN							{$$.gval.exp = A_CallExp(EM_tokPos,S_Symbol($1.gval.sval),$3.gval.expList);}

%%

	
