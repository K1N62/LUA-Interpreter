// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "src/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.

#line 51 "src/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 9 "src/parser.y" // lalr1.cc:408

  #include <string>
  #include <iostream>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node root;

#line 62 "src/parser.cpp" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 129 "src/parser.cpp" // lalr1.cc:474

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // laststat
      case 60: // funcname
      case 61: // varlist
      case 62: // var
      case 63: // namelist
      case 64: // explist
      case 65: // exp
      case 66: // prefixexp
      case 67: // functioncall
      case 68: // args
      case 69: // function
      case 70: // funcbody
      case 71: // parlist
      case 72: // tableconstructor
      case 73: // fieldlist
      case 74: // field
      case 75: // fieldsep
      case 76: // binop
      case 77: // unop
      case 78: // rep_func_name
      case 79: // rep_var
      case 80: // rep_list_name
      case 81: // rep_exp
      case 82: // rep_elseif
      case 83: // rep_stat
      case 84: // rep_field
      case 85: // opt_explist
      case 86: // opt_parlist
      case 87: // opt_name
      case 88: // opt_tridot
      case 89: // opt_fieldlist
      case 90: // opt_fieldsep
      case 91: // opt_semi
      case 92: // opt_laststat
      case 93: // opt_exp
      case 94: // opt_else
      case 95: // opt_eq
        value.move< Node > (that.value);
        break;

      case 3: // WS
      case 4: // NL
      case 5: // SEMCOL
      case 6: // STR
      case 7: // NUM
      case 8: // EQ
      case 9: // COM
      case 10: // DOT
      case 11: // COL
      case 12: // BRKOPN
      case 13: // BRKCLS
      case 14: // TRIDOT
      case 15: // PAROPN
      case 16: // PARCLS
      case 17: // CUROPN
      case 18: // CURCLS
      case 19: // NAME
      case 20: // FUNC
      case 21: // PLUS
      case 22: // MINUS
      case 23: // MULT
      case 24: // DIV
      case 25: // POW
      case 26: // MOD
      case 27: // DDOT
      case 28: // LESS
      case 29: // GREAT
      case 30: // LESSEQ
      case 31: // GREATEQ
      case 32: // EQEQ
      case 33: // NOTEQ
      case 34: // AND
      case 35: // OR
      case 36: // NOT
      case 37: // HASH
      case 38: // WHILE
      case 39: // FOR
      case 40: // DO
      case 41: // IF
      case 42: // ELSE
      case 43: // ELSEIF
      case 44: // THEN
      case 45: // RETURN
      case 46: // BREAK
      case 47: // _FALSE
      case 48: // _TRUE
      case 49: // _END
      case 50: // IN
      case 51: // LOCAL
      case 52: // NIL
      case 53: // REP
      case 54: // UNTIL
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // laststat
      case 60: // funcname
      case 61: // varlist
      case 62: // var
      case 63: // namelist
      case 64: // explist
      case 65: // exp
      case 66: // prefixexp
      case 67: // functioncall
      case 68: // args
      case 69: // function
      case 70: // funcbody
      case 71: // parlist
      case 72: // tableconstructor
      case 73: // fieldlist
      case 74: // field
      case 75: // fieldsep
      case 76: // binop
      case 77: // unop
      case 78: // rep_func_name
      case 79: // rep_var
      case 80: // rep_list_name
      case 81: // rep_exp
      case 82: // rep_elseif
      case 83: // rep_stat
      case 84: // rep_field
      case 85: // opt_explist
      case 86: // opt_parlist
      case 87: // opt_name
      case 88: // opt_tridot
      case 89: // opt_fieldlist
      case 90: // opt_fieldsep
      case 91: // opt_semi
      case 92: // opt_laststat
      case 93: // opt_exp
      case 94: // opt_else
      case 95: // opt_eq
        value.copy< Node > (that.value);
        break;

      case 3: // WS
      case 4: // NL
      case 5: // SEMCOL
      case 6: // STR
      case 7: // NUM
      case 8: // EQ
      case 9: // COM
      case 10: // DOT
      case 11: // COL
      case 12: // BRKOPN
      case 13: // BRKCLS
      case 14: // TRIDOT
      case 15: // PAROPN
      case 16: // PARCLS
      case 17: // CUROPN
      case 18: // CURCLS
      case 19: // NAME
      case 20: // FUNC
      case 21: // PLUS
      case 22: // MINUS
      case 23: // MULT
      case 24: // DIV
      case 25: // POW
      case 26: // MOD
      case 27: // DDOT
      case 28: // LESS
      case 29: // GREAT
      case 30: // LESSEQ
      case 31: // GREATEQ
      case 32: // EQEQ
      case 33: // NOTEQ
      case 34: // AND
      case 35: // OR
      case 36: // NOT
      case 37: // HASH
      case 38: // WHILE
      case 39: // FOR
      case 40: // DO
      case 41: // IF
      case 42: // ELSE
      case 43: // ELSEIF
      case 44: // THEN
      case 45: // RETURN
      case 46: // BREAK
      case 47: // _FALSE
      case 48: // _TRUE
      case 49: // _END
      case 50: // IN
      case 51: // LOCAL
      case 52: // NIL
      case 53: // REP
      case 54: // UNTIL
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 56: // chunk
      case 57: // block
      case 58: // stat
      case 59: // laststat
      case 60: // funcname
      case 61: // varlist
      case 62: // var
      case 63: // namelist
      case 64: // explist
      case 65: // exp
      case 66: // prefixexp
      case 67: // functioncall
      case 68: // args
      case 69: // function
      case 70: // funcbody
      case 71: // parlist
      case 72: // tableconstructor
      case 73: // fieldlist
      case 74: // field
      case 75: // fieldsep
      case 76: // binop
      case 77: // unop
      case 78: // rep_func_name
      case 79: // rep_var
      case 80: // rep_list_name
      case 81: // rep_exp
      case 82: // rep_elseif
      case 83: // rep_stat
      case 84: // rep_field
      case 85: // opt_explist
      case 86: // opt_parlist
      case 87: // opt_name
      case 88: // opt_tridot
      case 89: // opt_fieldlist
      case 90: // opt_fieldsep
      case 91: // opt_semi
      case 92: // opt_laststat
      case 93: // opt_exp
      case 94: // opt_else
      case 95: // opt_eq
        yylhs.value.build< Node > ();
        break;

      case 3: // WS
      case 4: // NL
      case 5: // SEMCOL
      case 6: // STR
      case 7: // NUM
      case 8: // EQ
      case 9: // COM
      case 10: // DOT
      case 11: // COL
      case 12: // BRKOPN
      case 13: // BRKCLS
      case 14: // TRIDOT
      case 15: // PAROPN
      case 16: // PARCLS
      case 17: // CUROPN
      case 18: // CURCLS
      case 19: // NAME
      case 20: // FUNC
      case 21: // PLUS
      case 22: // MINUS
      case 23: // MULT
      case 24: // DIV
      case 25: // POW
      case 26: // MOD
      case 27: // DDOT
      case 28: // LESS
      case 29: // GREAT
      case 30: // LESSEQ
      case 31: // GREATEQ
      case 32: // EQEQ
      case 33: // NOTEQ
      case 34: // AND
      case 35: // OR
      case 36: // NOT
      case 37: // HASH
      case 38: // WHILE
      case 39: // FOR
      case 40: // DO
      case 41: // IF
      case 42: // ELSE
      case 43: // ELSEIF
      case 44: // THEN
      case 45: // RETURN
      case 46: // BREAK
      case 47: // _FALSE
      case 48: // _TRUE
      case 49: // _END
      case 50: // IN
      case 51: // LOCAL
      case 52: // NIL
      case 53: // REP
      case 54: // UNTIL
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 27 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 741 "src/parser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 28 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); if (!yystack_[0].value.as< Node > ().isUndefined()) yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ()); root = yylhs.value.as< Node > (); }
#line 747 "src/parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 31 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 753 "src/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 34 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::Equal);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 763 "src/parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 39 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 769 "src/parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 40 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 775 "src/parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 41 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::While);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[3].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                    }
#line 785 "src/parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 46 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::Repeat);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 795 "src/parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 51 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::If);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[5].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[3].value.as< Node > ());
                                                                      if (yystack_[2].value.as< Node > ().size() != 0)
                                                                        yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ());
                                                                      if (!yystack_[1].value.as< Node > ().isUndefined())
                                                                        yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                    }
