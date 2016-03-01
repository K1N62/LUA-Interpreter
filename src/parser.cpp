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
#line 14 "src/parser.y" // lalr1.cc:408

  #include <string>
  #include <iostream>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  Environment env;

#line 63 "src/parser.cpp" // lalr1.cc:408


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
#line 130 "src/parser.cpp" // lalr1.cc:474

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
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // varlist
      case 60: // var
      case 61: // namelist
      case 62: // explist
      case 63: // exp
      case 64: // prefixexp
      case 65: // functioncall
      case 66: // args
      case 67: // function
      case 68: // funcbody
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        value.move< Node* > (that.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.move< string > (that.value);
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
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // varlist
      case 60: // var
      case 61: // namelist
      case 62: // explist
      case 63: // exp
      case 64: // prefixexp
      case 65: // functioncall
      case 66: // args
      case 67: // function
      case 68: // funcbody
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        value.copy< Node* > (that.value);
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        value.copy< string > (that.value);
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
      case 54: // chunk
      case 55: // block
      case 56: // stat
      case 57: // laststat
      case 58: // funcname
      case 59: // varlist
      case 60: // var
      case 61: // namelist
      case 62: // explist
      case 63: // exp
      case 64: // prefixexp
      case 65: // functioncall
      case 66: // args
      case 67: // function
      case 68: // funcbody
      case 69: // parlist
      case 70: // tableconstructor
      case 71: // fieldlist
      case 72: // field
      case 73: // fieldsep
      case 74: // rep_func_name
      case 75: // rep_var
      case 76: // rep_list_name
      case 77: // rep_exp
      case 78: // rep_elseif
      case 79: // rep_stat
      case 80: // rep_field
      case 81: // opt_explist
      case 82: // opt_parlist
      case 83: // opt_name
      case 84: // opt_tridot
      case 85: // opt_fieldlist
      case 86: // opt_fieldsep
      case 87: // opt_semi
      case 88: // opt_laststat
      case 89: // opt_exp
      case 90: // opt_else
      case 91: // opt_eq
        yylhs.value.build< Node* > ();
        break;

      case 3: // STR
      case 4: // NUM
      case 5: // NAME
        yylhs.value.build< string > ();
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
#line 47 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 589 "src/parser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 48 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                                                                      if (yystack_[0].value.as< Node* > () != NULL )
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                      root = yylhs.value.as< Node* > ();
                                                                    }
#line 600 "src/parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 56 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 606 "src/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 59 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::Equal);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 616 "src/parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 64 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 622 "src/parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 65 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Loop(Loop::Type::Do);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 631 "src/parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 69 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Loop(Loop::Type::While);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 641 "src/parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 74 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Loop(Loop::Type::Repeat);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 651 "src/parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 79 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Condition(Condition::Type::If);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[5].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      if (yystack_[2].value.as< Node* > ()->size() != 0)
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                                                                      if (yystack_[1].value.as< Node* > () != NULL )
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 665 "src/parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 88 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Loop(Loop::Type::For);
                                                                      Node* name = new Node(Node::Type::Name, yystack_[8].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[6].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[4].value.as< Node* > ());
                                                                      if (yystack_[3].value.as< Node* > () != NULL )
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 680 "src/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 98 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Loop(Loop::Type::For);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[5].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 691 "src/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 104 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::Function);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 701 "src/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 109 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 707 "src/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 110 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 713 "src/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 113 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 719 "src/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 114 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 725 "src/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 117 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::FunctionName);
                                                                      Node* name = new Node(Node::Type::Name, yystack_[2].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                      if (yystack_[1].value.as< Node* > ()->size() > 0)
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                      if (yystack_[0].value.as< Node* > () != NULL )
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 739 "src/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 128 "src/parser.y" // lalr1.cc:847
    {
                                                                      if (yystack_[0].value.as< Node* > ()->size() == 0) {
                                                                        yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                                                                      } else {
                                                                        yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > ();
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                      }
                                                                    }
#line 752 "src/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 138 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Name, yystack_[0].value.as< string > ()); }
#line 758 "src/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 139 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::FieldElement);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 768 "src/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 144 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::MemberFunction);
                                                                      Node* name = new Node(Node::Type::Name, yystack_[0].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                    }
#line 779 "src/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 152 "src/parser.y" // lalr1.cc:847
    {
                                                                      Node* name = new Node(Node::Type::Name, yystack_[1].value.as< string > ());
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::ListName);
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                      if (yystack_[0].value.as< Node* > ()->size() != 0)
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 791 "src/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 161 "src/parser.y" // lalr1.cc:847
    {
                                                                      if (yystack_[1].value.as< Node* > ()->size() != 0) {
                                                                        yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                      } else {
                                                                        yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > ();
                                                                      }
                                                                    }
#line 804 "src/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 171 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Nil, "Nil"); }
#line 810 "src/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 172 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::False); }
#line 816 "src/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 173 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::True); }
#line 822 "src/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 174 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Number, yystack_[0].value.as< string > ()); }
#line 828 "src/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 175 "src/parser.y" // lalr1.cc:847
    {
                                                                      yystack_[0].value.as< string > ().erase(0,1);
                                                                      yystack_[0].value.as< string > ().erase(yystack_[0].value.as< string > ().length() - 1, 1);
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::String, yystack_[0].value.as< string > ());
                                                                    }
