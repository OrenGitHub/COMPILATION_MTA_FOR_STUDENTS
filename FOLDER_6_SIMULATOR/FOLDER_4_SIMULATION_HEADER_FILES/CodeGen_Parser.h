typedef union
{
	union
	{
		int								ival;
		int								temp_serial_number;
		float							fval;
		string							sval;
		string							register_name;
		PSEUDO_MIPS_ASM_AST_LabelList	labelList;
		PSEUDO_MIPS_ASM_AST_Var			var;
		PSEUDO_MIPS_ASM_AST_Label_Type_	label;
		PSEUDO_MIPS_ASM_AST_exp			exp;
		PSEUDO_MIPS_ASM_AST_expList		expList;
	}
	gval;
} YYSTYPE;
#define	INT	258
#define	FLOAT	259
#define	STRING	260
#define	VFTABLE	261
#define	PRINT_INT	262
#define	PRINT_CHAR	263
#define	STRING_VAR	264
#define	ALLOCATE	265
#define	START_OF_CODE	266
#define	EXIT	267
#define	ID	268
#define	LABEL	269
#define	COMMA	270
#define	COLON	271
#define	LOAD	272
#define	STORE	273
#define	LOAD_IMMEDIATE	274
#define	LOAD_ADDRESS	275
#define	LOAD_BYTE	276
#define	STORE_BYTE	277
#define	ADD_IMMEDIATE	278
#define	JUMP	279
#define	JUMP_AND_LINK	280
#define	JUMP_AND_LINK_REG	281
#define	LPAREN	282
#define	RPAREN	283
#define	PLUS	284
#define	MINUS	285
#define	ADD	286
#define	SUB	287
#define	MUL	288
#define	DIV	289
#define	TEMP	290
#define	BEQ	291
#define	BNE	292
#define	BLT	293
#define	BLE	294
#define	BGT	295
#define	BGE	296
#define	REGISTER	297
#define	AND	298
#define	OR	299
#define	MOVE	300


extern YYSTYPE zzlval;
