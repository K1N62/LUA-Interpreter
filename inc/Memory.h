#pragma once

#include "Node.h"

/** Handles memory operations
* @author Jim Ahlstrand
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
  * @param type Memory type of enum Type
  * @param value integer value of the node
  */
  Memory(int value);
  /** Constructor with string type
  * @param type Memory type of enum Type
  * @param value string value of the node
  */
  Memory(std::string value);
  /** Constructor with function type
  * @param type Memory type of enum Type
  * @param func Node* value of the node
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
