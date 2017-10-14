/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

//Prepare global variables
double A[101]={0}, B[101]={0}, C[101]={0}, R[101]={0}, X[101]={0}, Y[101]={0};
double a=0, b=0, c=0, r=0, x=0, y=0;

int failCheck(char name) // KLAR
{
	if((name >= 'A' && name <= 'C') || (name >= 'a' && name <= 'c') ||
			(name >= 'X' && name <= 'Y') || (name >= 'x' && name <= 'y') ||
			name == 'R' || name == 'r')
	{
		return 0;
	}
	return 1;
}

double* find_var(char name)
{
	//Check input
	if(failCheck(name) == 1)
	{
		return NULL;
	}

	double *ptr;

	switch(name) //Convert char to pointer to the global variable
	{
	case 'a':
		ptr = &a;
		break;
	case 'b':
		ptr = &b;
		break;
	case 'c':
		ptr = &c;
		break;
	case 'r':
		ptr = &r;
		break;
	case 'x':
		ptr = &x;
		break;
	case 'y':
		ptr = &y;
		break;
	}

	return ptr;
}

double* find_arr(char name)
{
	//Check input
	if(failCheck(name) == 1)
	{
		return NULL;
	}

	double *ptr;

	switch(name) //Convert char to pointer to the global variable
	{
	case 'A': //Uppercase
		ptr = &A;
		break;
	case 'B':
		ptr = &B;
		break;
	case 'C':
		ptr = &C;
		break;
	case 'R':
		ptr = &R;
		break;
	case 'X':
		ptr = &X;
		break;
	case 'Y':
		ptr = &Y;
		break;

	case 'a': //Lowercase
		ptr = &a;
		break;
	case 'b':
		ptr = &b;
		break;
	case 'c':
		ptr = &c;
		break;
	case 'r':
		ptr = &r;
		break;
	case 'x':
		ptr = &x;
		break;
	case 'y':
		ptr = &y;
		break;
	}

	return ptr;
}

int checkSize(char name) // EJ KLAR
{
	int size = sizeof(name)/sizeof(double);
	return size;
}

int clear(char var) // EJ KLAR
{
	if (checkSize(var) > 1)
	{
		var = { 0 }; // FixaAAAAA
		return 0;
	}
	else
	{
		return 1;
	}
}

int set(char name, double v) // EJ KLAR
{

	if(checkSize(name) == 1)
	{
		name = v;
	}
	else if (checkSize(name) > 1)
	{

	}
	else
	{

	}

	return 0;
}

int show(char name) //Done
{
	int i;

	//For arrays
	if((name >= 'A' && name <= 'C') || name == 'R' || (name >= 'X' && name <= 'Y'))
	{
		for(i = 0; i < 100 ; ++i)
			printf("%d", name[i]);
	}
	//For scalars
	else if((name >= 'a' && name <= 'c') || name == 'r' || (name >= 'x' && name <= 'y'))
	{
		printf("%d", name);
	}
	//For incorrect input
	else
	{
		return 0;
	}
	return 0;
}







