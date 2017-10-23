#ifndef __LAB2_FUNCS_H__
#define __LAB2_FUNCS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include "lab2.h"


// add all other functions below
int clear(char var);
int calc(char r, char x, char y, char op);
int processLine(const char *line);
void printhelp(void);
void readLine(void);
void init(void);
void callCommand(char *input1,char *input2,char *input3,char *input4);
void set (char var, double v);
int failCheck(char var);
void importCSV(const char *var,const char *filename)

#endif /* __LAB2_FUNCS_H__ */
