#ifndef __CALC_ERRORMSG_H__
#define __CALC_ERRORMSG_H__

/******************************/
/* FILE NAME: CALC_ErrorMsg.h */
/******************************/

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"

/**********************/
/* EXTERNAL VARIABLES */
/**********************/
extern int Calc_ErrorMsg_tokPos;

/***********/
/* NEWLINE */
/***********/
void Calc_ErrorMsg_Newline(void);

/*********/
/* ERROR */
/*********/
void Calc_ErrorMsg_Error(int, string,...);

/****************/
/* LOG FILENAME */
/****************/
void Calc_ErrorMsg_Set_Log_Filename(string log_Filename);

/*********/
/* RESET */
/*********/
void Calc_ErrorMsg_Reset(string filename);

#endif
