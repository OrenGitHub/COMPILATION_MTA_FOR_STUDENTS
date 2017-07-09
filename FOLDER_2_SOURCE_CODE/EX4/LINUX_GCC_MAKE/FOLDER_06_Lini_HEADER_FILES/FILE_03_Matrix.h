#ifndef __MATRIX_H__
#define __MATRIX_H__

/*******************************/
/* FILE NAME: FILE_02_Matrix.h */
/*******************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <assert.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_02_Fraction.h"

/*********/
/* TYPES */
/*********/
typedef struct Matrix_	*Matrix;

/*************/
/* FUNCTIONS */
/*************/
void SetNumRows(Matrix M,int numRows);
void SetNumCols(Matrix M,int numCols);

/*************/
/* FUNCTIONS */
/*************/
Matrix AllocateMatrix(void);

/*************/
/* FUNCTIONS */
/*************/
void SetMatEntry(Matrix M,int i,int j, Fraction value);

#endif
