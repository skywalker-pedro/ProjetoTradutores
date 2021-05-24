/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SKYLANG_TAB_H_INCLUDED
# define YY_YY_SKYLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE = 258,                    /* TYPE  */
    CLE = 259,                     /* CLE  */
    CLT = 260,                     /* CLT  */
    CNE = 261,                     /* CNE  */
    CGT = 262,                     /* CGT  */
    AND = 263,                     /* AND  */
    CEQ = 264,                     /* CEQ  */
    CGE = 265,                     /* CGE  */
    ID = 266,                      /* ID  */
    INTEGER = 267,                 /* INTEGER  */
    FLOAT = 268,                   /* FLOAT  */
    CHAR = 269,                    /* CHAR  */
    STRING = 270,                  /* STRING  */
    EMPTY = 271,                   /* EMPTY  */
    RETURN = 272,                  /* RETURN  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    WHILE = 275,                   /* WHILE  */
    WRITE = 276,                   /* WRITE  */
    WRITELN = 277,                 /* WRITELN  */
    READ = 278,                    /* READ  */
    EXISTS = 279,                  /* EXISTS  */
    ADD = 280,                     /* ADD  */
    REMOVE = 281,                  /* REMOVE  */
    FOR = 282,                     /* FOR  */
    FORALL = 283,                  /* FORALL  */
    IN = 284,                      /* IN  */
    IS_SET = 285,                  /* IS_SET  */
    OR = 286,                      /* OR  */
    NEGATION = 287,                /* NEGATION  */
    EQUALS = 288,                  /* EQUALS  */
    APOST = 289,                   /* APOST  */
    CHAVES_INI = 290,              /* CHAVES_INI  */
    CHAVES_FIM = 291,              /* CHAVES_FIM  */
    PARENTESES_INI = 292,          /* PARENTESES_INI  */
    PARENTESES_FIM = 293,          /* PARENTESES_FIM  */
    SEMICOLON = 294,               /* SEMICOLON  */
    COLON = 295,                   /* COLON  */
    PLUS = 296,                    /* PLUS  */
    MINUS = 297,                   /* MINUS  */
    MULT = 298,                    /* MULT  */
    DIV = 299,                     /* DIV  */
    THEN = 300                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 273 "skylang.y"

	char *str;
	struct node* tree;

#line 114 "skylang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SKYLANG_TAB_H_INCLUDED  */
