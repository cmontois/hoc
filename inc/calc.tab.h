/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EXIT = 258,
     SYMBOLS = 259,
     PROG = 260,
     STACK = 261,
     NL = 262,
     ADD = 263,
     SUB = 264,
     MUL = 265,
     DIV = 266,
     POW = 267,
     MOD = 268,
     ASG = 269,
     NOT = 270,
     AND = 271,
     OR = 272,
     SUP = 273,
     INF = 274,
     SEQ = 275,
     IEQ = 276,
     EQ = 277,
     NEQ = 278,
     AO = 279,
     AF = 280,
     PV = 281,
     INT = 282,
     FLOAT = 283,
     UNDEF = 284,
     VINT = 285,
     VFLOAT = 286,
     CONST = 287,
     PREDEF = 288,
     BOOL = 289,
     VBOOL = 290,
     IF = 291,
     ELSE = 292,
     XOR = 293,
     NON = 294,
     MINUS = 295
   };
#endif
/* Tokens.  */
#define EXIT 258
#define SYMBOLS 259
#define PROG 260
#define STACK 261
#define NL 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define POW 267
#define MOD 268
#define ASG 269
#define NOT 270
#define AND 271
#define OR 272
#define SUP 273
#define INF 274
#define SEQ 275
#define IEQ 276
#define EQ 277
#define NEQ 278
#define AO 279
#define AF 280
#define PV 281
#define INT 282
#define FLOAT 283
#define UNDEF 284
#define VINT 285
#define VFLOAT 286
#define CONST 287
#define PREDEF 288
#define BOOL 289
#define VBOOL 290
#define IF 291
#define ELSE 292
#define XOR 293
#define NON 294
#define MINUS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 5 "src/calc.y"
{symbol_t* symbol;}
/* Line 1529 of yacc.c.  */
#line 131 "inc/calc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

