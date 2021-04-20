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
    ID = 259,                      /* ID  */
    RETURN = 260,                  /* RETURN  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    WRITE = 264,                   /* WRITE  */
    WRITELN = 265,                 /* WRITELN  */
    READ = 266,                    /* READ  */
    EXISTS = 267,                  /* EXISTS  */
    ADD = 268,                     /* ADD  */
    REMOVE = 269,                  /* REMOVE  */
    FOR = 270,                     /* FOR  */
    FORALL = 271,                  /* FORALL  */
    IN = 272,                      /* IN  */
    IS_IN = 273,                   /* IS_IN  */
    IS_SET = 274,                  /* IS_SET  */
    OR = 275,                      /* OR  */
    CLE = 276,                     /* CLE  */
    CLT = 277,                     /* CLT  */
    CNE = 278,                     /* CNE  */
    CGT = 279,                     /* CGT  */
    AND = 280,                     /* AND  */
    CEQ = 281,                     /* CEQ  */
    CGE = 282,                     /* CGE  */
    DIGIT = 283,                   /* DIGIT  */
    LETTER = 284,                  /* LETTER  */
    STRING = 285,                  /* STRING  */
    APOST = 286,                   /* APOST  */
    CHAVES_INI = 287,              /* CHAVES_INI  */
    CHAVES_FIM = 288,              /* CHAVES_FIM  */
    PARENTESES_INI = 289,          /* PARENTESES_INI  */
    PARENTESES_FIM = 290,          /* PARENTESES_FIM  */
    EMPTY = 291,                   /* EMPTY  */
    SEMICOLON = 292,               /* SEMICOLON  */
    EQUALS = 293,                  /* EQUALS  */
    COLON = 294                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "skylang.y"

	char *str;
	struct node* tree;

#line 108 "skylang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SKYLANG_TAB_H_INCLUDED  */