#line 838 "src/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 180 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Tridot, "..."); }
#line 844 "src/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 181 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 850 "src/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 182 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 856 "src/parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 183 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 862 "src/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 184 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::DoubleDot); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 868 "src/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 185 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Addition); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 874 "src/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 186 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Subtraction); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 880 "src/parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 187 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Division); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 886 "src/parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 188 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Multiplication); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 892 "src/parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 189 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Power); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 898 "src/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 190 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Binop(Binop::Type::Modulo); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 904 "src/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 191 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::LessThan); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 910 "src/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 192 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::LessOrEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 916 "src/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 193 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::GreaterThan); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 922 "src/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 194 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::GreaterOrEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 928 "src/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 195 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::EqualEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 934 "src/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 196 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::NotEqual); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 940 "src/parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 197 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::And); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 946 "src/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 198 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::Or); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 952 "src/parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 199 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Test(Test::Type::Not); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 958 "src/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 200 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Negate); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 964 "src/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 201 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Hash); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 970 "src/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 204 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 976 "src/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 205 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 982 "src/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 206 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 988 "src/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 209 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::FunctionCall);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 998 "src/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 214 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = yystack_[3].value.as< Node* > ();
                                                                      Node* name = new Node(Node::Type::Name, yystack_[1].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 1009 "src/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 222 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1015 "src/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 223 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1021 "src/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 224 "src/parser.y" // lalr1.cc:847
    {
                                                                      yystack_[0].value.as< string > ().erase(0,1);
                                                                      yystack_[0].value.as< string > ().erase(yystack_[0].value.as< string > ().length() - 1, 1);
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::String, yystack_[0].value.as< string > ());
                                                                    }
#line 1031 "src/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 231 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1037 "src/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 234 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::FunctionBody);
                                                                      if (yystack_[3].value.as< Node* > () != NULL )
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ());
                                                                    }
#line 1048 "src/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 242 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1054 "src/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 243 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Tridot); }
#line 1060 "src/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 246 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1066 "src/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 249 "src/parser.y" // lalr1.cc:847
    {
                                                                      if (yystack_[1].value.as< Node* > ()->size() != 0) {
                                                                        yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > ();
                                                                        yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ());
                                                                        yylhs.value.as< Node* > ()->moveToFront();
                                                                      } else {
                                                                        yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > ();
                                                                      }
                                                                    }
#line 1080 "src/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 260 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::Equal);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[3].value.as< Node* > ());
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 1090 "src/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 265 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = new Node(Node::Type::Equal);
                                                                      Node* name = new Node(Node::Type::Name, yystack_[2].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                      yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ());
                                                                    }
#line 1101 "src/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 271 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1107 "src/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 274 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1113 "src/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 275 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1119 "src/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 278 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::FunctionName); }
#line 1125 "src/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 279 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > ();
                                                                      Node* name = new Node(Node::Type::Name, yystack_[0].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                    }
#line 1135 "src/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 286 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::VariableList); }
#line 1141 "src/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 287 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1147 "src/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 290 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::ListName); }
#line 1153 "src/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 291 "src/parser.y" // lalr1.cc:847
    {
                                                                      yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > ();
                                                                      Node* name = new Node(Node::Type::Name, yystack_[0].value.as< string > ());
                                                                      yylhs.value.as< Node* > ()->addChild(name);
                                                                    }
