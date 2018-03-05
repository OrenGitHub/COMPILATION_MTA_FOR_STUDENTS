#ifndef __PARSE_H__
#define __PARSE_H__

/*****************/
/* INCLUDE FILES */
/*****************/
#include "util.h"
#include "PSEUDO_MIPS_ASM_AST.h"

PSEUDO_MIPS_ASM_AST_expList Pseudo_Assembley_To_AST(string Pseudo_Assembley_Filename);

extern int zzparse(void);
extern PSEUDO_MIPS_ASM_AST_expList PSEUDO_MIPS_ASM_AST_root;

#endif
