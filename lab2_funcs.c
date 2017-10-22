/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

struct commands commandList[20] =
{ //name,args,description,number
		{"exit","","exit this application", 																			1},
		{"exit x","","exit this application with return code x",														2},
		{"quit","","exit this application",																				3},
		{"help","","shows this message",																				4},
		{"show","<var>","shows a scalar or array variable",																5},
		{"set","<var> <value>","set variable <var> to value <value>, e.g. 'set a 3.14'",								6},
		{"clear","<var>","clear the given variable or array by setting all values to 0",								7},
};

struct commands helpList[20] =
{ //name,args,description,number
		{"exit","","exit this application", 																			1},
		{"exit x","","exit this application with return code x",														2},
		{"quit","","exit this application",																				3},
		{"help","","shows this message",																				4},
		{"show","<var>","shows a scalar or array variable",																5},
		{"set","<var> <value>","set variable <var> to value <value>, e.g. 'set a 3.14'",								6},
};

void init(void)
{
	vars[0].n = 'a';
	vars[1].n = 'b';
	vars[2].n = 'c';
	vars[3].n = 'r';
	vars[4].n = 'x';
	vars[5].n = 'y';

	arrs[0].n = 'A';
	arrs[1].n = 'B';
	arrs[2].n = 'C';
	arrs[3].n = 'R';
	arrs[4].n = 'X';
	arrs[5].n = 'Y';

	clear('a');
	clear('b');
	clear('c');
	clear('r');
	clear('x');
	clear('y');

	clear('A');
	clear('B');
	clear('C');
	clear('R');
	clear('X');
	clear('Y');

}

matlab_var_t *find_var(char var)
{
	if(failCheck(var) != -1)
	{
		return NULL;
	}
	matlab_var_t *result;
	switch(var)
	{
	case 'a':
		result = &vars[0];
		break;
	case 'b':
		result = &vars[1];
		break;
	case 'c':
		result = &vars[2];
		break;
	case 'r':
		result = &vars[3];
		break;
	case 'x':
		result = &vars[4];
		break;
	case 'y':
		result = &vars[5];
		break;
	}
	return result;
}

matlab_arr_t *find_arr(char var)
{
	if(failCheck(var) != 0)
	{
		return NULL;
	}
	matlab_arr_t *result;
	switch(var)
	{
	case 'A':
		result = &arrs[0];
		break;
	case 'B':
		result = &arrs[1];
		break;
	case 'C':
		result = &arrs[2];
		break;
	case 'R':
		result = &arrs[3];
		break;
	case 'X':
		result = &arrs[4];
		break;
	case 'Y':
		result = &arrs[5];
		break;
	}
	return result;
}

void callCommand(char *input1,char *input2,char *input3,char *input4)
{
	if(input1 == "help")
	{
		printhelp();
	}
	else if(input1 == "exit")
	{
		if(strcmp(input2,"0") == 0 || strcmp(input2,"") == 0)
		{
			exit(0);
		}
		else if(atof(input2) > 0)
		{
			exit(atof(input2));
		}
		else
		{
			printf("Error: wrong usage of exit.\n");
			readLine();
		}
	}
	else if(input1 == "quit")
	{
		exit(0);
	}
	else if(input1 == "show")
	{
		show(*input2);
	}
	else if(input1 == "set")
	{
		double val = atof(input3);
		set(*input2,val);
	}
	else if(input1 == "clear")
	{
		clear(*input2);
		if(failCheck(*input2) == -1 || failCheck(*input2) == 0)
		{
			printf("%c cleared\n",*input2);
		}
	}
	else
	{
		printf("Command not found.\n");
	}
}

void readLine(void)
{
	char input[80] = { 0 };

	printf(">> ");
	fgets(input,80,stdin);

	processLine(input);
}

int processLine(const char *line)
{
	char part1[20] = {0},part2[20] = {0},part3[20] = {0},part4[20] = {0};
	int partCounter = 1, i = 0,n = 0;

	while(line[i] != '\0') //Separate input into 4 parts
	{
		int doOnce = 0;
		while(line[i] == ' ' || line[i] == '\n') //Skip all spaces
		{
			if(doOnce == 0)
			{
				partCounter++;
				n=0;
				doOnce = 1;
			}
			i++;
		}

		switch(partCounter)
		{
		case 1:
			part1[n] = line[i];
			break;
		case 2:
			part2[n] = line[i];
			break;
		case 3:
			part3[n] = line[i];
			break;
		case 4:
			part4[n] = line[i];
			break;
		}

		i++;
		n++;
	} //Separation complete

	i = 0;
	int length = 0;
	while(commandList[i].number)
	{
		++length;
		++i;
	}
	for(int i = 0; i < length; ++i)
	{
		if(strcmp(commandList[i].name,part1) == 0)
		{
			callCommand(commandList[i].name,part2,part3,part4);
		}
	}

	//printf("%s %s %s %s\n",part1,part2,part3,part4);

	return 0;
}

