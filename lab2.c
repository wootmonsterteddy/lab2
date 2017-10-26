/*
 * lab2.c
 *
 *  Created on: 13 okt. 2017
 *      Author: Erik, Nicklas
 */

#include "lab2_funcs.h"

/*TODO:
- means done
* not done

Lab1 Ex3:
help -
quit -
exit -
______________________

Lab2 Ex1:
find_var -
find_arr -
clear -
set -
show -
array -
______________________

Lab2 Ex2:
calc *
show_vars() -
______________________

Lab2 Ex3:
showCSV -
importCSV -
exportCSV -
______________________

Lab2 Ex4:

sin -
exportMAT *
debounce -
event *

*/

int main(int argc, char *argv[])
{
	init();

	while(argc == 1)
	{
		readLine();
	}

	return 0;
}
