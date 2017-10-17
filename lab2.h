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

/* global variables, beware */
extern matlab_var_t vars[6];
extern matlab_arr_t arrs[6];


/* function declarations */
int processLine(const char *line);

matlab_var_t *find_var(char var);
matlab_arr_t *find_arr(char var);

int array(char name, double start, double stop);
int show(char name);
int calc(char r, char x,char y, char op);

#endif /* __LAB2_H__ */

