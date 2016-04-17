#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <map>
#include "Error.h"

class Memory;
class Node;

#define KEY this->memory[name]

/** Handles current memory scope
* @author Jim Ahlstrand
* @remark no support for invisible variables
*/
class Environment {
  public:
    // Constructors
    // ---------------------------------------
    //! Default constructor
    Environment();
    /** Constructor with parent scope
    * @param parent Environment parent scope
    */
    Environment(Environment* parent);
    //! Default destructor
    virtual ~Environment();

    // Methods
    // ---------------------------------------
    /** Writes to memory
    * @param string name identifier
    * @param Memory* mem pointer to memory
    * @return int 0 if success
    */
    int write(std::string name, Memory* m, bool local = false);
    /** Writes to memory
    * @param string name identifier
    * @param Node* node pointer that needs evaluation
    * @return int 0 if success
    */
    int write(std::string name, Node* node, bool local = false);
    /** reads from memory
    * @param string name identifier
    * @return integer value of the variable
    */
    Memory* read(std::string name);
    /** Check if memory exists
    * @param string name identifier
    * @return bool, true if name is in memory
    */
    bool isReadable(std::string name) { return this->memory.find(name) != this->memory.end(); }

  private:
    // Properties
    // ---------------------------------------
    //! Memory map
    std::map<std::string, Memory*> memory;
    //! Pointer to parent environment
    Environment* parent;
};
