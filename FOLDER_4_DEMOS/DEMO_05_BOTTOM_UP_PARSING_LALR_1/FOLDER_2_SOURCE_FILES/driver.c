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
#include "Parser.h"
#include "ErrorMsg.h"

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

	printf("%s\n",Output_Filename);

	/**************************/
	/* [4] Give me some space */
	/**************************/
	printf("\n\n");

	/*****************/
	/* [5] Parse ... */
	/*****************/
	if (Parse()) {printf("\n\n>> OK   \n\n");}
	else         {printf("\n\n>> ERROR\n\n");}
	
	/******************/
	/* [6] return ... */
	/******************/	
	return 0;
}

