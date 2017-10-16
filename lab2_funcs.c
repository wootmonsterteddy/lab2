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

void readInput(void)
{

	char* input[50];
	fgets(input,50,stdin);

}

void printhelp(void)
{
	printf("Available commands:\n"
			"	help: shows this message\n"
			"	set <var> <value>: Set variable <var> to value <value>, e.g. 'set a 3.14'\n"
			"	sin <res> <var>: Calculates the sin values of <var> and stores in <res>\n"
			"	show <var>: Shows a scalar or array variable\n"
			"	showFile <filename>: Shows the file <filename>\n"
			"	deleteFile <filename>: Deletes the file <filename>\n"
			"	importCSV <var> <filename>: Imports variables from the CSV file <filename> and stores in array <var>\n"
			"	exportCSV <filename>: Saves a variables into the CSV file <filename>\n"
			"	exportMAT <filename>: Saves a variables into the JSON file <filename>\n"
			"	exportJSON <filename>: Saves a variables into the JSON file <filename>\n"
			"	exportXML <filename>: Saves a variables into the XML file <filename>\n"
			"	quit: exit this application\n"
			"	exit: exit this application\n"
			"	exit x: exit this application with return code x\n");
}

int checkInput(char var) //KLAR
{
	//0 = fail, 1 = upper, 2 = lower
	if((var >= 'a' && var <= 'c') || var == 'r' || var == 'x' || var == 'y')
	{
		return 2;
	}
	else if ((var >= 'A' && var <= 'C') || var == 'R' || var == 'X' || var == 'Y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct arr *find_arr(char var) //EJ KLAR FIXA
{
	struct arr *arrPtr;
	//Check input
	if(checkInput(var) == 0)
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

	return *arrPtr;
}

struct var *find_var(char var) //EJ KLAR FIXA
{
	struct var *varPtr;

	//Check input
	if(checkInput(var) == 0)
	{
		varPtr = NULL;
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

	return *varPtr;
}

int checkSize(char var) //KLAR
{
	switch(checkInput(var))
	{
	case 1:
		struct arr *ptr1 = find_arr(var);
		return sizeof(ptr1)/sizeof(double)-1;
		break;
	case 2:
		struct var *ptr2 = find_var(var);
		return sizeof(ptr2)/sizeof(double)-1;
		break;
	default:
		return -1;
		break;
	}
}

int clear(char var) //KLAR
{
	//function must set all elements of an array to 0.0
	double *ptr = findPtr(var); //FIXA
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


	return 0;
}

int show(char name) //EJ KLAR
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
