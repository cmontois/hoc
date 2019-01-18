#ifndef _CALC_H_
#define _CALC_H_

#include "symbol.h"
#include "code.h"
#include "num.h"
#include "error.h"
#include "init.h"

int yylex();

extern insmac_t prog[];
extern insmac_t* prog_ptr;
extern insmac_t* current_ptr;

#endif