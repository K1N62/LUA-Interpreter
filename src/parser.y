%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%code requires {
  #include "Node.h"
  using namespace std;
}
%code {
  #include <string>
  #include <iostream>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node root;
}
%token <std::string> WS NL SEMCOL STR NUM EQ COM DOT COL BRKOPN BRKCLS TRIDOT PAROPN PARCLS CUROPN CURCLS NAME FUNC
%token <std::string> PLUS MINUS MULT DIV POW MOD DDOT LESS GREAT LESSEQ GREATEQ EQEQ NOTEQ AND OR NOT HASH
%token <std::string> WHILE FOR DO IF ELSE ELSEIF THEN RETURN BREAK _FALSE _TRUE _END IN LOCAL NIL REP UNTIL
%type <Node> chunk block stat laststat funcname varlist var namelist explist tableconstructor parlist
%type <Node> exp prefixexp functioncall args function funcbody fieldlist field fieldsep binop unop
%type <Node> rep_func_name rep_var rep_list_name rep_exp rep_elseif rep_stat rep_field
%type <Node> opt_explist opt_parlist opt_tridot opt_fieldlist opt_fieldsep opt_semi opt_laststat opt_exp opt_else opt_eq opt_name
%token END 0 "end of file"
%%

chunk         : /* EMPTY */                                         { $$ = Node(); }
              | rep_stat opt_laststat                               { $$ = $1; if (!$2.isUndefined()) $$.addChild($2); root = $$; }
              ;

block         : chunk                                               { $$ = $1; }
              ;

stat          : varlist EQ explist                                  {
                                                                      $$ = Node(Node::Type::Equal);
                                                                      $$.addChild($1);
                                                                      $$.addChild($3);
                                                                    }
              | functioncall                                        { $$ = $1; }
              | DO block _END                                       { $$ = Node(); }
              | WHILE exp DO block _END                             {
                                                                      $$ = Node(Node::Type::While);
                                                                      $$.addChild($2);
                                                                      $$.addChild($4);
                                                                    }
              | REP block UNTIL exp                                 {
                                                                      $$ = Node(Node::Type::Repeat);
                                                                      $$.addChild($2);
                                                                      $$.addChild($4);
                                                                    }
              | IF exp THEN block rep_elseif opt_else _END          {
                                                                      $$ = Node(Node::Type::If);
                                                                      $$.addChild($2);
                                                                      $$.addChild($4);
                                                                      if ($5.size() != 0)
                                                                        $$.addChild($5);
                                                                      if (!$6.isUndefined())
                                                                        $$.addChild($6);
                                                                    }
              | FOR NAME EQ exp COM exp opt_exp DO block _END       {
                                                                      $$ = Node(Node::Type::For);
                                                                      Node name = Node(Node::Type::Name, $2);
                                                                      $$.addChild(name);
                                                                      $$.addChild($4);
                                                                      $$.addChild($6);
                                                                      if (!$7.isUndefined())
                                                                        $$.addChild($7);
                                                                      $$.addChild($9);
                                                                    }
              | FOR namelist IN explist DO block _END               { $$ = Node(); }
              | FUNC funcname funcbody                              {
                                                                      $$ = Node(Node::Type::Function);
                                                                      $$.addChild($2);
                                                                      $$.addChild($3);
                                                                    }
              | LOCAL FUNC NAME funcbody                            { $$ = Node(); }
              | LOCAL namelist opt_eq                               { $$ = Node(); }
              ;

laststat      : RETURN opt_explist                                  { $$ = $2; }
              | BREAK                                               { $$ = Node(); }
              ;

funcname      : NAME rep_func_name opt_name                         {
                                                                      $$ = Node(Node::Type::FunctionName);
                                                                      Node name = Node(Node::Type::Name, $1);
                                                                      $$.addChild(name);
                                                                      if ($2.size() > 0)
                                                                        $$.addChild($2);
                                                                      if (!$3.isUndefined())
                                                                        $$.addChild($3);
                                                                    }
              ;

varlist       : var rep_var                                         {
                                                                      if ($2.size() == 0) {
                                                                        $$ = $1;
                                                                      } else {
                                                                        $$ = $2;
                                                                        $$.addChild($1);
                                                                      }
                                                                    }
              ;

