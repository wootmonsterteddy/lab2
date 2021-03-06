/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

struct commands commandList[17] =
{ //name,args,description,number
		{"exit","","exit this application", 																																1},
		{"exit x","","exit this application with return code x",																											2},
		{"quit","","exit this application",																																	3},
		{"help","","shows this message",																																	4},
		{"show","<var>","shows a scalar or array variable",																													5},
		{"set","<var> <value>","set variable <var> to value <value>, e.g. 'set a 3.14'",																					6},
		{"clear","<var>","clear the given variable or array by setting all values to 0",																					7},
		{"array","<var> <start> <stop>","fill array <var> with first value <start> and last value <stop> with values between at equal steps",								8},
		{"importCSV","<var> <filename>","imports values from the CSV file <filename> and stores in array <var>", 															9},
		{"exportCSV","<var> <filename>","exports an array <var> into the CSV file <filename>", 																				10},
		{"showCSV","<filename>","displays the contents of the .csv file <filename>",			 																			11},
		{"showvars","","displays the contents of all scalar variables",							 																			12},
		{"sin","<res> <var>","calculates the sin values of <var> and stores in <res>, works in degrees",		 															13},
		{"exportMAT","<var> <filename>","exports a variable <var> to the MAT file <filename>",		 																		14},
		{"debounce","<res> <var>","debounces an array <var> and outputs the result to an array <res>",		 																15},
		{"event","<res> <var>","finds and event in array <var> and outputs the result to an array <res> and prints start and stop values to the screen",					16},
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

	printf("MINIBaltam started. Type 'help' for a list of commands.\n");
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

void callCommand(char *input1, char *input2, char *input3, char *input4, char *input5)
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
		set(*input2, val);
	}
	else if(input1 == "clear")
	{
		clear(*input2);
		if(failCheck(*input2) == -1 || failCheck(*input2) == 0)
		{
			printf("%c cleared\n", *input2);
		}
	}
	else if(input1 == "array")
	{
		if(*input3 == NULL || *input4 == NULL || *input5 != NULL)
		{
			printf("Error: wrong usage of function.\n");
		}
		else
		{
			double number1 = atof(input3);
			double number2 = atof(input4);
			array(*input2,number1,number2);
		}
	}
	else if(input1 == "importCSV")
	{
		importCSV(input2,input3);
	}
	else if(input1 == "exportCSV")
	{
		exportCSV(input2,input3);
	}
	else if(input1 == "showCSV")
	{
		showCSV(input2);
	}
	else if(input1 == "showvars")
	{
		show_vars();
	}
	else if(input1 == "sin")
	{
		calcSin(*input2,*input3);
	}
	else if(input1 == "exportMAT")
	{
		exportMAT(input2,input3);
	}
	else if(input1 == "debounce")
	{
		debounce(*input2,*input3);
	}
	else if(input1 == "event")
	{
		event(*input2,*input3);
	}
	else
	{
		printf("Error: command not found.\n");
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
	char part1[20] = {0}, part2[20] = {0}, part3[20] = {0}, part4[20] = {0}, part5[20] = {0};
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
		case 5:
			part5[n] = line[i];
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
		if(strcmp(commandList[i].name, part1) == 0)
		{
			callCommand(commandList[i].name, part2, part3, part4, part5);
			return 0;
		}
	}
	if((failCheck(*part1) == -1 || failCheck(*part1) == 0) && *part2 == '=')
	{
		calc(part1,part3,part4,part5);
	}
	else
	{
		printf("Error: command not found.\n");
	}
	return 0;
}

void printhelp(void)
{
	unsigned int length = 0, i = 0;
	while(commandList[i].number)
	{
		length = commandList[i].number;
		i++;
	}
	printf("Available commands:\n");

	for(int i = 0; i < length; ++i)
	{
		printf("	%s %s: %s\n", commandList[i].name, commandList[i].args, commandList[i].description);
	}
}


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