#line 1163 "src/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 298 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::ExpressionList); }
#line 1169 "src/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 299 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ()); }
#line 1175 "src/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 302 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Condition(Condition::Type::ElseIf); }
#line 1181 "src/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 303 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[4].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[2].value.as< Node* > ()); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1187 "src/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 306 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Stat); }
#line 1193 "src/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 307 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[1].value.as< Node* > ()); }
#line 1199 "src/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 310 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::FieldList); }
#line 1205 "src/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 311 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[2].value.as< Node* > (); yylhs.value.as< Node* > ()->addChild(yystack_[0].value.as< Node* > ()); }
#line 1211 "src/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 314 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1217 "src/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 315 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1223 "src/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 318 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1229 "src/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 319 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1235 "src/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 322 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1241 "src/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 323 "src/parser.y" // lalr1.cc:847
    { Node* name = new Node(Node::Type::Name, yystack_[0].value.as< string > ()); yylhs.value.as< Node* > () = name; }
#line 1247 "src/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 326 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1253 "src/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 327 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::Tridot); }
#line 1259 "src/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 330 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = new Node(Node::Type::FieldList); }
#line 1265 "src/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 331 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1271 "src/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 334 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1277 "src/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 335 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1283 "src/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 338 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1289 "src/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 339 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1295 "src/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 342 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1301 "src/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 343 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[1].value.as< Node* > (); }
#line 1307 "src/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 346 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1313 "src/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 347 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1319 "src/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 350 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1325 "src/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 351 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1331 "src/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 354 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = NULL; }
#line 1337 "src/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 355 "src/parser.y" // lalr1.cc:847
    { yylhs.value.as< Node* > () = yystack_[0].value.as< Node* > (); }
#line 1343 "src/parser.cpp" // lalr1.cc:847
    break;


