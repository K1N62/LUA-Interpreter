#pragma once

#include "Node.h"

/** Handles contitional operations
* @author Jim Ahlstrand
*/
class Condition : public Node {
public:
    //! Defines types of Conditions
    enum Type {
        Undefined,
        If,
        ElseIf
    };

    // Constructors
    // ---------------------------------------
    //! Default constructor
    Condition();
    /** Constructor with type
    * @param type Condition type of enum Type
    */
    Condition(Type type);

    // Methods
    // ---------------------------------------
    /** Executes the Condition
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
    //! Condition type
    Type type;
};
