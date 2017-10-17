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
	printf("%s",line);

	return 0;
}

int main(int argc, char *argv[])
{


	return 0;
}