void printhelp(void)
{
	unsigned int length = 0, i = 0;
	while(helpList[i].number)
	{
		length = helpList[i].number;
		i++;
	}
	printf("Available commands:\n");

	for(int i = 0; i < length; ++i)
	{
		printf("	%s %s: %s\n",helpList[i].name,helpList[i].args,helpList[i].description);
	}

	/*
	printf("\nAvailable commands:\n"
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
	 */
}

#if 1
int failCheck(char var)
{
	if((var >= 'a' && var <= 'c') || var == 'r' || var == 'x' || var == 'y')
	{
		return -1;
	}
	else if((var >= 'A' && var <= 'C') || var == 'R' || var == 'X' || var == 'Y')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
#endif

#if 1
int clear(char var)
{
	if(failCheck(var) == 1)
	{
		printf("Error: incorrect usage of function. \n");
		return 0;
	}
	else if(failCheck(var) == -1)
	{
		matlab_var_t *variable = find_var(var);
		variable->v = 0.0;
	}
	else if(failCheck(var) == 0)
	{
		matlab_arr_t *array = find_arr(var);
		for(int i = 0; i < 50; ++i)
		{
			array->v[i] = 0.0;
		}
	}
	return 0;
}
#endif

#if 1
void set(char var, double v)
{
	if(failCheck(var) == -1)
	{
		matlab_var_t *variable = find_var(var);
		variable->v = v;
		printf("%c = %G\n",variable->n,variable->v);
	}
	else if(failCheck(var) == 0)
	{
		matlab_arr_t *array = find_arr(var);
		for(int i = 0; i < 50; ++i)
		{
			array->v[i] = v;
		}
		printf("%c[...] = %G\n",array->n,v);
	}
	else
	{
		printf("Error: incorrect input.\n");
	}
}
#endif

#if 1
int show(char name)
{
	if(failCheck(name) == -1)
	{
		matlab_var_t *variable = find_var(name);
		printf("%c = %G\n",name,variable->v);
	}
	else if(failCheck(name) == 0)
	{
		for(int i = 0; i < 50; ++i)
		{
			matlab_arr_t *array = find_arr(name);
			printf("%c[%i] = %G\n",name,i,array->v[i]);
		}
	}
	else
	{
		printf("Error: incorrect usage of function.\n");
		return 0;
	}
	return 0;
}
#endif

#if 0
double array (char var, double start, double stop)
{
	int i = 0, temp;

	if(failCheck(var) == 0)
	{
		temp = (stop - start) / 50;
		matlab_arr_t *array = find_arr(var);
		for(i = 0; i < 50; ++i)
		{
			array->v[i] = start + (temp * i);
		}
		return name;
	}
	else
	{
		printf("Error, incorrect usage of function. \n");
		return 0;
	}
}
#endif

#if 0
int calc(char r, char x, char y, char op)
{
	int i = 0;

	if( op != '+' || op != '-' || op != '*' || op != '/' || op != '!')
	{
		printf("Error, operator does not exist \n");
		return 0;
	}
	else if(failCheck(r) == 1 || failCheck(x) == 1 || failCheck(y) == 1)
	{
		printf("Error, incorrect input. \n");
		return 0;
	}
	else if(failCheck(r) == -1 || failCheck(x) == -1 || failCheck(y) == -1)
	{
		switch(op)
		{
		case 1:
			op = '+';
			r = x + y;
			break;
		case 2:
			op = '-';
			r = x - y;
			break;
		case 3:
			op = '*';
			r = x * y;
			break;
		case 4:
			op = '/';
			r = x / y;
			break;
		}
		return show_vars(r);
	}
	else
	{
		switch(op)
		{
		case 1:
			op = '+';
			for(i = 0; i < 50; ++i)
				r[i] = x[i] + y[i];
			break;
		case 2:
			op = '-';
			for(i = 0; i < 50; ++i)
				r[i] = x[i] - y[i];
			break;
		case 3:
			op = '*';
			for(i = 0; i < 50; ++i)
				r[i] = x[i] * y[i];
			break;
		case 4:
			op = '/';
			for(i = 0; i < 50; ++i)
				r[i] = x[i] / y[i];
			break;
		}
		return 0;
	}
}
#endif

/*
int compareStrings(char *string,char *compare)
{
	int i = 0, correct = 0, length = 0;

	while(compare[i] != '\0')
	{
		++length;
		++i;
	}

	i = 0;
	while(string[i] == compare[i])
	{
		++correct;
		if(correct == length)
		{
			return 1;
		}
		++i;
	}
	return 0;
}
 */
