/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

void callCommand(char *input)
{
	if(input == "help")
	{
		printhelp();
	}
	else if(input == "exit")
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

struct commands commandList[20] =
{
		{"exit","","exit this application", 											1},
		{"exit x","","exit this application with return code x",						2},
		{"quit","","exit this application",												3},
		{"help","","shows this message",												4},
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
		if(line[i] == ' ')
		{
			partCounter++;
			i++;
			n=0;
			continue;
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
			callCommand(commandList[i].name);
		}
	}

	printf("%s %s %s %s",part1,part2,part3,part4);

	return 0;
}

void printhelp(void)
{
	printf("Available commands:\n");

	for(int i = 0; i < 4; i++)
	{
		printf("	%s %s: %s\n",commandList[i].name,commandList[i].args,commandList[i].description);
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


