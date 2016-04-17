#pragma once

#include "Node.h"
#include "math.h"
#include <cstring>

/** Handles binary operations
* @author Jim Ahlstrand
* @todo add test for number of children, binop can have max 2
*/
class Binop : public Node {
public:
  //! Defines types of Binops
  enum Type {
    Undefined,
    Equal,
    Addition,
    Subtraction,
    Division,
    Multiplication,
    Power,
    Modulo
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Binop();
  /** Constructor with type
  * @param type Binop type of enum Type
  */
  Binop(Type type);

  // Methods
  // ---------------------------------------
  /** Executes the Node
  * @param env current Environment
  * @return bool true if node did execute
  */
  bool execute(Environment& env);
  /** Evaluate value of node
   * @param env current Environment
   * @return Memory* Pointer to memory with value of node
   */
  Memory* eval(Environment& env);
  /** Evaluate integer of the Binop
  * @param env current Environment
  * @return integer value of the node
  */
  int evalInt(Environment& env);
  /** Evaluate string of the Binop
  * @param env current Environment
  * @return string value of the node
  */
  std::string evalStr(Environment& env);
  /** Converts type of node to string
  * @return string type of the node
  */
  std::string getType();

protected:
  // Properties
  // ---------------------------------------
  //! Binop type
  Type type;
};
