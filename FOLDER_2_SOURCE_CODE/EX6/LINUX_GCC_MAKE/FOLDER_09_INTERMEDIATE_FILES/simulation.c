#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

int *Temp_0;

int *Temp_1;

int *Temp_2;

int *Temp_3;

int *Temp_4;

int *Temp_5;

int *Temp_6;

int *Temp_7;

int *Temp_8;

int *Temp_9;

int *Temp_10;

int *Temp_11;

int *Temp_12;

int *Temp_13;

int *Temp_14;

int *sp;

int *fp;

int *ra;

int *rv;

int *a0;

int *a1;

int *a2;

int *a3;

int *v0;

int *v1;

int *t0;

int *t1;

int *t2;

int *t3;

int *t4;

int *t5;

int *t6;

int *t7;

void main()

{

	int b1=1;
	int b2=2;
	int b3=3;
	int b4=4;
	int b5=5;
	int b6=6;
	sp = &b3;
	fp = &b2;
	__asm
	{
		call _here0
		_here0: pop eax
		add eax,14
		mov ra,eax
	}

	goto Label_0_main;

Label_0_main:

	fp = (int *) ((int) sp + 40);

	Temp_3 = (int *) -4;

	Temp_2 =(int *) (((int) fp) + ((int) Temp_3));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t0+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t1+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t2+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t3+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t4+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t5+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t6+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t7+(0));

	Temp_4 = (int *) 6701;

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (Temp_4+(0));

	Temp_5 = (int *) 7500;

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (Temp_5+(0));

	Temp_6 = (int *) 19;

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (Temp_6+(0));

	Temp_7 = (int *) 3;

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (Temp_7+(0));

	__asm
	{
		call _here1
		_here1: pop eax
		add eax,14
		mov ra,eax
	}

	goto Label_1_AllocateRecord;

	sp = (int *) ((int) sp + 16);

	t7 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t6 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t5 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t4 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t3 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t2 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t1 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t0 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	*(Temp_2) = (int) (v0+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t0+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t1+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t2+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t3+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t4+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t5+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t6+(0));

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (t7+(0));

	Temp_13 = (int *) -4;

	Temp_12 =(int *) (((int) fp) + ((int) Temp_13));

	Temp_11 = (int *) *(Temp_12 + 0);

	Temp_14 = (int *) 8;

	Temp_10 =(int *) (((int) Temp_11) + ((int) Temp_14));

	Temp_9 = (int *) *(Temp_10 + 0);

	sp = (int *) ((int) sp + -4);

	*(sp) = (int) (Temp_9+(0));

	__asm
	{
		call _here2
		_here2: pop eax
		add eax,14
		mov ra,eax
	}

	goto Label_3_PrintInt;

	sp = (int *) ((int) sp + 4);

	t7 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t6 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t5 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t4 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t3 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t2 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t1 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	t0 = (int *) *(sp + 0);

	sp = (int *) ((int) sp + 4);

	exit(0);

Label_1_AllocateRecord:

	a0 = (int *) *(sp + 0);

	a1 = (int *) 4;

	a0 =(int *) (((int) a1) * ((int) a0));

	v0 = (int *) malloc((int) a0);

	a0 = (int *) *(sp + 0);

	a1 = (int *) 0;

	a2 = (int *) 0;

Label_1_Loop:

	if (((int) (a1)) >= ((int) (a0)))
	{
		goto Label_1_ExitLoop;
	}

	v1 =(int *) (((int) v0) + ((int) a2));

	a3 = (int *) ((int) sp + 4);

	a3 =(int *) (((int) a3) + ((int) a2));

	a3 = (int *) *(a3 + 0);

	*(v1) = (int) (a3+(0));

	a1 = (int *) ((int) a1 + 1);

	a2 = (int *) ((int) a2 + 4);

	goto Label_1_Loop;

Label_1_ExitLoop:

	__asm
	{
		jmp ra
	}

Label_2_AllocateArray:

	a0 = (int *) *(sp + 0);

	a0 = (int *) ((int) a0 + 1);

	a1 = (int *) 4;

	a0 =(int *) (((int) a1) * ((int) a0));

	v0 = (int *) malloc((int) a0);

	a0 = (int *) *(sp + 0);

	*(v0) = (int) (a0+(0));

	a1 = (int *) 0;

	a2 = (int *) 0;

Label_2_Loop:

	if (((int) (a1)) >= ((int) (a0)))
	{
		goto Label_2_ExitLoop;
	}

	v1 =(int *) (((int) v0) + ((int) a2));

	v1 = (int *) ((int) v1 + 4);

	a3 = (int *) *(sp + 1);

	*(v1) = (int) (a3+(0));

	a1 = (int *) ((int) a1 + 1);

	a2 = (int *) ((int) a2 + 4);

	goto Label_2_Loop;

Label_2_ExitLoop:

	__asm
	{
		jmp ra
	}

Label_3_PrintInt:

	a0 = (int *) *(sp + 0);

	printf("%d ",(int) a0);

	a0 = (int *) 32;

	printf("%c ",(char) a0);

	__asm
	{
		jmp ra
	}

Label_4_Access_Violation:

	a0 = (int *) 65;

	printf("%c ",(char) a0);

	a0 = (int *) 99;

	printf("%c ",(char) a0);

	a0 = (int *) 99;

	printf("%c ",(char) a0);

	a0 = (int *) 101;

	printf("%c ",(char) a0);

	a0 = (int *) 115;

	printf("%c ",(char) a0);

	a0 = (int *) 115;

	printf("%c ",(char) a0);

	a0 = (int *) 32;

	printf("%c ",(char) a0);

	a0 = (int *) 86;

	printf("%c ",(char) a0);

	a0 = (int *) 105;

	printf("%c ",(char) a0);

	a0 = (int *) 111;

	printf("%c ",(char) a0);

	a0 = (int *) 108;

	printf("%c ",(char) a0);

	a0 = (int *) 97;

	printf("%c ",(char) a0);

	a0 = (int *) 116;

	printf("%c ",(char) a0);

	a0 = (int *) 105;

	printf("%c ",(char) a0);

	a0 = (int *) 111;

	printf("%c ",(char) a0);

	a0 = (int *) 110;

	printf("%c ",(char) a0);

	exit(0);

}

