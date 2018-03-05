#ifndef __TOKENS_H__
#define __TOKENS_H__

/***********************************/
/* FLEX uses 0-255 for inner stuff */
/***********************************/
#define SERIAL_NUMBER_START	256

/*********************/
/* TOKENS start here */
/*********************/
#define SMALLa	SERIAL_NUMBER_START+1
#define SMALLb	SERIAL_NUMBER_START+2
#define SMALLx	SERIAL_NUMBER_START+3

/*********/
/* TYPES */
/*********/
typedef union
{
	union
	{
		int ival;
	}
	gval;
}
YYSTYPE;

/****************************/
/* EXTERNAL VARIABLE aalval */
/****************************/
extern YYSTYPE aalval;

#endif
