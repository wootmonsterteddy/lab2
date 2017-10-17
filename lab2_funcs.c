/*
 * lab2_funcs.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"


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
