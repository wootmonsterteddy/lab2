/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

struct commands commandList[20] =
{ //name,args,description,number
		{"exit","","exit this application", 											1},
		{"exit x","","exit this application with return code x",						2},
		{"quit","","exit this application",												3},
		{"help","","shows this message",												4},
};

void callCommand(char *input1,char *input2,char *input3,char *input4)
{
	if(input1 == "help")
	{
		printhelp();
	}
	else if(input1 == "exit")
	{
		if(compareStrings(input2,"0") == 1 || compareStrings(input2,"") == 1)
		{
			exit(0);
		}
		else if(atoi(input2) > 0)
		{
			exit(atoi(input2));
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
	else
	{
		printf("Command not found.\n");
	}
}

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

}

void readLine(void)
{
	char input[80];

	printf(">> ");
	fgets(input,80,stdin);

	processLine(input);
}

int processLine(const char *line)
{
	char part1[20] = "",part2[20] = "",part3[20] = "",part4[20] = "";
	int partCounter = 1, i = 0,n = 0;

	while(line[i] != '\0') //Separate input into 4 parts
	{
		int doOnce = 0;
		while(line[i] == ' ') //Skip all spaces
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

	for(int i = 0; i < 4; ++i)
	{
		if(compareStrings(commandList[i].name,part1))
		{
			callCommand(commandList[i].name,part2,part3,part4);
		}
	}

	printf("%s %s %s %s",part1,part2,part3,part4);

	return 0;
}

void printhelp(void)
{
	int listSize = 0,i = 0;

	while(commandList[i].number)
	{
		listSize = commandList[i].number;
		++i;
	}
	printf("Available commands:\n");
/*
*/  i = 0;
	while (commandList[i].number != -1 || i < listSize)
	{
		printf("	%s %s: %s\n",commandList[i].name,commandList[i].args,commandList[i].description);
		i++;
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

#if 0
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

int clear (char name)
{
	int i = 0;

	if(failCheck(name) == 1)
	{
		printf("Error, incorrect usage of function. \n");
		return 0;
	}
	else if(failCheck(name) == -1)
	{
		name = 0.0;
	}
	else if(failCheck(name) == 0)
	{
		for(i = 0; i < 50; ++i)
		{
			name[i] = 0.0;
		}
	}
	return 0;
}


double set (char name, double v)
{
	if(failCheck(name) == -1)
	{
		name = v;
		return name;
	}
	else
	{
		printf("Error, incorrect input. \n");
		return 0;
	}
}
double array (char name, double start, double stop)
{
	int i = 0, temp;

	if(failCheck(name) == 0)
	{
		temp = (stop - start) / 50;
		for(i = 0; i < 50; ++i)
		{
			name[i] = start + (temp * i);
		}
		return name;
	}
	else
	{
		printf("Error, incorrect usage of function. \n");
		return 0;
	}
}

int show(char name)
{
	int i = 0;

	if(failCheck(name) == -1)
	{
		printf("%d", name);
	}
	else if(failCheck(name) == 0)
	{
		for(i = 0; i < 50; ++i)
		{
			printf("%d", name[i]);
		}
	}
	else
	{
		printf("Error, incorrect usage of function. \n");
		return 0;
	}
	return 0;
}

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
