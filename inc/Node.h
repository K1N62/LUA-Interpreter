#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Error.h"
#include "Environment.h"

#define TRUE    1
#define FALSE   0
#define EXEC_LEFT this->children[0]->execute(env)
#define EXEC_RIGHT this->children[1]->execute(env)

//! Class to build a non-specific tree-node
/**
* @author Jim Ahlstrand
*/
class Node {
public:
    //! Defines types of Nodes
    //! \bug unary minus missing
    //! \todo concatenate some of these types to one type with different values
    //! \todo implemetn local functions and namelists
    enum Type {
      Undefined,
      ExpressionList,
      VariableList,
      FunctionBody,
      FunctionName,
      FunctionCall,
      Function,
      MemberFunction,
      Variable,
      ListName,
      Range,
      Stat,
      Field,
      FieldList,
      FieldElement,
      Equal,
      DoubleDot,
      Hash,
      Negate,
      Name,
      Nil,
      Number,
      String,
      Tridot
    };

    // Constructors
    // ---------------------------------------
    //! Default constructor
    Node();
    //! Constructor with type
    /**
    * @param type Node type of enum Type
    */
    Node(Type type);
    //! Constructor with type and value
    /**
    * @param type Node type of enum Type
    * @param value String value of the node
    */
    Node(Type type, std::string value);
    //! Default destructor
    virtual ~Node();

    // Methods
    // ---------------------------------------
    //! Prints the node tree
    /**
    * @param id integer of currently highest node id
    * @param file ofstream file handler
    * @return id integer of this node id
    */
    int print(int id, std::ofstream& file);
    //! Adds a child to the node
    /**
    * @param child Node child to add
    * @return 0 on success else error
    */
    void addChild(Node* child) { this->children.push_back(child); }
    //! Gives a child of the node
    /**
    * @param i unsigned integer index of child
    * @return Node
    */
    Node* getChild(unsigned int i);
    //! Moves the end element to the front
    //! \remark ugly hack only used for field list correction
    /**
    * @return int 0 on success
    */
    int moveToFront();
    //! Gives the nodes id
    /**
    * @return id integer of nodes id
    */
    int getNodeID() { return this->id; }
    //! Is this node undefined?
    /**
    * @return id integer of nodes id
    */
    bool isUndefined() { return this->type == Undefined ? true : false; }
    //! Returns the number of childs in this node
    /**
    * @return id integer number of childs
    */
    unsigned int size() { return this->children.size(); }
    //! Executes the Node
    /**
    * @param env current Environment
    * @return integer value of the node
    */
    virtual int execute(Environment& env);
    //! Converts type of node to string
    /**
    * @return string type of the node
    */
    virtual std::string getType();

protected:
    // Methods
    // ---------------------------------------

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

//! Overloads the Node Type output stream operator
std::ostream& operator<<(std::ostream& out, const Node::Type& type);
