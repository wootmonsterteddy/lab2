/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

//Prepare global variables
struct var a,b,c,r,x,y;
struct arr A,B,C,R,X,Y;

int failCheck(char var) //KLAR
{
	if((var >= 'a' && var <= 'c') || var == 'r' || var == 'x' || var == 'y' || (var >= 'A' && var <= 'C') || var == 'R' || var == 'X' || var == 'Y')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

double* findPtr(char var) //EJ KLAR
{
	//Check input
	if(failCheck(var) == 1)
	{
		return NULL;
	}

	double *ptr;

	switch(var) //Convert char to pointer to the global variable
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

int checkSize(char var) //KLAR
{
	double *ptr = findPtr(var);
	return sizeof(*ptr)/sizeof(double);
}

int clear(char var) //KLAR
{
	//function must set all elements of an array to 0.0
	double *ptr = findPtr(var);
	if(checkSize(*ptr) == 1)
	{
		*ptr = 0.0;
		return 0;
	}
	else if(checkSize(*ptr) > 1 && checkSize(*ptr) <= 101)
	{
		for(int i = 0; i < 100; i++)
		{
			ptr[i] = 0.0;
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int set(char name, double v) // EJ KLAR
{

}

int show(char name) //Done
{
	//For arrays
	if((name >= 'A' && name <= 'C') || name == 'R' || (name >= 'X' && name <= 'Y'))
	{
		for(int i = 0; i < 100 ; ++i)
		{
			printf("%d", name[i]);
		}
	}
	//For scalars
	else if((name >= 'a' && name <= 'c') || name == 'r' || (name >= 'x' && name <= 'y'))
	{
		printf("%d", name);
	}
	//For incorrect input
	else
	{
		return 1;
	}
	return 0;
}

int array(char name, double start, double stop)
{

}
