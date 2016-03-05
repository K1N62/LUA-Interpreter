%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%code requires {
  #include "Node.h"
  #include "Test.h"
  #include "Loop.h"
  #include "Binop.h"
  #include "Memory.h"
  #include "Condition.h"
  #include "Environment.h"
  using namespace std;
}
%code {
  #include <string>
  #include <iostream>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  Environment env;
}

%token <string> STR NUM NAME

%token WHILE FOR DO IF ELSE ELSEIF THEN RETURN BREAK _FALSE _TRUE _END IN LOCAL NIL REP UNTIL SEMCOL
%token EQ COM DOT COL BRKOPN BRKCLS TRIDOT PAROPN PARCLS CUROPN CURCLS FUNC

%left OR
%left AND
%left LESS GREAT LESSEQ GREATEQ EQEQ NOTEQ
%right DDOT
%left PLUS MINUS
%left MULT DIV MOD
%left NOT HASH
%right POW

%type <Node*> chunk block stat laststat funcname varlist var namelist explist tableconstructor parlist
%type <Node*> exp prefixexp functioncall args function funcbody fieldlist field fieldsep
%type <Node*> rep_func_name rep_var rep_list_name rep_exp rep_elseif rep_stat rep_field
%type <Node*> opt_explist opt_parlist opt_tridot opt_fieldlist opt_fieldsep opt_semi opt_laststat opt_exp opt_else opt_eq opt_name

%token END 0 "end of file"

%%

chunk         : /* EMPTY */                                         { $$ = NULL; }
              | rep_stat opt_laststat                               {
                                                                      $$ = $1;
                                                                      if ($2 != NULL )
                                                                        $$->addChild($2);
                                                                      root = $$;
                                                                    }
              ;

block         : chunk                                               { $$ = $1; }
              ;

stat          : varlist EQ explist                                  {
                                                                      $$ = new Binop(Binop::Type::Equal);
                                                                      $$->addChild($1);
                                                                      $$->addChild($3);
                                                                    }
              | functioncall                                        { $$ = $1; }
              | DO block _END                                       {
                                                                      $$ = new Loop(Loop::Type::Do);
                                                                      $$->addChild($2);
                                                                    }
              | WHILE exp DO block _END                             {
                                                                      $$ = new Loop(Loop::Type::While);
                                                                      $$->addChild($2);
                                                                      $$->addChild($4);
                                                                    }
              | REP block UNTIL exp                                 {
                                                                      $$ = new Loop(Loop::Type::Repeat);
                                                                      $$->addChild($2);
                                                                      $$->addChild($4);
                                                                    }
              | IF exp THEN block rep_elseif opt_else _END          {
                                                                      $$ = new Condition(Condition::Type::If);
                                                                      $$->addChild($2);
                                                                      $$->addChild($4);
                                                                      if ($5->size() != 0)
                                                                        $$->addChild($5);
                                                                      if ($6 != NULL )
                                                                        $$->addChild($6);
                                                                    }
              | FOR NAME EQ exp COM exp opt_exp DO block _END       {
                                                                      $$ = new Loop(Loop::Type::For);
                                                                      $$->addChild(new Node(Node::Type::Name, $2));
                                                                      $$->addChild($4);
                                                                      $$->addChild($6);
                                                                      if ($7 != NULL )
                                                                        $$->addChild($7);
                                                                      $$->addChild($9);
                                                                    }
              | FOR namelist IN explist DO block _END               {
                                                                      $$ = new Loop(Loop::Type::For);
                                                                      $$->addChild($2);
                                                                      $$->addChild($4);
                                                                      $$->addChild($6);
                                                                    }
              | FUNC funcname funcbody                              {
                                                                      $$ = new Node(Node::Type::Function);
                                                                      $$->addChild($2);
                                                                      $$->addChild($3);
                                                                    }
              | LOCAL FUNC NAME funcbody                            { $$ = NULL; }
              | LOCAL namelist opt_eq                               { $$ = NULL; }
              ;

laststat      : RETURN opt_explist                                  {
                                                                      $$ = new Node(Node::Type::Return);
                                                                      $$->addChild($2);
                                                                    }
              | BREAK                                               { $$ = NULL; }
              ;

funcname      : NAME rep_func_name opt_name                         {
                                                                      $$ = $2;
                                                                      $$->addChild(new Node(Node::Type::Name, $1));
                                                                      if ($3 != NULL )
                                                                        $$->addChild($3);
                                                                    }
              ;

varlist       : var rep_var                                         {
                                                                      if ($2->size() == 0) {
                                                                        $$ = $1;
                                                                      } else {
                                                                        $$ = $2;
                                                                        $$->addChild($1);
                                                                      }
                                                                    }
              ;

