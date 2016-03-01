#pragma once

#include "Node.h"
#include "math.h"

//! Class for binary operations
/**
* @author Jim Ahlstrand
* @todo add test for number of children, binop can have max 2
*/
class Binop : public Node {
public:
    //! Defines types of Binops
    enum Type {
        Undefined,
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
    //! Constructor with type
    /**
    * @param type Binop type of enum Type
    */
    Binop(Type type);

    // Methods
    // ---------------------------------------
    //! Executes the Binop
    /**
    * @param env current Environment
    * @return integer value of the node
    */
    int execute(Environment& env);
    //! Converts type of node to string
    /**
    * @return string type of the node
    */
    std::string getType();

protected:
    // Properties
    // ---------------------------------------
    //! Binop type
    Type type;
};
