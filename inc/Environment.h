#pragma once

#include <string>
#include <map>

//! Environment class to handle variables
/**
* @author Jim Ahlstrand
*/
class Environment {
  public:

    // Constructors
    // ---------------------------------------
    //! Default constructor
    Environment();
    //! Default destructor
    virtual ~Environment();

    // Methods
    // ---------------------------------------


  private:
    // Properties
    // ---------------------------------------
    //! Map of variable names and their values
    std::map<std::string, std::string> var;
};
