#include "../inc/init.h"

void init_prog() {  
	int i;
   	symbol_t* sp;
       
   	for (i = 0; Consts[i].CName != NULL;  i++) 
			sp = install(Consts[i].CName, CONST, (svalue_t) Consts[i].CValue);
   	for (i = 0; Predefs[i].CName != NULL; i++) {
			sp = install(Predefs[i].CName, PREDEF, (svalue_t) 0);
			sp->value.func = Predefs[i].CFunc;
		};
		for (i=0; Keywords[i].CName != NULL; i++) {
			sp = install(Keywords[i].CName, Keywords[i].Ctype, (svalue_t) 0);
			sp->value.func = Predefs[i].CFunc;
		}
}

// void if_code() {
// 	printf('Hello World !');
// }
