#ifndef __LAB2_H__
#define __LAB2_H__

#define ARRAY_LEN	50

/* new data types */
typedef struct var {
  char n;
  double v;
} matlab_var_t;

typedef struct arr {
  char n;
  double v[ARRAY_LEN];
} matlab_arr_t;

//Prepare global variables
struct var a,b,c,r,x,y;
struct arr A,B,C,R,X,Y;

/* global variables, beware */
extern matlab_var_t vars[6];
extern matlab_arr_t arrs[6];


/* function declarations */
int processLine(const char *line);

matlab_var_t *find_var(char var);
matlab_arr_t *find_arr(char var);

//Defining struct for commands
struct commandList
{
	char* name;
	int n;
};
struct commandList commands[100] =
{
		{"help",		1},
		{"set",			2},
		{"sin",			3},
		{"show",		4},
		{"showFile",	5},
		{"deleteFile",	6},
		{"importCSV",	7},
		{"exportCSV",	8},
		{"exportMAT",	9},
		{"exportJSON", 	10},
		{"exportXML", 	11},
		{"quit",		12},
		{"exit",		13},
		{"exit x",	 	14},
};

//function definitions
int array(char name, double start, double stop);
int show(char name);
int calc(char r, char x,char y, char op);

#endif /* __LAB2_H__ */

