#pragma once

#include "Node.h"

/** Handles loops
* @author Jim Ahlstrand
*/
class Loop : public Node {
public:
  //! Defines types of Loops
  enum Type {
    Undefined,
    Repeat,   //! @todo convert to while loop
    While,
    For,    //! @todo convert to while loop
    Do,   //! @todo convert to while loop
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
