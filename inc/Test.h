#pragma once

#include "Node.h"

//! Handles test operations
/**
* @author Jim Ahlstrand
* @todo add test for number of children, test can have max 2
*/
class Test : public Node {
public:
  //! Defines types of Tests
  enum Type {
    Undefined,
    LessThan,
    LessOrEqual,
    GreaterThan,
    GreaterOrEqual,
    EqualEqual,
    NotEqual,
    And,
    Or,
    Not,
    False,
    True
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Test();
  //! Constructor with type
  /**
  * @param type Test type of enum Type
  */
  Test(Type type);

  // Methods
  // ---------------------------------------
  //! Executes the Test
  /**
  * @param env current Environment
  * @return integer value of the node
  */
  int evalInt(Environment& env);
  /** Evaluate string of the Binop
  * @param env current Environment
  * @return string value of the node
  */
  std::string evalStr(Environment& env);
  //! Converts type of node to string
  /**
  * @return string type of the node
  */
  std::string getType();

protected:
  // Properties
  // ---------------------------------------
  //! Test type
  Type type;
};
