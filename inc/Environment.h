#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <map>
#include "Error.h"

class Memory;

/** Handles current memory scope
* @author Jim Ahlstrand
*/
class Environment {
  public:
    // Constructors
    // ---------------------------------------
    //! Default destructor
    virtual ~Environment();

    // Methods
    // ---------------------------------------
    /** Writes to memory
    * @param string name identifier
    * @param Memory* mem pointer to memory
    * @return int 0 if success
    */
    int write(std::string name, Memory* memory);
    /** reads from memory
    * @param string name identifier
    * @return integer value of the variable
    */
    Memory* read(std::string name);

  private:
    // Properties
    // ---------------------------------------
    //! Memory map
    std::map<std::string, Memory*> memory;
};
