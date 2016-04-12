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
    FieldList
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  //! @remark is assumed to be a field list
  Memory();
  /** Constructor with integer type
  * @param value integer value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(int value, bool local = false);
  /** Constructor with string type
  * @param value string value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(std::string value, bool local = false);
  /** Constructor with function type
  * @param func Node* value of the node
  * @param local Bool True if defined in local namespace
  */
  Memory(Node* func, bool local = false);
  //! Default destructor
  virtual ~Memory();

  // Methods
  // ---------------------------------------
  /** Executes the Node
  * @param env current Environment
  * @return bool true if node did execute
  */
  bool execute(Environment& env);
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
  * @remark length of list returns number of elements in list
  * @remark length of string returns number of characters in string
  * @remark length of integer & function throws an exception
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
