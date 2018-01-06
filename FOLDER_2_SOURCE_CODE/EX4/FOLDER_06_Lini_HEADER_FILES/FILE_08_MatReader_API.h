#ifndef __MAT_READER_API_H__
#define __MAT_READER_API_H__

/**************************************/
/* FILE NAME: FILE_08_MatReader_API.h */
/**************************************/

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_01_util.h"
#include "FILE_03_Matrix.h"

/*******************/
/* EXTERN AST ROOT */
/*******************/
extern Matrix MatReader_AST_ROOT;

/*************/
/* FUNCTIONS */
/*************/
Matrix Parse_Input_Matrix(string Matrix_Filename);

#endif