#line 809 "src/parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 60 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::For);
                                                                      Node name = Node(Node::Type::Name, yystack_[8].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[6].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[4].value.as< Node > ());
                                                                      if (!yystack_[3].value.as< Node > ().isUndefined())
                                                                        yylhs.value.as< Node > ().addChild(yystack_[3].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                    }
#line 824 "src/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 70 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 830 "src/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 71 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::Function);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 840 "src/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 76 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 846 "src/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 77 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 852 "src/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 80 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 858 "src/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 81 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 864 "src/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 84 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::FunctionName);
                                                                      Node name = Node(Node::Type::Name, yystack_[2].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                      if (yystack_[1].value.as< Node > ().size() > 0)
                                                                        yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                      if (!yystack_[0].value.as< Node > ().isUndefined())
                                                                        yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 878 "src/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 95 "src/parser.y" // lalr1.cc:847
    {
                                                                      if (yystack_[0].value.as< Node > ().size() == 0) {
                                                                        yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                                                      } else {
                                                                        yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
                                                                        yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                      }
                                                                    }
#line 891 "src/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 105 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Name, yystack_[0].value.as< std::string > ()); }
#line 897 "src/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 106 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::MemberFunction);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[3].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                    }
#line 907 "src/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 111 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::MemberVariable);
                                                                      Node name = Node(Node::Type::Name, yystack_[0].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                    }
#line 918 "src/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 119 "src/parser.y" // lalr1.cc:847
    {
                                                                      Node name = Node(Node::Type::Name, yystack_[1].value.as< std::string > ());
                                                                      yylhs.value.as< Node > () = Node(Node::Type::ListName);
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                      if (yystack_[0].value.as< Node > ().size() != 0)
                                                                        yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 930 "src/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 128 "src/parser.y" // lalr1.cc:847
    {
                                                                      if (yystack_[1].value.as< Node > ().size() != 0) {
                                                                        yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                                                        yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                      } else {
                                                                        yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
                                                                      }
                                                                    }
#line 943 "src/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 138 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Nil, "Nil"); }
#line 949 "src/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 139 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::False, "false"); }
#line 955 "src/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 140 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::True, "true"); }
#line 961 "src/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 141 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Number, yystack_[0].value.as< std::string > ()); }
#line 967 "src/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 142 "src/parser.y" // lalr1.cc:847
    {
                                                                      yystack_[0].value.as< std::string > ().erase(0,1);
                                                                      yystack_[0].value.as< std::string > ().erase(yystack_[0].value.as< std::string > ().length() - 1, 1);
                                                                      yylhs.value.as< Node > () = Node(Node::Type::String, yystack_[0].value.as< std::string > ());
                                                                    }
#line 977 "src/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 147 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Tridot, "..."); }
#line 983 "src/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 148 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 989 "src/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 149 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 995 "src/parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 150 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1001 "src/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 151 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                                                      yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 1011 "src/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 156 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 1020 "src/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 162 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1026 "src/parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 163 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1032 "src/parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 164 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1038 "src/parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 167 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::FunctionCall);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 1048 "src/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 172 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = yystack_[3].value.as< Node > ();
                                                                      Node name = Node(Node::Type::Name, yystack_[1].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                      yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 1059 "src/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 180 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1065 "src/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 181 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1071 "src/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 182 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::String, yystack_[0].value.as< std::string > ()); }
#line 1077 "src/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 185 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1083 "src/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 188 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::FunctionBody);
                                                                      if (!yystack_[3].value.as< Node > ().isUndefined())
                                                                        yylhs.value.as< Node > ().addChild(yystack_[3].value.as< Node > ());
                                                                      yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ());
                                                                    }
#line 1094 "src/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 196 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1100 "src/parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 197 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Tridot); }
#line 1106 "src/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 200 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1112 "src/parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 203 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1118 "src/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 206 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1124 "src/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 207 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = Node(Node::Type::Equal);
                                                                      Node name = Node(Node::Type::Name, yystack_[2].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name); yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ());
                                                                    }
