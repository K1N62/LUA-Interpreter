#pragma once

#define TRUE            1
#define FALSE           0
#define LEFT            this->children[0]
#define RIGHT           this->children[1]
#define EXEC_LEFT       LEFT->execute(env)
#define EXEC_RIGHT      RIGHT->execute(env)
#define EVAL_LEFT       LEFT->eval(env)
#define EVAL_RIGHT      RIGHT->eval(env)
#define EVAL_INT_LEFT   LEFT->evalInt(env)
#define EVAL_INT_RIGHT  RIGHT->evalInt(env)
#define EVAL_STR_LEFT   LEFT->evalStr(env)
#define EVAL_STR_RIGHT  RIGHT->evalStr(env)

// Includes
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "Error.h"

extern bool debug;

class Environment;
class Memory;

/** Builds a tree-node structure
* @author Jim Ahlstrand
*/
class Node {
public:
  //! Defines types of Nodes
  //! @todo implement local functions and namelists
  enum Type {
    Undefined,
    ExpressionList,     //! @todo Implement this
    VariableList,       //! @todo Implement this
    FunctionName,
    FunctionCall,
    FunctionBody,
    MemberFunction,     //! @todo Implement this
    ListName,           //! @todo Implement this
    Stat,
    Field,              //! @todo Implement this
    FieldElement,       //! @todo Implement this
    DoubleDot,          //! @todo Implement this
    Hash,
    Negate,             //! @todo Implement this
    Tridot,             //! @todo Implement this
    Return,
    Do,                 //! @todo Implement this
    Test,               //! @remark should be restructured, moved to testclass?
  };

  // Constructors
  // ---------------------------------------
  //! Default constructor
  Node();
  /** Constructor with type
  * @param type Node type of enum Type
  */
  Node(Type type);
  //! Default destructor
  virtual ~Node();

  // Methods
  // ---------------------------------------
  /** Prints the node tree
  * @param id integer of currently highest node id
  * @param file ofstream file handler
  * @return id integer of this node id
  */
  int print(int id, std::ofstream& file, Environment& env);
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
  /** Reorders tha children in reverse
  * @return void
  */
  void reverse() { std::reverse(this->children.begin(), this->children.end()); }
  /** Transfers children to parent
  * @param parent Node* pointer to the parent node
  * @return Node
  */
  void transferChildren(Node* parent);
  /** Moves the end element to the front
  * @return int 0 on success
  * @remark ugly hack only used for field list correction
  */
  int moveToFront();
  /** Gets the node id
  * @return id integer of nodes id
  */
  int getNodeID() { return this->id; }
  /** Gets if this node is local only
  * @return bool True if node is local
  */
  bool getLocal() { return this->local; }
  /** Set local value
  * @return bool True if node is local
  */
  void setLocal(bool l) { this->local = l; }
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
  /** Evaluate value of node
  * @remark It's the callers responsiblility to delete the returned memory
  * @param env current Environment
  * @return Memory* Pointer to memory with value of node
  */
  virtual Memory* eval(Environment& env);
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
  //! Set testFirst value
  /**
  * @param bool b testFirst value
  * @return void
  */
  void setTestFirst(bool b) { this->testFirst = b; }

protected:
  // Properties
  // ---------------------------------------
  //! Test before or after execute?
  bool testFirst;
  //! Node id
  int id;
  //! Localy defined
  bool local;
  //! Node type
  Type type;
  //! The children connected to the node
  std::vector<Node*> children;
};
