#ifndef __ERRORMSG_H__
#define __ERRORMSG_H__

/*************************/
/* FILE NAME: ErrorMsg.h */
/*************************/
extern bool ErrorMsg_anyErrors;

void ErrorMsg_Newline(void);

extern int ErrorMsg_tokPos;

void ErrorMsg_Error(int, string,...);
void ErrorMsg_Reset(string filename);

#endif