var           : NAME                                                { $$ = new Node(Node::Type::Name, $1); }
              | prefixexp BRKOPN exp BRKCLS                         {
                                                                      $$ = new Node(Node::Type::FieldElement);
                                                                      $$->addChild($1);
                                                                      $$->addChild($3);
                                                                    }
              | prefixexp DOT NAME                                  {
                                                                      $$ = new Node(Node::Type::MemberFunction);
                                                                      $$->addChild($1);
                                                                      $$->addChild(new Node(Node::Type::Name, $3));
                                                                    }
              ;

namelist      : NAME rep_list_name                                  {
                                                                      if ($2->size() != 0) {
                                                                        $$ = $2;
                                                                        $$->addChild(new Node(Node::Type::Name, $1));
                                                                      } else {
                                                                        $$ = new Node(Node::Type::ListName);
                                                                        $$->addChild(new Node(Node::Type::Name, $1));
                                                                      }
                                                                    }
              ;

explist       : rep_exp exp                                         {
                                                                      if ($1->size() != 0) {
                                                                        $$ = $1;
                                                                        $$->addChild($2);
                                                                      } else {
                                                                        $$ = $2;
                                                                      }
                                                                    }
              ;

exp           : NIL                                                 { $$ = new Memory(Memory::Type::Nil); }
              | _FALSE                                              { $$ = new Test(Test::Type::False); }
              | _TRUE                                               { $$ = new Test(Test::Type::True); }
              | NUM                                                 { $$ = new Memory(stoi($1)); }
              | STR                                                 {
                                                                      $1.erase(0,1);
                                                                      $1.erase($1.length() - 1, 1);
                                                                      $$ = new Memory($1);
                                                                    }
              | TRIDOT                                              { $$ = new Node(Node::Type::Tridot, "..."); }
              | function                                            { $$ = $1; }
              | prefixexp                                           { $$ = $1; }
              | tableconstructor                                    { $$ = $1; }
              | exp DDOT exp                                        { $$ = new Node(Node::Type::DoubleDot); $$->addChild($1); $$->addChild($3); }
              | exp PLUS exp                                        { $$ = new Binop(Binop::Type::Addition); $$->addChild($1); $$->addChild($3); }
              | exp MINUS exp                                       { $$ = new Binop(Binop::Type::Subtraction); $$->addChild($1); $$->addChild($3); }
              | exp DIV exp                                         { $$ = new Binop(Binop::Type::Division); $$->addChild($1); $$->addChild($3); }
              | exp MULT exp                                        { $$ = new Binop(Binop::Type::Multiplication); $$->addChild($1); $$->addChild($3); }
              | exp POW exp                                         { $$ = new Binop(Binop::Type::Power); $$->addChild($1); $$->addChild($3); }
              | exp MOD exp                                         { $$ = new Binop(Binop::Type::Modulo); $$->addChild($1); $$->addChild($3); }
              | exp LESS exp                                        { $$ = new Test(Test::Type::LessThan); $$->addChild($1); $$->addChild($3); }
              | exp LESSEQ exp                                      { $$ = new Test(Test::Type::LessOrEqual); $$->addChild($1); $$->addChild($3); }
              | exp GREAT exp                                       { $$ = new Test(Test::Type::GreaterThan); $$->addChild($1); $$->addChild($3); }
              | exp GREATEQ exp                                     { $$ = new Test(Test::Type::GreaterOrEqual); $$->addChild($1); $$->addChild($3); }
              | exp EQEQ exp                                        { $$ = new Test(Test::Type::EqualEqual); $$->addChild($1); $$->addChild($3); }
              | exp NOTEQ exp                                       { $$ = new Test(Test::Type::NotEqual); $$->addChild($1); $$->addChild($3); }
              | exp AND exp                                         { $$ = new Test(Test::Type::And); $$->addChild($1); $$->addChild($3); }
              | exp OR exp                                          { $$ = new Test(Test::Type::Or); $$->addChild($1); $$->addChild($3); }
              | NOT exp                                             { $$ = new Test(Test::Type::Not); $$->addChild($2); }
              | MINUS exp                                           { $$ = new Node(Node::Type::Negate); $$->addChild($2); }
              | HASH exp                                            { $$ = new Node(Node::Type::Hash); $$->addChild($2); }
              ;

prefixexp     : var                                                 { $$ = $1; }
              | functioncall                                        { $$ = $1; }
              | PAROPN exp PARCLS                                   { $$ = $2; }
              ;

functioncall  : prefixexp args                                      {
                                                                      $$ = new Node(Node::Type::FunctionCall);
                                                                      $$->addChild($1);
                                                                      $$->addChild($2);
                                                                    }
              | prefixexp COL NAME args                             {
                                                                      $$ = $1;
                                                                      $$->addChild(new Node(Node::Type::Name, $3));
                                                                      $$->addChild($4);
                                                                    }
              ;

args          : PAROPN opt_explist PARCLS                           { $$ = $2; }
              | tableconstructor                                    { $$ = $1; }
              | STR                                                 {
                                                                      $1.erase(0,1);
                                                                      $1.erase($1.length() - 1, 1);
                                                                      $$ = new Node(Node::Type::ExpressionList);
                                                                      $$->addChild(new Memory($1));
                                                                    }
              ;

