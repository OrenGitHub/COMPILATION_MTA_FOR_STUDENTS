/***********************/
/* FILE NAME: Matrix.c */
/***********************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_02_Fraction.h"
#include "FILE_03_Matrix.h"

/***************/
/* DEFINITIONS */
/***************/
#define MAX_NUM_ROWS 4
#define MAX_NUM_COLS 5

/*********/
/* TYPES */
/*********/
struct Matrix_
{
	int numRows;
	int numCols;
	
	Fraction Mat[MAX_NUM_ROWS][MAX_NUM_COLS];
};

/*************/
/* FUNCTIONS */
/*************/
void SetNumRows(Matrix M,int numRows){M->numRows = numRows;}
void SetNumCols(Matrix M,int numCols){M->numCols = numCols;}

/*************/
/* FUNCTIONS */
/*************/
void SetMatEntry(Matrix M,int i,int j,Fraction value)
{
	M->Mat[i][j]=value;
}

/*************/
/* FUNCTIONS */
/*************/
Matrix AllocateMatrix(void)
{
	Matrix p = (Matrix) checked_malloc(sizeof(*p));
	
	return p;
}
void ClearMatrix(Matrix M)
{
	memset(M->Mat,0,sizeof(M->Mat));
}

