#ifndef _INIT_H_
#define _INIT_H_

#include <math.h>
#include "symbol.h"
#include "calc.tab.h"
#include "code.h"


static struct {char *CName; double CValue;} Consts[] = {
	"PI",     3.14159265358979323846,
  "E",      2.71828182845904523536,
  "GAMMA",  0.57721566490153286060,
  "DEG",   	57.29577951308232087680,
  "PHI",    1.61803398874989484820,
  NULL,     0
};

static struct {char *CName; double (*CFunc)();} Predefs[] = {
  	"sin", 		sin,
  	"cos",  	cos,
		"tan",		tan,
		"abs",  	fabs,
		"log",  	log,    
		"log10", 	log10,    
		"exp",  	exp,
		"sqrt", 	sqrt,
		0,      	0
};

static struct {char *CName; short Ctype; void (*CFunc)();} Keywords[] = {
	"else",	ELSE, STOP,
	"if",	  IF, 	if_code,
};

void init_prog();
void if_code();
#endif