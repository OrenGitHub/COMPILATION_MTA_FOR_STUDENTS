#ifndef __PARSER_H__
#define __PARSER_H__

/********/
/* E, L */
/********/
#define NUM_VARIABLES 2

/********************************/
/* {, }, ID(x), INT(i), =, ;, $ */
/********************************/
#define NUM_TOKENS 7

/*********/
/* Table */
/*********/
extern string table[][NUM_VARIABLES+NUM_TOKENS];

/***********/
/* Parse() */
/***********/
int Parse();

#endif
