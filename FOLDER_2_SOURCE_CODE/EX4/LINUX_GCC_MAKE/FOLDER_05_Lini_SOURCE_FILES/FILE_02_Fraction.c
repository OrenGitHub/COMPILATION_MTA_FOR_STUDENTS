/*************************/
/* FILE NAME: Fraction.c */
/*************************/

/*************************/
/* GENERAL INCLUDE FILES */
/*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************/
/* PROJECT INCLUDE FILES */
/*************************/
#include "FILE_01_util.h"
#include "FILE_02_Fraction.h"

/*********/
/* TYPES */
/*********/
struct Fraction_
{
	int nominator;
	int denominator;
};

/*************/
/* FUNCTIONS */
/*************/
void SetNominator(Fraction f,int nominator){f->nominator = nominator;}
void SetDenominator(Fraction f,int denominator){f->denominator = denominator;}

/*************/
/* FUNCTIONS */
/*************/
Fraction New_Fraction(int nominator,int denominator)
{
	Fraction p = (Fraction) checked_malloc(sizeof(*p));
	
	p->nominator = nominator;
	p->denominator = denominator;
	
	return p;
}

/*************/
/* FUNCTIONS */
/*************/
void FractionToLowestTerms(Fraction f)
{
	int i=0;
	int non_trivial_divisor=1;
	int abs_nominator = abs(f->nominator);
	int abs_denominator = abs(f->denominator);
	
	for (i=2;(i<abs_nominator)&&(i<abs_denominator);i++)
	{
		if (((abs_nominator/i)*i) == abs_nominator)
		{
			if (((abs_denominator/i)*i) == abs_denominator)
			{
				non_trivial_divisor = i;
			}
		}
	}
	
	f->nominator   /= non_trivial_divisor;
	f->denominator /= non_trivial_divisor;
}

/*************/
/* FUNCTIONS */
/*************/
Fraction AllocateFraction(void)
{
	Fraction p = (Fraction) checked_malloc(sizeof(*p));
	
	return p;
}
