#ifndef __PARSER_H__
#define __PARSER_H__

/*****/
/* E */
/*****/
#define NUM_VARIABLES 1

/******************************/
/* (, ), INT(x), +, -, *, / $ */
/******************************/
#define NUM_TOKENS 8

/*********/
/* Table */
/*********/
extern string table[][NUM_VARIABLES+NUM_TOKENS];

/***********/
/* Parse() */
/***********/
int Parse();

#endif
