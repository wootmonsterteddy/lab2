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

struct arr find_arr(char var) //EJ KLAR FIXA
{
	struct arr *arrPtr;
	//Check input
	if(failCheck(var) == 1)
	{
		arrPtr = NULL;
	}

	switch(var) //Convert char to pointer to the global variable
	{
	case 'A': //Uppercase
		arrPtr = &A;
		break;
	case 'B':
		arrPtr = &B;
		break;
	case 'C':
		arrPtr = &C;
		break;
	case 'R':
		arrPtr = &R;
		break;
	case 'X':
		arrPtr = &X;
		break;
	case 'Y':
		arrPtr = &Y;
		break;
	}
	return arrPtr;
}

struct var find_var(char var) //EJ KLAR FIXA
{
	struct var *varPtr;

	//Check input
	if(failCheck(var) == 1)
	{
		return NULL;
	}

	switch(var) //Convert char to pointer to the global variable
	{
	case 'a': //Lowercase
		varPtr = &a;
		break;
	case 'b':
		varPtr = &b;
		break;
	case 'c':
		varPtr = &c;
		break;
	case 'r':
		varPtr = &r;
		break;
	case 'x':
		varPtr = &x;
		break;
	case 'y':
		varPtr = &y;
		break;
	}
	return varPtr;
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
