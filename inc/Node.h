#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

//! Node class to build node tree
/**
* @author Jim Ahlstrand
*/
class Node {
  public:
    //! Defines types of Nodes
    //! \todo concatenate some of these types to one type with different values
    enum Type {
      Undefined,
      ExpressionList,
      VariableList,
      FunctionBody,
      FunctionName,
      FunctionCall,
      Function,
      MemberVariable,
      MemberFunction,
      Variable,
      ListName,
      Range,
      Repeat,
      While,
      For,
      If,
      ElseIf,
      Stat,
      Field,
      Equal,
      Addition,
      Subtraction,
      Division,
      Multiplication,
      Power,
      Modulo,
      DoubleDot,
      LessThan,
      LessOrEq,
      GreaterThan,
      GreaterOrEq,
      Test,
      NotEq,
      And,
      Or,
      Not,
      Hash,
      Comma,
      SemiColon,
      Name,
      Nil,
      False,
      True,
      Number,
      String,
      Tridot
    };

    // Constructors
    //! Default constructor
    Node();
    //! Constructor with type
    /**
    * @author Jim Ahlstrand
    * @param type Node type of enum Type
    */
    Node(Type type);
    //! Constructor with type and value
    /**
    * @author Jim Ahlstrand
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
    * @author Jim Ahlstrand
    * @param id integer of currently highest node id
    * @param file ofstream file handler
    * @return id integer of this node id
    */
    int print(int id, std::ofstream& file);
    //! Adds a child to the node
    /**
    * @author Jim Ahlstrand
    * @param child Node child to add
    * @return 0 on success else error
    */
    int addChild(Node& child);
    //! Gives a child of the node
    /**
    * @author Jim Ahlstrand
    * @param i unsigned integer index of child
    * @return Node
    */
    Node getChild(unsigned int i);
    //! Gives the nodes id
    /**
    * @author Jim Ahlstrand
    * @return id integer of nodes id
    */
    int getNodeID() { return this->id; }
    //! Is this node undefined?
    /**
    * @author Jim Ahlstrand
    * @return id integer of nodes id
    */
    bool isUndefined() { return this->type == Undefined ? true : false; }
    //! Returns the number of childs in this node
    /**
    * @author Jim Ahlstrand
    * @return id integer number of childs
    */
    int size() { return this->children.size(); }

  private:
    // Properties
    // ---------------------------------------
    //! Node id
    int id;
    //! Node type
    Type type;
    //! Node value
    std::string value;
    //! The children connected to the node
    std::vector<Node> children;
};