int clear(char var)
{
	if(failCheck(var) == 1)
	{
		printf("Error: unknown variable '%c'. \n", var);
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

void set(char var, double v)
{
	if(failCheck(var) == -1)
	{
		matlab_var_t *variable = find_var(var);
		variable->v = v;
		printf("%c = %G\n", variable->n, variable->v);
	}
	else if(failCheck(var) == 0)
	{
		matlab_arr_t *array = find_arr(var);
		for(int i = 0; i < 50; ++i)
		{
			array->v[i] = v;
		}
		printf("%c[...] = %G\n", array->n, v);
	}
	else
	{
		printf("Error: unknown variable '%c'\n",var);
	}
}

int show(char name)
{
	if(failCheck(name) == -1)
	{
		matlab_var_t *variable = find_var(name);
		printf("%c = %G\n", name, variable->v);
	}
	else if(failCheck(name) == 0)
	{
		for(int i = 0; i < 50; ++i)
		{
			matlab_arr_t *array = find_arr(name);
			printf("%c[%i] = %G\n", name, i, array->v[i]);
		}
	}
	else
	{
		printf("Error: unknown variable '%c'\n",name);
		return 0;
	}
	return 0;
}

int array (char name, double start, double stop)
{
	if(failCheck(name) == 0)
	{
		double temp;
		matlab_arr_t *array = find_arr(name);
		array->v[0] = start;
		array->v[49] = stop;
		temp = (stop - start) / 49;
		for(int i = 1; i < 49; ++i)
		{
			array->v[i] = start + (temp * (double) i);
		}
		return 0;
	}
	else
	{
		printf("Error: wrong usage of function.\n");
		return 1;
	}
}

int calc(char *r, char *x, char *op, char *y)
{
	int i = 0;

	if((failCheck(*r) == 1 || failCheck(*x) == 1 || failCheck(*y) == 1) ||
		(failCheck(*r) != failCheck(*x) || failCheck(*r) != failCheck(*y)))
	{
		printf("Error: incorrect input.\n");
		return 1;
	}
	else if(failCheck(*r) == -1 && failCheck(*x) == -1 && failCheck(*y) == -1)
	{
		matlab_var_t *result = find_var(*r);
		matlab_var_t *var1 = find_var(*x);
		matlab_var_t *var2 = find_var(*y);

		switch(*op)
		{
		case '+':
			result->v = var1->v + var2->v;
			break;
		case '-':
			result->v = var1->v - var2->v;
			break;
		case '*':
			result->v = var1->v * var2->v;
			break;
		case '/':
			result->v = var1->v / var2->v;
			break;
		default:
			printf("Error: operator does not exist.\n");
			return 0;
		}
		printf("%c = %g\n",*r,result->v);
	}
	else if(failCheck(*r) == 0 && failCheck(*x) == 0 && failCheck(*y) == 0)
	{
		matlab_arr_t *result = find_arr(*r);
		matlab_arr_t *array1 = find_arr(*x);
		matlab_arr_t *array2 = find_arr(*y);
		switch(*op)
		{
		case '+':
			for(i = 0; i < 50; ++i)
				result->v[i] = array1->v[i] + array2->v[i];
			break;
		case '-':
			for(i = 0; i < 50; ++i)
				result->v[i] = array1->v[i] - array2->v[i];
			break;
		case '*':
			for(i = 0; i < 50; ++i)
				result->v[i] = array1->v[i] * array2->v[i];
			break;
		case '/':
			for(i = 0; i < 50; ++i)
				result->v[i] = array1->v[i] / array2->v[i];
			break;
		default:
			printf("Error: operator does not exist.\n");
			return 0;
		}
	}
	return 0;
}


void importCSV(const char *var,const char *filename)
{
	if(failCheck(*var) != 0)
	{
		printf("Error: wrong usage of function.\n");
		return;
	}

	FILE *inputFile = fopen(filename,"r");

	if(inputFile == NULL)
	{
		printf("Error: file could not be opened.\n");
		return;
	}

	matlab_arr_t *array = find_arr(*var);
	char buffer[256] = {0};

	for(int i = 0; i < 50; ++i)
	{
		fgets(buffer,sizeof(buffer)-1,inputFile);
		if(*buffer == EOF)
		{
			break;
		}
		else
		{
			array->v[i] = atof(buffer);
		}
	}

	fclose(inputFile);
}

void exportCSV(const char *var,const char *filename)
{
	if(failCheck(*var) != 0)
	{
		printf("Error: wrong usage of function.\n");
		return;
	}

	FILE *outputFile = fopen(filename,"w");

	if(outputFile == NULL)
	{
		printf("Error: file could not be opened.\n");
		return;
	}

	matlab_arr_t *array = find_arr(*var);

	for(int i = 0; i < 50; ++i)
	{
		fprintf(outputFile,"%G\n",array->v[i]);
	}

	fclose(outputFile);
}

int showCSV(const char *filename)
{
	FILE *inputFile = fopen(filename,"r");

	if(inputFile == NULL)
	{
		printf("Error: file could not be opened.\n");
		return 1;
	}

	char buffer[256] = {0};

	for(int i = 0; i < 50; ++i)
	{
		fgets(buffer,sizeof(buffer)-1,inputFile);
		printf("%s",buffer);
	}

	fclose(inputFile);
	return 0;
}

int exportMAT(char *var, const char *filename)
{
	Fmatrix header;

	header.type = 0000;
	header.mrows = ARRAY_LEN;
	header.ncols = 1;
	header.imagf = 0;
	header.namelen = 1 + 1;

	FILE *outputFile = fopen(filename,"wb");

	if(outputFile == NULL)
	{
		printf("Error: file could not be opened.\n");
		return 1;
	}

	char *name[2] = {0};
	name[0] = *var;
	name[1] = '\0';

	matlab_arr_t *array = find_arr(*var);

	fwrite(&header,sizeof(Fmatrix),1,outputFile); //Write header
	fwrite(&name,1,2,outputFile); //Write name
	fwrite(array->v,sizeof(double),ARRAY_LEN,outputFile);

	fclose(outputFile);

	return 0;
}

void show_vars(void)
{
	for(int i = 0; i < 6; ++i)
	{
		printf("%c = %G\n",vars[i].n,vars[i].v);
	}
}

int calcSin(char res, char var)
{
	if(failCheck(res) == -1 && failCheck(var) == -1)
	{
		//Calculate for scalars
		matlab_var_t *result = find_var(res);
		matlab_var_t *variable = find_var(var);

		result->v = sin((float)(M_PI/180)*(variable->v));

		printf("%c = %G\n",result->n,result->v);
	}
	else if(failCheck(res) == 0 && failCheck(var) == 0)
	{
		//Calculate for arrays
		matlab_arr_t *result = find_arr(res);
		matlab_arr_t *variable = find_arr(var);

		for(int i = 0; i < 50; ++i)
		{
			result->v[i] = sin((float)(M_PI/180)*(variable->v[i]));
		}
	}
	else
	{
		printf("Error: wrong usage of function.\n");
		return 1;
	}

	return 0;
}

int debounce(char R, char I) // R is result, I is input
{
	matlab_arr_t *result = find_arr(R);
	matlab_arr_t *input = find_arr(I);

	for(int i = 0; i < ARRAY_LEN; i++)	//Clean input to <0.3V & >3.3V
	{
		if(input->v[i] > 3)
		{
			result->v[i] = 3.3;
		}
		else if(input->v[i] < 0.3)
		{
			result->v[i] = 0;
		}
	}

	for(int i = 1; i < ARRAY_LEN-2; i++) //Pure digital signal
	{
		if(result->v[i] != result->v[i+1] || result->v[i] != result->v[i+2])
		{
			result->v[i] = result->v[i-1];
		}
	}

	if(result->v[48] != result->v[49])
	{
		result->v[48] = result->v[47];
	}
	result->v[49] = result->v[48];

	return 0;
}

int event(char R, char I)
{
	matlab_arr_t *result = find_arr(R);
	matlab_arr_t *input = find_arr(I);
	int counter = 0, start = -1, stop = -1, i;
	bool eventFound = false;

	for(int i = 0; i < ARRAY_LEN; i++) //Clear result array
	{
		result->v[i] = 0;
	}

	for(i = 0; i < ARRAY_LEN-10; i++)
	{
		int k = 0;
		while(input->v[i+k] && input->v[i+k] > 0.5) //Look for 10 samples.
		{
			if(counter == 10)
			{
				eventFound = true;
				start = i;
				break;
			}
			counter++;
			k++;
		}
		if(eventFound == true)
		{
			while(input->v[i] > 0.5 && i <= 49)
			{
				result->v[i] = input->v[i];
				stop = i;
				i++;
			}
			break;
		}
	}

	printf("Event start detected @%i\nEvent stop detected @%i\n",start,stop);

	return 0;
}
