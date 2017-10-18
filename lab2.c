/*
 * lab2.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

struct commands commandList[20] =
{
		{"exit", 		1},
		{"quit",		2},
		{"help",		3},
};

int processLine(const char *line)
{
	char part1[20] = {0},part2[20] = {0},part3[20] = {0},part4[20] = {0};
	int partCounter = 1, i = 0,n = 0;

	while(line[i] != '\0') //Go through the input string
	{
		if(line[i] == ' ') //Space separates the parts
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
	}

	printf("%s %s %s %s",part1,part2,part3,part4);

	return 0;
}

int main(int argc, char *argv[])
{
	char input[20];

	printf(">> ");
	fgets(input,20,stdin);

	processLine(input);


	return 0;
}
