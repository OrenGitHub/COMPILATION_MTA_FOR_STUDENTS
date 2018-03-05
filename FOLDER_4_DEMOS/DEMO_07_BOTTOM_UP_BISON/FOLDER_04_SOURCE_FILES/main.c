/*********************/
/* FILE NAME: main.c */
/*********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"
#include "Parser_API.h"

/********/
/* main */
/********/
int main(int argc,char **argv)
{
	/***********************/
	/* [0] Initializations */
	/***********************/
	string Input_Filename=argv[1];
	string Output_Filename =argv[2];

	/**************************/
	/* [1] Dummy LEX LOG file */
	/**************************/
	ErrorMsg_Set_Log_Filename(Output_Filename);

	/**************************/
	/* [2] Parse Solution Set */
	/**************************/
	Parse(Input_Filename);
	
	/****************/
	/* [3] return 0 */
	/****************/
	return 0;
}