#line 1134 "src/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 212 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1140 "src/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 215 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Comma); }
#line 1146 "src/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 216 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::SemiColon); }
#line 1152 "src/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 219 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Addition); }
#line 1158 "src/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 220 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Subtraction); }
#line 1164 "src/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 221 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Division); }
#line 1170 "src/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 222 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Multiplication); }
#line 1176 "src/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 223 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Power); }
#line 1182 "src/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 224 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Modulo); }
#line 1188 "src/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 225 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::DoubleDot); }
#line 1194 "src/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 226 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::LessThan); }
#line 1200 "src/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 227 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::LessOrEq); }
#line 1206 "src/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 228 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::GreaterThan); }
#line 1212 "src/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 229 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::GreaterOrEq); }
#line 1218 "src/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 230 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Test); }
#line 1224 "src/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 231 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::NotEq); }
#line 1230 "src/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 232 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::And); }
#line 1236 "src/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 233 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Or); }
#line 1242 "src/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 236 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Subtraction); }
#line 1248 "src/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 237 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Not); }
#line 1254 "src/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 238 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Hash); }
#line 1260 "src/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 241 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::FunctionName); }
#line 1266 "src/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 242 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
                                                                      Node name = Node(Node::Type::Name, yystack_[0].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                    }
#line 1276 "src/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 249 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::VariableList); }
#line 1282 "src/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 250 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ()); }
#line 1288 "src/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 253 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::ListName); }
#line 1294 "src/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 254 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
                                                                      Node name = Node(Node::Type::Name, yystack_[0].value.as< std::string > ());
                                                                      yylhs.value.as< Node > ().addChild(name);
                                                                    }
