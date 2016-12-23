/*********************/
/* FILE NAME: main.c */
/*********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <stdlib.h>

/*****************/
/* INCLUDE FILES */
/*****************/
#include "asm.h"
#include "IR.h"
#include "util.h"
#include "tree.h"
#include "symbol.h"
#include "semant.h"
#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "Liveness_Analysis.h"
#include "Register_Allocation.h"
#include "Pseudo_Assembley_To_Simulation.h"
#include "Write_Assembley_Output_Filename.h"

/********************/
/* GLOBAL VARIABLES */
/********************/
static A_exp AST=NULL;
static T_exp IR_tree = NULL;
string Tiger_Program_Filename;
string Mips_Asm_Output_Filename;
int Temporaries_To_Registers_Map[MAX_NUM_TEMPORARIES];

/********/
/* main */
/********/
int main(int argc,char **argv)
{
	/***********************/
	/* [0] Initializations */
	/***********************/
	Tiger_Program_Filename=argv[1];
	Mips_Asm_Output_Filename=argv[2];

	/***************************************************/
	/* [1] Build Abstract Syntax Tree Of Tiger Program */
	/***************************************************/
	AST = Tiger_Program_To_AST(Tiger_Program_Filename);
	ABSYN_PrintTree(AST,"GRAPHVIZ_FILES/ABSYN_Graph.txt");

	/*************************/
	/* [2] Semantic Analysis */
	/*************************/
	Semantic_Analysis(AST);

	/***********************************/
	/* [3] Intermediate Representation */
	/***********************************/
	IR_tree = AST_To_IR(AST);
	IR_PrintTree(IR_tree,"GRAPHVIZ_FILES/IR_Graph.txt");

	/***********************/
	/* [4] Code Generation */
	/***********************/
	IR_To_Pseudo_Assembley(
		IR_tree,
		"Pseudo_Assembley.txt");

	/***********************************************/
	/* [5] Generate PC Simulation for unit testing */
	/***********************************************/
	Pseudo_Assembley_To_Simulation(
		"Pseudo_Assembley.txt",
		"simulation.c");

	/**********************************************/
	/* [6] Liveness Analysis & Interference Graph */
	/**********************************************/
	Liveness_Analysis(
		"Pseudo_Assembley.txt",
		"Liveness_Analysis.txt",
		"Interference_Graph.txt");

	/***************************/
	/* [7] Register Allocation */
	/***************************/
	Register_Allocation(
		"Interference_Graph.txt",
		Temporaries_To_Registers_Map);

	/****************************/
	/* [8] Write Assembley File */
	/****************************/
	Write_Assembley_Output_File(
		"Pseudo_Assembley.txt",
		Temporaries_To_Registers_Map,
		Mips_Asm_Output_Filename);
}
