/***********/
/* parse.c */
/***********/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "parse.h"
#include "util.h"
#include "PSEUDO_MIPS_ASM_AST_errormsg.h"

/***************************/
/* Pseudo_Assembley_To_AST */
/***************************/
PSEUDO_MIPS_ASM_AST_expList Pseudo_Assembley_To_AST(string Pseudo_Assembley_Filename)
{
	PSEUDO_MIPS_ASM_AST_EM_reset(Pseudo_Assembley_Filename);
 	if (zzparse() == 0)
	{
		/******************/
		/* parsing worked */
		/******************/
		return PSEUDO_MIPS_ASM_AST_root;
	}
	else
	{
		return NULL;
	}
}