var           : NAME                                                { $$ = Node(Node::Type::Name, $1); }
              | prefixexp BRKOPN exp BRKCLS                         {
                                                                      $$ = Node(Node::Type::MemberFunction);
                                                                      $$.addChild($1);
                                                                      $$.addChild($3);
                                                                    }
              | prefixexp DOT NAME                                  {
                                                                      $$ = Node(Node::Type::MemberVariable);
                                                                      Node name = Node(Node::Type::Name, $3);
                                                                      $$.addChild($1);
                                                                      $$.addChild(name);
                                                                    }
              ;

namelist      : NAME rep_list_name                                  {
                                                                      Node name = Node(Node::Type::Name, $1);
                                                                      $$ = Node(Node::Type::ListName);
                                                                      $$.addChild(name);
                                                                      if ($2.size() != 0)
                                                                        $$.addChild($2);
                                                                    }
              ;

explist       : rep_exp exp                                         {
                                                                      if ($1.size() != 0) {
                                                                        $$ = $1;
                                                                        $$.addChild($2);
                                                                      } else {
                                                                        $$ = $2;
                                                                      }
                                                                    }
              ;

exp           : NIL                                                 { $$ = Node(Node::Type::Nil, "Nil"); }
              | _FALSE                                              { $$ = Node(Node::Type::False, "false"); }
              | _TRUE                                               { $$ = Node(Node::Type::True, "true"); }
              | NUM                                                 { $$ = Node(Node::Type::Number, $1); }
              | STR                                                 {
                                                                      $1.erase(0,1);
                                                                      $1.erase($1.length() - 1, 1);
                                                                      $$ = Node(Node::Type::String, $1);
                                                                    }
              | TRIDOT                                              { $$ = Node(Node::Type::Tridot, "..."); }
              | function                                            { $$ = $1; }
              | prefixexp                                           { $$ = $1; }
              | tableconstructor                                    { $$ = $1; }
              | exp binop exp                                       {
                                                                      $$ = $2;
                                                                      $$.addChild($1);
                                                                      $$.addChild($3);
                                                                    }
              | unop exp                                            {
                                                                      $$ = $1;
                                                                      $$.addChild($2);
                                                                    }
              ;

prefixexp     : var                                                 { $$ = $1; }
              | functioncall                                        { $$ = $1; }
              | PAROPN exp PARCLS                                   { $$ = $2; }
              ;

functioncall  : prefixexp args                                      {
                                                                      $$ = Node(Node::Type::FunctionCall);
                                                                      $$.addChild($1);
                                                                      $$.addChild($2);
                                                                    }
              | prefixexp COL NAME args                             {
                                                                      $$ = $1;
                                                                      Node name = Node(Node::Type::Name, $3);
                                                                      $$.addChild(name);
                                                                      $$.addChild($4);
                                                                    }
              ;

args          : PAROPN opt_explist PARCLS                           { $$ = $2; }
              | tableconstructor                                    { $$ = $1; }
              | STR                                                 { $$ = Node(Node::Type::String, $1); }
              ;

function      : FUNC funcbody                                       { $$ = $2; }
              ;

funcbody      : PAROPN opt_parlist PARCLS block _END                {
                                                                      $$ = Node(Node::Type::FunctionBody);
                                                                      if (!$2.isUndefined())
                                                                        $$.addChild($2);
                                                                      $$.addChild($4);
                                                                    }
              ;

parlist       : namelist opt_tridot                                 { $$ = Node(); }
              | TRIDOT                                              { $$ = Node(Node::Type::Tridot); }
              ;

tableconstructor  : CUROPN opt_fieldlist CURCLS                     { $$ = $2; }
                  ;

fieldlist     : field rep_field opt_fieldsep                        { $$ = Node(); }
              ;

field         : BRKOPN exp BRKCLS EQ exp                            { $$ = Node(); }
              | NAME EQ exp                                         {
                                                                      $$ = Node(Node::Type::Equal);
                                                                      Node name = Node(Node::Type::Name, $1);
                                                                      $$.addChild(name); $$.addChild($3);
                                                                    }
              | exp                                                 { $$ = $1; }
              ;

fieldsep      : COM                                                 { $$ = Node(Node::Type::Comma); }
              | SEMCOL                                              { $$ = Node(Node::Type::SemiColon); }
              ;