function      : FUNC funcbody                                       { $$ = $2; }
              ;

funcbody      : PAROPN opt_parlist PARCLS block _END                {
                                                                      $$ = new Node(Node::Type::FunctionBody);
                                                                      if ($2 != NULL )
                                                                        $$->addChild($2);
                                                                      $$->addChild($4);
                                                                    }
              ;

parlist       : namelist opt_tridot                                 {
                                                                      $$ = $1;
                                                                      if ($2 != NULL )
                                                                        $$->addChild($2);
                                                                    }
              | TRIDOT                                              { $$ = new Node(Node::Type::Tridot); }
              ;

tableconstructor  : CUROPN opt_fieldlist CURCLS                     { $$ = $2; }
                  ;

fieldlist     : field rep_field opt_fieldsep                        {
                                                                      if ($2->size() != 0) {
                                                                        $$ = $2;
                                                                        $$->addChild($1);
                                                                        $$->moveToFront();
                                                                      } else {
                                                                        $$ = $1;
                                                                      }
                                                                    }
              ;

field         : BRKOPN exp BRKCLS EQ exp                            {
                                                                      $$ = new Binop(Binop::Type::Equal);
                                                                      $$->addChild($2);
                                                                      $$->addChild($5);
                                                                    }
              | NAME EQ exp                                         {
                                                                      $$ = new Binop(Binop::Type::Equal);
                                                                      $$->addChild(new Node(Node::Type::Name, $1));
                                                                      $$->addChild($3);
                                                                    }
              | exp                                                 { $$ = $1; }
              ;

fieldsep      : COM                                                 { $$ = NULL; }
              | SEMCOL                                              { $$ = NULL; }
              ;

rep_func_name : /* EMPTY */                                         { $$ = new Node(Node::Type::FunctionName); }
              | rep_func_name DOT NAME                              {
                                                                      $$ = $1;
                                                                      $$->addChild(new Node(Node::Type::Name, $3));
                                                                    }
              ;

rep_var       : /* EMPTY */                                         { $$ = new Node(Node::Type::VariableList); }
              | rep_var COM var                                     { $$ = $1; $$->addChild($3); }
              ;

rep_list_name : /* EMPTY */                                         { $$ = new Node(Node::Type::ListName); }
              | rep_list_name COM NAME                              {
                                                                      $$ = $1;
                                                                      $$->addChild(new Node(Node::Type::Name, $3));
                                                                    }
              ;

rep_exp       : /* EMPTY */                                         { $$ = new Node(Node::Type::ExpressionList); }
              | rep_exp exp COM                                     { $$ = $1; $$->addChild($2); }
              ;

rep_elseif    : /* EMPTY */                                         { $$ = new Condition(Condition::Type::ElseIf); }
              | rep_elseif ELSEIF exp THEN block                    { $$ = $1; $$->addChild($3); $$->addChild($5); }
              ;

rep_stat      : /* EMPTY */                                         { $$ = new Node(Node::Type::Stat); }
              | rep_stat stat opt_semi                              { $$ = $1; $$->addChild($2); }
              ;

rep_field     : /* EMPTY */                                         { $$ = new Memory(); }
              | rep_field fieldsep field                            { $$ = $1; $$->addChild($3); }
              ;

opt_explist   : /* EMPTY */                                         { $$ = NULL; }
              | explist                                             { $$ = $1; }
              ;

opt_parlist   : /* EMPTY */                                         { $$ = NULL; }
              | parlist                                             { $$ = $1; }
              ;

opt_name      : /* EMPTY */                                         { $$ = NULL; }
              | COL NAME                                            { $$ = new Node(Node::Type::Name, $2); }
              ;

opt_tridot    : /* EMPTY */                                         { $$ = NULL; }
              | COM TRIDOT                                          { $$ = new Node(Node::Type::Tridot); }
              ;

opt_fieldlist : /* EMPTY */                                         { $$ = new Memory(); }
              | fieldlist                                           { $$ = $1; }
              ;

opt_fieldsep  : /* EMPTY */                                         { $$ = NULL; }
              | fieldsep                                            { $$ = $1; }
              ;

opt_semi      : /* EMPTY */                                         { $$ = NULL; }
              | SEMCOL                                              { $$ = NULL; }
              ;

opt_laststat  : /* EMPTY */                                         { $$ = NULL; }
              | laststat opt_semi                                   { $$ = $1; }
              ;

opt_exp       : /* EMPTY */                                         { $$ = NULL; }
              | COM exp                                             { $$ = $2; }
              ;

opt_else      : /* EMPTY */                                         { $$ = NULL; }
              | ELSE block                                          { $$ = $2; }
              ;

opt_eq        : /* EMPTY */                                         { $$ = NULL; }
              | EQ explist                                          { $$ = $2; }
              ;
