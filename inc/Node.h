#pragma once

#define TRUE            1
#define FALSE           0
#define LEFT            this->children[0]
#define RIGHT           this->children[1]
#define VAL_LEFT        LEFT->getValue()
#define VAL_RIGHT       RIGHT->getValue()
#define EXEC_LEFT       LEFT->execute(env)
#define EXEC_RIGHT      RIGHT->execute(env)
#define EVAL_INT_LEFT   LEFT->evalInt(env)
#define EVAL_INT_RIGHT  RIGHT->evalInt(env)
#define EVAL_STR_LEFT   LEFT->evalStr(env)
#define EVAL_STR_RIGHT  RIGHT->evalStr(env)

// Settings
#define DEBUG true
#define PRINT_LEAF_VALUES true

// Includes
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Error.h"

class Environment;

/** Builds a tree-node structure
* @author Jim Ahlstrand
*/
class Node {
public:
  //! Defines types of Nodes
  //! @todo implement local functions and namelists
  enum Type {
    Undefined,
    ExpressionList, //! @todo implement
    VariableList, //! @todo implement
    FunctionName,
    FunctionCall,
    FunctionBody,
    Function,
    MemberFunction, //! @todo implement
    ListName, //! @todo implement
    Stat,
    Field, //! @todo implement
    FieldElement, //! @todo implement
    DoubleDot, //! @todo implement
    Hash,
    Negate, //! @todo implement
    Name,
    Tridot, //! @todo implement
    Return //! @todo implement
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Node();
  /** Constructor with type
  * @param type Node type of enum Type
  */
  Node(Type type);
  /** Constructor with type and value
  * @param type Node type of enum Type
  * @param value String value of the node
  */
  Node(Type type, std::string value);
  //! Default destructor
  virtual ~Node();

  // Methods
  // ---------------------------------------
  /** Prints the node tree
  * @param id integer of currently highest node id
  * @param file ofstream file handler
  * @return id integer of this node id
  */
  int print(int id, std::ofstream& file);
  /** Adds a child to the node
  * @param child Node child to add
  * @return 0 on success else error
  */
  void addChild(Node* child) { this->children.push_back(child); }
  /** Gives a child of the node
  * @param i unsigned integer index of child
  * @return Node
  */
  Node* getChild(unsigned int i);
  /** Moves the end element to the front
  * @return int 0 on success
  * @remark ugly hack only used for field list correction
  */
  int moveToFront();
  /** Gives the nodes id
  * @return id integer of nodes id
  */
  int getNodeID() { return this->id; }
  /** Is this node undefined?
  * @return id integer of nodes id
  */
  bool isUndefined() { return this->type == Undefined ? true : false; }
  /** Returns the number of childs in this node
  * @return id integer number of childs
  */
  unsigned int size() { return this->children.size(); }
  /** Executes the Node
  * @param env current Environment
  * @return bool true if node did execute
  */
  virtual bool execute(Environment& env);
  /** Evaluate integer value of the Node
  * @param env current Environment
  * @return integer value of the node
  */
  virtual int evalInt(Environment& env);
  /** Evaluate string value of the Node
  * @param env current Environment
  * @return string value of the node
  */
  virtual std::string evalStr(Environment& env);
  /** Converts type of node to string
  * @return string type of the node
  */
  virtual std::string getType();
  /** Gets the nodes value.
  * @return string value of the node
  */
  std::string getValue() { return this->value; }

protected:
  // Properties
  // ---------------------------------------
  //! Node id
  int id;
  //! Node type
  Type type;
  //! Node value
  std::string value;
  //! The children connected to the node
  std::vector<Node*> children;
};