binop         : PLUS                                                { $$ = Node(Node::Type::Addition); }
              | MINUS                                               { $$ = Node(Node::Type::Subtraction); }
              | DIV                                                 { $$ = Node(Node::Type::Division); }
              | MULT                                                { $$ = Node(Node::Type::Multiplication); }
              | POW                                                 { $$ = Node(Node::Type::Power); }
              | MOD                                                 { $$ = Node(Node::Type::Modulo); }
              | DDOT                                                { $$ = Node(Node::Type::DoubleDot); }
              | LESS                                                { $$ = Node(Node::Type::LessThan); }
              | LESSEQ                                              { $$ = Node(Node::Type::LessOrEq); }
              | GREAT                                               { $$ = Node(Node::Type::GreaterThan); }
              | GREATEQ                                             { $$ = Node(Node::Type::GreaterOrEq); }
              | EQEQ                                                { $$ = Node(Node::Type::Test); }
              | NOTEQ                                               { $$ = Node(Node::Type::NotEq); }
              | AND                                                 { $$ = Node(Node::Type::And); }
              | OR                                                  { $$ = Node(Node::Type::Or); }
              ;

unop          : MINUS                                               { $$ = Node(Node::Type::Subtraction); }
              | NOT                                                 { $$ = Node(Node::Type::Not); }
              | HASH                                                { $$ = Node(Node::Type::Hash); }
              ;

rep_func_name : /* EMPTY */                                         { $$ = Node(Node::Type::FunctionName); }
              | rep_func_name DOT NAME                              {
                                                                      $$ = $1;
                                                                      Node name = Node(Node::Type::Name, $3);
                                                                      $$.addChild(name);
                                                                    }
              ;

rep_var       : /* EMPTY */                                         { $$ = Node(Node::Type::VariableList); }
              | rep_var COM var                                     { $$ = $1; $$.addChild($3); }
              ;

rep_list_name : /* EMPTY */                                         { $$ = Node(Node::Type::ListName); }
              | rep_list_name COM NAME                              {
                                                                      $$ = $1;
                                                                      Node name = Node(Node::Type::Name, $3);
                                                                      $$.addChild(name);
                                                                    }
              ;

rep_exp       : /* EMPTY */                                         { $$ = Node(Node::Type::ExpressionList); }
              | rep_exp exp COM                                     { $$ = $1; $$.addChild($2); }
              ;

rep_elseif    : /* EMPTY */                                         { $$ = Node(Node::Type::ElseIf); }
              | rep_elseif ELSEIF exp THEN block                    { $$ = $1; $$.addChild($3); $$.addChild($5); }
              ;

rep_stat      : /* EMPTY */                                         { $$ = Node(Node::Type::Stat); }
              | rep_stat stat opt_semi                              { $$ = $1; $$.addChild($2); }
              ;

rep_field     : /* EMPTY */                                         { $$ = Node(Node::Type::Field); }
              | rep_field fieldsep field                            { $$ = $1; $$.addChild($2); }
              ;

opt_explist   : /* EMPTY */                                         { $$ = Node(); }
              | explist                                             { $$ = $1; }
              ;

opt_parlist   : /* EMPTY */                                         { $$ = Node(); }
              | parlist                                             { $$ = $1; }
              ;

opt_name      : /* EMPTY */                                         { $$ = Node(); }
              | COL NAME                                            { Node name = Node(Node::Type::Name, $2); $$ = name; }
              ;

opt_tridot    : /* EMPTY */                                         { $$ = Node(); }
              | COM TRIDOT                                          { $$ = Node(Node::Type::Tridot); }
              ;

opt_fieldlist : /* EMPTY */                                         { $$ = Node(); }
              | fieldlist                                           { $$ = $1; }
              ;

opt_fieldsep  : /* EMPTY */                                         { $$ = Node(); }
              | fieldsep                                            { $$ = $1; }
              ;

opt_semi      : /* EMPTY */                                         { $$ = Node(); }
              | SEMCOL                                              { $$ = Node(Node::Type::SemiColon); }
              ;

opt_laststat  : /* EMPTY */                                         { $$ = Node(); }
              | laststat opt_semi                                   { $$ = $1; }
              ;

opt_exp       : /* EMPTY */                                         { $$ = Node(); }
              | COM exp                                             { $$ = $2; }
              ;

opt_else      : /* EMPTY */                                         { $$ = Node(); }
              | ELSE block                                          { $$ = $2; }
              ;

opt_eq        : /* EMPTY */                                         { $$ = Node(); }
              | EQ explist                                          { $$ = $2; }
              ;
