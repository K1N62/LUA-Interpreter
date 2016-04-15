#pragma once

#include "Node.h"

/** Handles memory operations
* @author Jim Ahlstrand
* @todo implement support for float variables and infinite large int
*/
class Memory : public Node {
public:
  //! Defines types of Memory
  enum Type {
      Nil,
      Number,
      String,
      Function,
      Variable,
  };
  //! @todo fix Fieldlist, ex. local and function calls
  // Constructors
  // ---------------------------------------
  //! Default constructor
  //! @remark is assumed to be a field list
  Memory();
  /** Constructor with integer type
  * @param value integer value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(int value);
  /** Constructor with string type
  * @param value string value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(std::string value, bool isConstant = false);
  /** Constructor with function type
  * @param func Node* value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(Node* func);
  //! Default destructor
  virtual ~Memory();

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
  /** Evaluate integer of the Memory
  * @param env current Environment
  * @return integer value of the node
  */
  int evalInt(Environment& env);
  /** Evaluate string of the Memory
  * @param env current Environment
  * @return string value of the node
  */
  std::string evalStr(Environment& env);
  /** Converts type of node to string
  * @return string type of the node
  */
  std::string getType();
  /** Gets the function pointer
  * @return Node* pointer to the function node
  */
  Node* getFunc() { return this->func; }
  /** Gets the integer value
  * @return integer
  */
  int getInt() { return this->integer; }
  /** Gets the string value
  * @return string
  */
  std::string getStr() { return this->str; }
  /** Get length of Memory
  * @return unsigned int length of Memory
  * @remark Depends on type
  */
  unsigned int length();

protected:
  // Properties
  // ---------------------------------------
  //! Memory type
  Type type;
  //! Integer value
  int integer;
  //! String value
  std::string str;
  //! Function pointer
  Node* func;
};
