%top{
#include "parser.h"
#include <iostream>
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
"\n"                  ;
[ ]+                  ;
[0-9]+                return yy::parser::make_NUM(yytext);
"="                   return yy::parser::make_EQ(yytext);
":"                   return yy::parser::make_COL(yytext);
"["                   return yy::parser::make_BRKOPN(yytext);
"]"                   return yy::parser::make_BRKCLS(yytext);
"("                   return yy::parser::make_PAROPN(yytext);
")"                   return yy::parser::make_PARCLS(yytext);
"{"                   return yy::parser::make_CUROPN(yytext);
"}"                   return yy::parser::make_CURCLS(yytext);
";"                   return yy::parser::make_SEMCOL(yytext);
","                   return yy::parser::make_COM(yytext);
"+"                   return yy::parser::make_PLUS(yytext);
"-"                   return yy::parser::make_MINUS(yytext);
"*"                   return yy::parser::make_MULT(yytext);
"/"                   return yy::parser::make_DIV(yytext);
"^"                   return yy::parser::make_POW(yytext);
"%"                   return yy::parser::make_MOD(yytext);
"<"                   return yy::parser::make_LESS(yytext);
">"                   return yy::parser::make_GREAT(yytext);
"<="                  return yy::parser::make_LESSEQ(yytext);
">="                  return yy::parser::make_GREATEQ(yytext);
"=="                  return yy::parser::make_EQEQ(yytext);
"~="                  return yy::parser::make_NOTEQ(yytext);
"in"                  return yy::parser::make_IN(yytext);
"nil"                 return yy::parser::make_NIL(yytext);
"and"                 return yy::parser::make_AND(yytext);
"or"                  return yy::parser::make_OR(yytext);
"not"                 return yy::parser::make_NOT(yytext);
"while"               return yy::parser::make_WHILE(yytext);
"for"                 return yy::parser::make_FOR(yytext);
"do"                  return yy::parser::make_DO(yytext);
"end"                 return yy::parser::make__END(yytext);
"if"                  return yy::parser::make_IF(yytext);
"else"                return yy::parser::make_ELSE(yytext);
"elseif"              return yy::parser::make_ELSEIF(yytext);
"then"                return yy::parser::make_THEN(yytext);
"return"              return yy::parser::make_RETURN(yytext);
"break"               return yy::parser::make_BREAK(yytext);
"false"               return yy::parser::make__FALSE(yytext);
"true"                return yy::parser::make__TRUE(yytext);
"local"               return yy::parser::make_LOCAL(yytext);
"until"               return yy::parser::make_UNTIL(yytext);
"repeat"              return yy::parser::make_REP(yytext);
"function"            return yy::parser::make_FUNC(yytext);
"#"                   return yy::parser::make_HASH(yytext);
"."                   return yy::parser::make_DOT(yytext);
".."                  return yy::parser::make_DDOT(yytext);
"..."                 return yy::parser::make_TRIDOT(yytext);
\"([^"]|\\.)*\"       return yy::parser::make_STR(yytext);
[a-zA-Z][a-zA-Z0-9_]*  return yy::parser::make_NAME(yytext);
<<EOF>>               return yy::parser::make_END();
%%
