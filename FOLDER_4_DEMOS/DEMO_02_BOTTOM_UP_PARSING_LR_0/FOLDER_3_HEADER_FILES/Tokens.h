#ifndef __TOKENS_H__
#define __TOKENS_H__

/***********************************/
/* FLEX uses 0-255 for inner stuff */
/***********************************/
#define SERIAL_NUMBER_START	256

/*********************/
/* TOKENS start here */
/*********************/
#define LBRACE		SERIAL_NUMBER_START+1
#define RBRACE		SERIAL_NUMBER_START+2
#define ID			SERIAL_NUMBER_START+3
#define INT			SERIAL_NUMBER_START+4
#define ASSIGN		SERIAL_NUMBER_START+5
#define SEMICOLON	SERIAL_NUMBER_START+6

/*********/
/* TYPES */
/*********/
typedef union
{
	union
	{
		int ival;
		string sval;
	}
	gval;
}
YYSTYPE;

/****************************/
/* EXTERNAL VARIABLE aalval */
/****************************/
extern YYSTYPE aalval;

#endif
