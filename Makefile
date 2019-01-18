DEBUG ?= 1
AUTOCLEAN ?= 1

# Paths
DSRC = src
DINC = inc
DOBJ = obj


# Compiler Flags
CFLAGS = -I $(DINC)
LIBRARIES = -ll -ly

ifeq ($(DEBUG), 1)
	CFLAGS += -D DEBUG
endif

ifeq ($(AUTOCLEAN), 1)
	CFLAGS += -D AUTOCLEAN
endif


# Commands
CC = gcc $(CFLAGS)
LEX = lex -I
YACC = bison -d

# Objects
OBJS = \
$(DOBJ)/calc.o \
$(DOBJ)/calc.l.o \
$(DOBJ)/init.o \
$(DOBJ)/code.o \
$(DOBJ)/data.o \
$(DOBJ)/error.o \
$(DOBJ)/symbol.o \
$(DOBJ)/num.o \
$(DOBJ)/bool.o


all: calc

calc: $(OBJS)
	$(CC) $(OBJS) $(LIBRARIES) -o calc

$(DOBJ)/calc.o: $(DINC)/calc.h $(DSRC)/calc.y $(DOBJ)/code.o $(DOBJ)/error.o $(DOBJ)/init.o $(DOBJ)/symbol.o $(DOBJ)/num.o $(DOBJ)/bool.o
	$(YACC) $(DSRC)/calc.y -o $(DINC)/calc.tab.c
	$(CC) -c $(DINC)/calc.tab.c -o $(DOBJ)/calc.o

$(DOBJ)/calc.l.o: $(DOBJ)/calc.o $(DINC)/calc.tab.h $(DSRC)/calc.l
	$(LEX) -o $(DINC)/lex.yy.c $(DSRC)/calc.l 
	$(CC) -c $(DINC)/lex.yy.c -o $(DOBJ)/calc.l.o

$(DOBJ)/init.o: $(DSRC)/init.c $(DINC)/init.h $(DOBJ)/symbol.o
	$(CC) -c $(DSRC)/init.c -o $(DOBJ)/init.o

$(DOBJ)/code.o: $(DSRC)/code.c $(DINC)/code.h $(DOBJ)/data.o $(DOBJ)/symbol.o $(DOBJ)/num.o
	$(CC) -c $(DSRC)/code.c -o $(DOBJ)/code.o

$(DOBJ)/num.o: $(DSRC)/num.c $(DINC)/num.h $(DOBJ)/data.o
	$(CC) -c $(DSRC)/num.c -o $(DOBJ)/num.o

$(DOBJ)/bool.o: $(DSRC)/bool.c $(DINC)/bool.h $(DOBJ)/data.o
	$(CC) -c $(DSRC)/bool.c -o $(DOBJ)/bool.o

$(DOBJ)/data.o: $(DSRC)/data.c $(DINC)/data.h $(DOBJ)/symbol.o
	$(CC) -c $(DSRC)/data.c -o $(DOBJ)/data.o
	
$(DOBJ)/error.o: $(DSRC)/error.c $(DINC)/error.h
	$(CC) -c $(DSRC)/error.c -o $(DOBJ)/error.o

$(DOBJ)/symbol.o: $(DSRC)/symbol.c $(DINC)/symbol.h $(DINC)/color.h
	$(CC) -c $(DSRC)/symbol.c -o $(DOBJ)/symbol.o

clean:
	rm -f $(OBJS) calc