#line 1304 "src/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 261 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::ExpressionList); }
#line 1310 "src/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 262 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ()); }
#line 1316 "src/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 265 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::ElseIf); }
#line 1322 "src/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 266 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[4].value.as< Node > (); yylhs.value.as< Node > ().addChild(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().addChild(yystack_[0].value.as< Node > ()); }
#line 1328 "src/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 269 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Stat); }
#line 1334 "src/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 270 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ()); }
#line 1340 "src/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 273 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Field); }
#line 1346 "src/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 274 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().addChild(yystack_[1].value.as< Node > ()); }
#line 1352 "src/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 277 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1358 "src/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 278 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1364 "src/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 281 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1370 "src/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 282 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1376 "src/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 285 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1382 "src/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 286 "src/parser.y" // lalr1.cc:847
    { Node name = Node(Node::Type::Name, yystack_[0].value.as< std::string > ()); yylhs.value.as< Node > () = name; }
#line 1388 "src/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 289 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1394 "src/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 290 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::Tridot); }
#line 1400 "src/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 293 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1406 "src/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 294 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1412 "src/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 297 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1418 "src/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 298 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1424 "src/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 301 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1430 "src/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 302 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(Node::Type::SemiColon); }
#line 1436 "src/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 305 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1442 "src/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 306 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1448 "src/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 309 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1454 "src/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 310 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1460 "src/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 313 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1466 "src/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 314 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1472 "src/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 317 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node(); }
#line 1478 "src/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 318 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1484 "src/parser.cpp" // lalr1.cc:847
    break;


