#pragma once

#include "Node.h"

/** Handles loops
* @author Jim Ahlstrand
* @remark for loop is rewritten in the parser, however this is not a complete rewrite
*/
class Loop : public Node {
public:
  //! Defines types of Loops
  enum Type {
    Undefined,
    Repeat,   //! @todo Implement this
    While,
    For       //! @todo Should be rewritten as while loop
              //! @see http://www.lua.org/manual/5.1/manual.html#2.4.5
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Loop();
  /** Constructor with type
  * @param type Loop type of enum Type
  */
  Loop(Type type);

  // Methods
  // ---------------------------------------
  /** Executes the Loop
  * @param env current Environment
  * @return integer value of the node
  */
  bool execute(Environment& env);
  /** Converts type of node to string
  * @return string type of the node
  */
  std::string getType();

protected:
  // Properties
  // ---------------------------------------
  //! Loop type
  Type type;
};
