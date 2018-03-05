/***********************/
/* FILE NAME: driver.c */
/***********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"
#include "ErrorMsg.h"
#include "Tokens.h"

/*******************/
/* LEXING FUNCTION */
/*******************/
int aalex(void);

/*****************/
/* CURRENT TOKEN */
/*****************/
int tok=0;

/******************/
/* TOKEN PRINTING */
/******************/
string tokname(int tok)
{
	switch (tok) {
	case (INT):		return "INT";
	case (LPAREN):	return "LPAREN";
	case (RPAREN):	return "RPAREN";
	case (LBRACK):	return "LBRACK";
	case (RBRACK):	return "RBRACK";
	case (LBRACE):	return "LBRACE";
	case (RBRACE):	return "RBRACE";
	case (PLUS):	return "PLUS";
	case (MINUS):	return "MINUS";
	case (TIMES):	return "TIMES";
	case (DIVIDE):	return "DIVIDE";
	case (0):		return "END_OF_FILE";
	default:		return "BAD_TOKEN";
	}
}

/*******************************************/
/* THE HEART OF THE PREDICTIVE PARSER: Eat */
/*******************************************/
void Eat(int expectedToken)
{
	if (tok == expectedToken)
	{
		/*****************************************/
		/* Everything is OK, read the next token */
		/*****************************************/
		tok=aalex();
	}
	else
	{
		/******************************************/
		/* Error ... Print an appropriate message */
		/******************************************/
		ErrorMsg_Error(
			ErrorMsg_tokPos,
			"\n\nERROR >> Expected: %s, but received: %s\n\n",
			tokname(expectedToken),
			tokname(tok));
		/*******************************/
		/* Exit on the first error ... */
		/*******************************/
		exit(0);
	}
}

void E();
/*************************/
/* E = Simple Calculator */
/*************************/
void E_tag()
{
	switch (tok) {
	case (TIMES):
		// E' ---> * E E'
		Eat(TIMES);
		E();
		E_tag();
		break;

	case (DIVIDE):
		// E' ---> / E E'
		Eat(DIVIDE);
		E();
		E_tag();
		break;

	case (PLUS):
		// E' ---> + E E'
		Eat(PLUS);
		E();
		E_tag();
		break;

	case (MINUS):
		// E' ---> - E E'
		Eat(MINUS);
		E();
		E_tag();
		break;
	}
}

/*************************/
/* E = Simple Calculator */
/*************************/
void E()
{
	switch (tok) {

	case (LPAREN):
		
		// E ---> (E)E'
		Eat(LPAREN);
		E();
		Eat(RPAREN);
		E_tag();
		break;

	case (INT):
		
		// E ---> INT
		Eat(INT);
		E_tag();
		break;

	default:

		ErrorMsg_Error(
			ErrorMsg_tokPos,
			"Unexpected %s\n\n",
			tokname(tok));
		/*******************************/
		/* Exit on the first error ... */
		/*******************************/
		exit(0);
	}
}

/*************************************/
/* B = Balanced Multiple Parentheses */
/*************************************/
void B()
{
	switch (tok) {

	case (LPAREN):
		
		// B ---> (B)B
		Eat(LPAREN);
		B();
		Eat(RPAREN);
		B();
		break;

	case (LBRACK):
		
		// B ---> [B]B
		Eat(LBRACK);
		B();
		Eat(RBRACK);
		B();
		break;

	case (LBRACE):
		
		// B ---> {B}B
		Eat(LBRACE);
		B();
		Eat(RBRACE);
		B();
		break;
	}
}

/*****************************/
/* A = Balanced Parentheses */
/*****************************/
void A()
{
	switch (tok) {

	case (LPAREN):
		
		// A ---> (A)
		Eat(LPAREN);
		A();
		Eat(RPAREN);
		break;

	case (INT):

		// A ---> INT
		Eat(INT);
		break;
		
	default:

		ErrorMsg_Error(
			ErrorMsg_tokPos,
			"Unexpected %s\n\n",
			tokname(tok));
		/*******************************/
		/* Exit on the first error ... */
		/*******************************/
		exit(0);
	}
}

/*********/
/* USAGE */
/*********/
void usage(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr,"usage: a.out filename\n");
		return 0;
	}
}

void S1(){A();}
void S2(){B();}
void S3(){E();}

/*****************/
/* START OF CODE */
/*****************/
int main(int argc, char **argv)
{
	/********************************/
	/* [1] Input & Output filenames */
	/********************************/
	string Input_Filename =argv[1];
	string Output_Filename=argv[2];
		
	/*****************/
	/* [2] Usage ... */
	/*****************/
	usage(argc,argv);
	
	/***************************************************/
	/* [3] Set Lex Logs and open input file for lexing */
	/***************************************************/
	ErrorMsg_Set_Log_Filename(Output_Filename);	
	ErrorMsg_Reset(Input_Filename);

	/**************************/
	/* [4] Give me some space */
	/**************************/
	printf("\n\n");
	
	/************************/
	/* [5] Read first token */
	/************************/
	tok = aalex();
		
	/******************************************************/
	/* [6] Call the relevant grammar with S1, S2, S3 etc. */
	/******************************************************/
	// S1();
	// S2();
	S3();

	/******************************************************************/
	/* [7] If the program reaches this point then the input is legal! */
	/******************************************************************/
	printf(">> OK\n\n");

	/******************/
	/* [8] return ... */
	/******************/
	return 0;
}

