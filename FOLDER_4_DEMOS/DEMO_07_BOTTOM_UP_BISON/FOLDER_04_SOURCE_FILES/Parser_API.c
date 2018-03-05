/****************/
/* Parser_API.c */
/****************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"
#include "ErrorMsg.h"
#include "Parser_API.h"

/**********************/
/* Parse Input Matrix */
/**********************/
int Parse(string Input_Filename)
{
	/*************************/
	/* Open file for parsing */
	/*************************/
	ErrorMsg_Reset(Input_Filename);

	/*******************************/
	/* 3 ... 2 ... 1 ... parse !!! */
	/*******************************/
	if (aaparse() == 0)
	{
		/******************/
		/* parsing worked */
		/******************/
		printf("\n\n>> %d\n\n",ROOT);
	}
	else
	{
		/******************/
		/* parsing failed */
		/******************/
		printf("\n\n>> ERROR\n\n");
		return -1;
	}
}

