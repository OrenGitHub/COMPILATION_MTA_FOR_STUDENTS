#ifndef __ERRORMSG_H__
#define __ERRORMSG_H__

/*************************/
/* FILE NAME: ErrorMsg.h */
/*************************/

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "util.h"

/**********************/
/* EXTERNAL VARIABLES */
/**********************/
extern int ErrorMsg_tokPos;

/***********/
/* NEWLINE */
/***********/
void ErrorMsg_Newline(void);

/*********/
/* ERROR */
/*********/
void ErrorMsg_Error(int, string,...);

/****************/
/* LOG FILENAME */
/****************/
void ErrorMsg_Set_Log_Filename(string log_Filename);

/*********/
/* RESET */
/*********/
void ErrorMsg_Reset(string filename);

#endif