#line 1488 "src/parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -44;

  const signed char parser::yytable_ninf_ = -88;

  const short int
  parser::yypact_[] =
  {
      19,    25,   113,   -44,    83,   -44,    11,    83,    27,   -33,
      83,     8,   -44,    21,     4,    51,    51,    53,    87,    32,
      16,   -44,   -44,   -44,   -44,    17,    52,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    50,    32,   -44,   -44,   -44,    83,
     -44,    52,   301,    80,    54,   -44,    44,   215,   -44,    83,
     -44,   -44,    98,   110,    67,   -44,   -44,   -44,   -44,   114,
     -44,   103,   106,    83,   108,   -44,   -44,    83,   118,   321,
     -44,   -44,   109,    -5,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,    83,   321,   101,   -44,   -33,    83,   120,   -44,   -44,
     -31,   146,    52,   -44,   -44,    83,   -44,     2,   -44,    93,
     263,   121,   286,    83,    43,   -44,   -44,   125,   -44,   122,
     321,   124,   127,   -44,    90,   173,   128,   100,   -44,   -44,
     -44,   -44,   321,   105,   -44,   -44,   -44,   133,   321,   -44,
     -44,    17,   -44,   130,   -44,   -33,   -44,   -44,   -44,    83,
     -44,   -33,    73,    83,   -44,   -44,    99,   200,   112,   -33,
      83,   116,   321,   -44,    83,   117,   -44,   -44,   239,   -44,
     321,   -33,   -31,   134,   -44,   -44
  };

  const unsigned char
  parser::yydefact_[] =
  {
      83,     0,   101,     1,     0,    20,     0,     0,     0,    83,
       0,    79,    17,     0,    83,    99,    99,     0,    36,     0,
       6,     3,    29,    28,    30,    95,     0,    70,    71,    72,
      26,    27,    25,    36,     0,    32,    37,    31,    33,     0,
      73,     0,     0,    77,     0,     4,     0,     0,    88,     0,
      16,    77,     0,   107,     0,   100,    84,   102,    79,    19,
      43,     0,     0,     0,    79,    39,    42,     0,    20,    52,
      96,    85,     0,    89,    44,    38,    55,    56,    58,    57,
      59,    60,    61,    62,    64,    63,    65,    66,    67,    68,
      69,     0,    35,    91,    13,    83,     0,    23,    79,     7,
      83,    24,     0,    79,    15,     0,     5,     0,    22,     0,
       0,     0,     0,     0,    97,    48,    47,    93,    90,     0,
      34,     0,     0,    18,     0,     0,     0,     0,    81,    80,
      14,   108,     9,    36,    40,    21,    41,     0,    51,    54,
      53,    98,    49,     0,    46,    83,    74,    92,     8,     0,
      78,    83,   105,     0,    86,    94,     0,   103,     0,    83,
       0,     0,    50,    45,     0,     0,    12,   106,     0,    10,
     104,    83,    83,     0,    82,    11
  };

  const short int
  parser::yypgoto_[] =
  {
     -44,   184,    -9,   -44,   -44,   -44,   -44,    -1,    -3,   -43,
      -4,     0,   183,    77,   -44,   -34,   -44,   -15,   -44,    46,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     126,   -44,   -44,   -44,   -44,   -44,   172,   -44,   -44,   -44,
     -44
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    45,    46,    15,    16,    41,    17,    33,    44,    48,
      69,    35,    36,    65,    37,    74,   118,    38,    70,    71,
     141,    91,    39,    93,    59,    97,    49,   152,     2,   114,
      50,   119,   123,   144,    72,   142,    56,    21,   165,   161,
     104
  };

  const short int
  parser::yytable_[] =
  {
      34,    18,    19,    42,    66,    54,    47,    94,   -87,   116,
      53,    -2,    -2,   -87,    51,   106,    -2,     4,    -2,    -2,
      66,     5,   -37,    22,    23,     3,   -37,   -37,   -37,    67,
      40,    24,     4,   -37,    25,    92,    68,    26,    60,    27,
      51,    52,    61,    62,    63,   101,    43,    64,   139,    25,
     -87,   -87,   140,    28,    29,   127,    55,   -87,    -2,   110,
     131,    58,   -87,   112,    30,    31,    75,    73,   130,    32,
     117,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   124,   120,    96,    22,
      23,   128,   125,    99,    66,   -75,   -75,    24,     4,    60,
      25,   132,     5,    26,    98,    27,   133,    19,    64,   138,
      25,   121,   122,   -76,   -76,   159,   160,   102,   103,    28,
      29,   105,   108,   107,   -87,   109,   113,   115,     4,   126,
      30,    31,     5,     6,   143,    32,   156,   136,   145,   148,
     151,   153,   158,   146,   155,   157,   147,   150,   163,   162,
     167,     7,     8,     9,    10,   129,   168,   171,    11,    12,
     170,   166,   173,   174,    13,   169,    14,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   149,   175,     1,    20,   134,   154,    57,     0,
     111,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,   100,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,   135,     0,     0,     0,
       0,     0,     0,   172,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   137,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    95,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90
  };

  const short int
  parser::yycheck_[] =
  {
       4,     2,     2,     7,    19,    14,    10,    41,     0,    14,
      13,    42,    43,     5,    19,    58,    49,    15,    49,     0,
      35,    19,     6,     6,     7,     0,    10,    11,    12,    12,
      19,    14,    15,    17,    17,    39,    19,    20,     6,    22,
      19,    20,    10,    11,    12,    49,    19,    15,     5,    17,
      42,    43,     9,    36,    37,    98,     5,    49,    54,    63,
     103,     8,    54,    67,    47,    48,    16,    15,   102,    52,
      73,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    95,    91,     8,     6,
       7,   100,    96,    49,   109,     8,     9,    14,    15,     6,
      17,   105,    19,    20,    50,    22,   107,   107,    15,   113,
      17,    10,    11,     8,     9,    42,    43,    19,     8,    36,
      37,    54,    19,     9,    16,    19,     8,    18,    15,     9,
      47,    48,    19,    20,     9,    52,   145,    16,    16,    49,
      40,     8,   151,    19,    14,   149,    19,    19,    49,   153,
     159,    38,    39,    40,    41,     9,   160,    40,    45,    46,
     164,    49,   171,   172,    51,    49,    53,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     9,    49,     0,     2,   109,   141,    16,    -1,
      64,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    56,    83,     0,    15,    19,    20,    38,    39,    40,
      41,    45,    46,    51,    53,    58,    59,    61,    62,    66,
      67,    92,     6,     7,    14,    17,    20,    22,    36,    37,
      47,    48,    52,    62,    65,    66,    67,    69,    72,    77,
      19,    60,    65,    19,    63,    56,    57,    65,    64,    81,
      85,    19,    20,    63,    57,     5,    91,    91,     8,    79,
       6,    10,    11,    12,    15,    68,    72,    12,    19,    65,
      73,    74,    89,    15,    70,    16,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    76,    65,    78,    70,    40,     8,    80,    50,    49,
      44,    65,    19,     8,    95,    54,    64,     9,    19,    19,
      65,    85,    65,     8,    84,    18,    14,    63,    71,    86,
      65,    10,    11,    87,    57,    65,     9,    64,    57,     9,
      70,    64,    65,    62,    68,    13,    16,    13,    65,     5,
       9,    75,    90,     9,    88,    16,    19,    19,    49,     9,
      19,    40,    82,     8,    74,    14,    57,    65,    57,    42,
      43,    94,    65,    49,     9,    93,    49,    57,    65,    49,
      65,    40,    44,    57,    57,    49
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    55,    56,    56,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    61,
      62,    62,    62,    63,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    68,    69,    70,    71,    71,    72,    73,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     1,     3,     5,     4,
       7,    10,     7,     3,     4,     3,     2,     1,     3,     2,
       1,     4,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     1,     3,     2,
       4,     3,     1,     1,     2,     5,     2,     1,     3,     3,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     5,     0,     3,     0,     3,     0,     1,     0,
       1,     0,     2,     0,     2,     0,     1,     0,     1,     0,
       1,     0,     2,     0,     2,     0,     2,     0,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "WS", "NL", "SEMCOL", "STR",
  "NUM", "EQ", "COM", "DOT", "COL", "BRKOPN", "BRKCLS", "TRIDOT", "PAROPN",
  "PARCLS", "CUROPN", "CURCLS", "NAME", "FUNC", "PLUS", "MINUS", "MULT",
  "DIV", "POW", "MOD", "DDOT", "LESS", "GREAT", "LESSEQ", "GREATEQ",
  "EQEQ", "NOTEQ", "AND", "OR", "NOT", "HASH", "WHILE", "FOR", "DO", "IF",
  "ELSE", "ELSEIF", "THEN", "RETURN", "BREAK", "_FALSE", "_TRUE", "_END",
  "IN", "LOCAL", "NIL", "REP", "UNTIL", "$accept", "chunk", "block",
  "stat", "laststat", "funcname", "varlist", "var", "namelist", "explist",
  "exp", "prefixexp", "functioncall", "args", "function", "funcbody",
  "parlist", "tableconstructor", "fieldlist", "field", "fieldsep", "binop",
  "unop", "rep_func_name", "rep_var", "rep_list_name", "rep_exp",
  "rep_elseif", "rep_stat", "rep_field", "opt_explist", "opt_parlist",
  "opt_name", "opt_tridot", "opt_fieldlist", "opt_fieldsep", "opt_semi",
  "opt_laststat", "opt_exp", "opt_else", "opt_eq", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    27,    27,    28,    31,    34,    39,    40,    41,    46,
      51,    60,    70,    71,    76,    77,    80,    81,    84,    95,
     105,   106,   111,   119,   128,   138,   139,   140,   141,   142,
     147,   148,   149,   150,   151,   156,   162,   163,   164,   167,
     172,   180,   181,   182,   185,   188,   196,   197,   200,   203,
     206,   207,   212,   215,   216,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     236,   237,   238,   241,   242,   249,   250,   253,   254,   261,
     262,   265,   266,   269,   270,   273,   274,   277,   278,   281,
     282,   285,   286,   289,   290,   293,   294,   297,   298,   301,
     302,   305,   306,   309,   310,   313,   314,   317,   318
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1929 "src/parser.cpp" // lalr1.cc:1155
