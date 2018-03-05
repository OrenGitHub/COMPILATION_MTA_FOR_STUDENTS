/******************************************/
/* FILE NAME: FILE_12_RowOperations_AST.c */
/******************************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_01_util.h"

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_12_RowOperations_AST.h"

/****************/
/* STRUCT TYPES */
/****************/
struct AST_Ri_Swap_Rj_
{
	int i;
	int j;
};

/****************/
/* STRUCT TYPES */
/****************/
struct AST_Ri_equals_cRi_
{
	int i;
	AST_Number c;
};

/****************/
/* STRUCT TYPES */
/****************/
struct AST_Ri_Equals_Ri_Plus_cRj_
{
	int i;
	int j;
	AST_Number c;
};

/****************/
/* STRUCT TYPES */
/****************/
struct AST_RowOp_
{
	AST_ROW_OP_TYPE type;

	union
	{
		struct {int i; int j;}							Ri_Swap_Rj;
		struct {int i; AST_Number c;}					Ri_Equals_cRi;
		struct {int i; int op; AST_Number c; int j;}	Ri_Equals_Ri_Plus_cRj;
	} u;
};

/****************/
/* STRUCT TYPES */
/****************/
struct AST_RowOpList_
{
	AST_RowOp head;
	AST_RowOpList tail;
};

/*********/
/* CTORS */
/*********/
AST_RowOp		AST_Alloc_Ri_Swap_Rj(int i,int j)
{
	AST_RowOp p;
	
	p = (AST_RowOp) checked_malloc(sizeof(*p));

	p->type = AST_ROW_OP_TYPE_RI_SWAP_RJ;
	p->u.Ri_Swap_Rj.i = i;
	p->u.Ri_Swap_Rj.j = j;

	return p;
}
AST_RowOp		AST_Alloc_Ri_equals_cRi(int i, AST_Number c)
{
	AST_RowOp p;
	
	p = (AST_RowOp) checked_malloc(sizeof(*p));

	p->type = AST_ROW_OP_TYPE_RI_EQUALS_CRI;
	p->u.Ri_Equals_cRi.i = i;
	p->u.Ri_Equals_cRi.c = c;

	return p;
}
AST_RowOpList	AST_Alloc_RowOpList(AST_RowOp head,AST_RowOpList tail)
{
	AST_RowOpList p;
	
	p = (AST_RowOpList) checked_malloc(sizeof(*p));

	p->head = head;
	p->tail = tail;

	return p;
}
AST_RowOp		AST_Alloc_Ri_Equals_Ri_Plus_cRj(int i, int op, AST_Number c,int j)
{
	AST_RowOp p;
	
	p = (AST_RowOp) checked_malloc(sizeof(*p));

	p->type = AST_ROW_OP_TYPE_RI_EQUALS_RI_PLUS_CRJ;
	p->u.Ri_Equals_Ri_Plus_cRj.i = i;
	p->u.Ri_Equals_Ri_Plus_cRj.op = op;
	p->u.Ri_Equals_Ri_Plus_cRj.c = c;
	p->u.Ri_Equals_Ri_Plus_cRj.j = j;

	return p;
}