#line 1347 "src/parser.cpp" // lalr1.cc:847
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


  const signed char parser::yypact_ninf_ = -50;

  const signed char parser::yytable_ninf_ = -86;

  const short int
  parser::yypact_[] =
  {
       6,    29,   216,   -50,   -50,    27,    10,    31,    27,   105,
     -50,     9,     5,    27,    41,    32,    32,    35,   -14,   126,
     215,   -50,   -50,   -50,   -50,   -50,   -50,   -50,    21,    43,
      27,    27,    27,   -50,    96,   126,   -50,   -50,   -50,    39,
      58,   -50,    66,   151,   -50,    27,   -50,   -50,    79,    84,
      81,   329,   -50,    43,   -50,   -50,   -50,   -50,    88,   -50,
     104,   109,    27,    85,   -50,   -50,    95,    27,   346,   -50,
     -50,    87,    15,   -50,   -30,    72,    72,    31,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    98,   -50,   -50,   101,   219,    43,
     -50,   -50,    27,   -50,    42,   -50,   -50,     3,   -50,     2,
     290,    93,    27,   311,   -16,   -50,   -50,   106,   -50,    94,
     113,   362,   377,   386,   386,   386,   386,   386,   386,   386,
     -30,   -30,    72,    72,    72,    72,   244,   141,   142,   -50,
     -50,   -50,   -50,   346,   144,   150,   -50,    55,   -50,   -50,
     -50,   346,   132,   -50,   -50,    21,   -50,   128,   -50,    31,
     -50,    27,   -50,    31,    71,   -50,   -50,    27,   -50,   -50,
     143,   269,   145,    31,    27,   147,   346,   -50,    27,   157,
     -50,   -50,   168,   -50,   346,    31,   101,   149,   -50,   -50
  };

  const unsigned char
  parser::yydefact_[] =
  {
      81,     0,    99,     1,    20,     0,     0,    81,     0,    77,
      17,     0,    81,     0,     0,    97,    97,     0,    52,     0,
       6,     3,    29,    28,    26,    27,    25,    30,    93,     0,
       0,     0,     0,    52,     0,    32,    53,    31,    33,    75,
       0,     4,     0,     0,    86,     0,    16,    75,     0,   105,
       0,     0,    71,     0,    98,    82,   100,    77,    19,    59,
       0,     0,     0,    77,    55,    58,    20,     0,    68,    94,
      83,     0,    87,    60,    50,    49,    51,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    77,     7,    81,    24,     0,
      77,    15,     0,    54,    89,    13,     5,     0,    22,     0,
       0,     0,     0,     0,    95,    64,    63,    91,    88,     0,
       0,    48,    47,    41,    43,    42,    44,    45,    46,    34,
      35,    36,    38,    37,    40,    39,     0,     0,     0,    79,
      78,    14,   106,     9,     0,     0,    18,    52,    56,    21,
      57,    67,     0,    70,    69,    96,    65,     0,    62,    81,
       8,     0,    76,    81,   103,    72,    90,     0,    84,    92,
       0,   101,     0,    81,     0,     0,    66,    61,     0,     0,
      12,   104,     0,    10,   102,    81,    81,     0,    80,    11
  };

  const short int
  parser::yypgoto_[] =
  {
     -50,   167,   -12,   -50,   -50,   -50,   -50,    -1,    -8,   -34,
       8,     0,   166,    61,   -50,   -49,   -50,    -7,   -50,    16,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   114,   -50,
     -50,   -50,   -50,   -50,   156,   -50,   -50,   -50,   -50
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    41,    42,    15,    16,    53,    17,    33,    40,    44,
      68,    35,    36,    64,    37,    73,   118,    38,    69,    70,
     155,   104,    58,    94,    45,   164,     2,   114,    46,   119,
     146,   158,    71,   156,    55,    21,   179,   175,   101
  };

  const short int
  parser::yytable_[] =
  {
      50,    18,    19,    49,   105,    59,    -2,   153,     4,   154,
     -73,   -73,    65,    34,    47,    39,    43,    89,    90,    91,
      47,    51,    92,   106,    22,    23,    66,    -2,    65,     3,
      22,    23,     4,    63,    13,    28,    24,    25,    74,    75,
      76,    26,    24,    25,    48,   116,    52,    26,    -2,    67,
     141,    27,    13,    98,    28,    54,    29,    27,    13,    57,
      28,   138,    29,    93,   117,   120,   142,    30,   144,   145,
     110,    31,    32,    30,    72,   113,    95,    31,    32,   -74,
     -74,   173,   174,    96,    99,   139,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    65,   102,    77,   -85,   147,    19,   100,   108,
     143,    -2,    -2,   107,   109,   -85,   -85,   -85,    -2,   112,
     151,   115,   -85,   137,    92,   150,   159,   -85,   -85,    59,
     160,   157,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   162,   170,    92,   165,
     163,   172,    60,    61,    62,   166,   167,    63,   169,    28,
     177,   181,   180,    97,   183,   185,   189,     1,    20,   171,
     148,   168,    56,   187,   188,   176,     0,   111,     0,     0,
     186,     0,   182,     0,     0,     0,   184,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,    92,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   -53,     0,
      92,     4,     5,     6,     7,     8,     0,     0,     0,     9,
      10,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   -53,   -53,   -53,   140,     0,     0,    13,   -53,     0,
       0,    14,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   161,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   178,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   149,
       0,    92,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     152,     0,    92,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   103,     0,    92,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,    92,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    92,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,    92,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,    92,
      86,    87,    88,    89,    90,    91,     0,     0,    92
  };

  const short int
  parser::yycheck_[] =
  {
      12,     2,     2,    11,    53,     3,     0,    23,     5,    25,
      24,    25,    19,     5,     5,     5,     8,    47,    48,    49,
       5,    13,    52,    57,     3,     4,     5,    22,    35,     0,
       3,     4,     5,    31,    31,    33,    15,    16,    30,    31,
      32,    20,    15,    16,    35,    30,     5,    20,    17,    28,
      99,    30,    31,    45,    33,    23,    35,    30,    31,    24,
      33,    95,    35,    24,    72,    77,   100,    46,    26,    27,
      62,    50,    51,    46,    31,    67,    18,    50,    51,    24,
      25,    10,    11,    17,     5,    97,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   109,    22,     8,     0,   107,   107,    24,     5,
     102,    10,    11,    25,     5,    10,    11,    32,    17,    24,
     112,    34,    17,    25,    52,    32,    32,    22,    23,     3,
      17,    25,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     5,   159,    52,     5,
       8,   163,    26,    27,    28,     5,    24,    31,    30,    33,
      17,   173,    17,    12,    17,     8,    17,     0,     2,   161,
     109,   155,    16,   185,   186,   167,    -1,    63,    -1,    -1,
      12,    -1,   174,    -1,    -1,    -1,   178,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     3,    -1,
      52,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    26,    27,    28,    25,    -1,    -1,    31,    33,    -1,
      -1,    35,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    25,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    25,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    29,
      -1,    52,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      29,    -1,    52,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    32,    -1,    52,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    52,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    54,    79,     0,     5,     6,     7,     8,     9,    13,
      14,    19,    21,    31,    35,    56,    57,    59,    60,    64,
      65,    88,     3,     4,    15,    16,    20,    30,    33,    35,
      46,    50,    51,    60,    63,    64,    65,    67,    70,     5,
      61,    54,    55,    63,    62,    77,    81,     5,    35,    61,
      55,    63,     5,    58,    23,    87,    87,    24,    75,     3,
      26,    27,    28,    31,    66,    70,     5,    28,    63,    71,
      72,    85,    31,    68,    63,    63,    63,     8,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    52,    24,    76,    18,    17,    12,    63,     5,
      24,    91,    22,    32,    74,    68,    62,    25,     5,     5,
      63,    81,    24,    63,    80,    34,    30,    61,    69,    82,
      55,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    25,    62,    55,
      25,    68,    62,    63,    26,    27,    83,    60,    66,    29,
      32,    63,    29,    23,    25,    73,    86,    25,    84,    32,
      17,    25,     5,     8,    78,     5,     5,    24,    72,    30,
      55,    63,    55,    10,    11,    90,    63,    17,    25,    89,
      17,    55,    63,    17,    63,     8,    12,    55,    55,    17
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    53,    54,    54,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    60,    60,    61,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    66,
      67,    68,    69,    69,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     1,     3,     5,     4,
       7,    10,     7,     3,     4,     3,     2,     1,     3,     2,
       1,     4,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     3,     2,     4,     3,     1,     1,
       2,     5,     2,     1,     3,     3,     5,     3,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       5,     0,     3,     0,     3,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     1,     0,     1,     0,     1,     0,
       2,     0,     2,     0,     2,     0,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "STR", "NUM", "NAME", "WHILE",
  "FOR", "DO", "IF", "ELSE", "ELSEIF", "THEN", "RETURN", "BREAK", "_FALSE",
  "_TRUE", "_END", "IN", "LOCAL", "NIL", "REP", "UNTIL", "SEMCOL", "EQ",
  "COM", "DOT", "COL", "BRKOPN", "BRKCLS", "TRIDOT", "PAROPN", "PARCLS",
  "CUROPN", "CURCLS", "FUNC", "OR", "AND", "LESS", "GREAT", "LESSEQ",
  "GREATEQ", "EQEQ", "NOTEQ", "DDOT", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "NOT", "HASH", "POW", "$accept", "chunk", "block", "stat",
  "laststat", "funcname", "varlist", "var", "namelist", "explist", "exp",
  "prefixexp", "functioncall", "args", "function", "funcbody", "parlist",
  "tableconstructor", "fieldlist", "field", "fieldsep", "rep_func_name",
  "rep_var", "rep_list_name", "rep_exp", "rep_elseif", "rep_stat",
  "rep_field", "opt_explist", "opt_parlist", "opt_name", "opt_tridot",
  "opt_fieldlist", "opt_fieldsep", "opt_semi", "opt_laststat", "opt_exp",
  "opt_else", "opt_eq", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    47,    47,    48,    56,    59,    64,    65,    69,    74,
      79,    88,    98,   104,   109,   110,   113,   114,   117,   128,
     138,   139,   144,   152,   161,   171,   172,   173,   174,   175,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   204,   205,   206,   209,   214,   222,   223,   224,
     231,   234,   242,   243,   246,   249,   260,   265,   271,   274,
     275,   278,   279,   286,   287,   290,   291,   298,   299,   302,
     303,   306,   307,   310,   311,   314,   315,   318,   319,   322,
     323,   326,   327,   330,   331,   334,   335,   338,   339,   342,
     343,   346,   347,   350,   351,   354,   355
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
#line 1805 "src/parser.cpp" // lalr1.cc:1155
