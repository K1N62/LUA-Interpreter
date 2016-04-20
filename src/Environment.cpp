
#include "Memory.h"
#include "Node.h"
#include "Environment.h"

Environment::Environment()
{
  if (debug)
    std::cout << " + Creating new Environment ( " << &f << " )" << std::endl;

  // Init return value
  this->memory["return"] = NULL;
  // Init parent scope
  this->parent = NULL;
}

Environment::Environment(Environment* parent)
{
  if (debug)
    std::cout << " + Creating new Environment ( " << &f << " ) -> " << &env << std::endl;

  // Init return value
  this->memory["return"] = NULL;
  // Init parent scope
  this->parent = parent;
}

Environment::~Environment()
{
    if (debug)
        std::cout << " - Deleting environment: " << this << std::endl;

    for (std::map<std::string, Memory*>::iterator it = this->memory.begin(); it != this->memory.end(); it++)
        if (it->second != NULL)
            delete it->second;
}

int Environment::write(std::string name, Memory* m, bool local)
{
  // return is a special case, always global
  if (name == "return" && this->parent != NULL) {
    return this->parent->write(name, m);
  } else {
    // If varibale is found in this scope consider it local
    if (this->memory.find(name) != this->memory.end())
      local = true;
    // If it's a local variable or scope has no parent (global)
    if ( local || this->parent == NULL ) {
      try {
        // Check if key dosen't exists
        if ( !this->isReadable(name) ) {
          if (debug) {
              if (m->getType() == "Function")
                std::cout << " -> Writing to " << name << " = " << m << " -> " << m->getFunc() << " in: " << this << std::endl;
              else
                std::cout << " -> Writing to " << name << " = " << m << " in: " << this << std::endl;
          }
          KEY = m;
        }
        // Else delete old value and then write
        else {
          if (KEY != NULL)
            delete KEY;

          if (debug) {
            if (m->getType() == "Function")
              std::cout << " -> Writing to " << name << " = " << m << " -> " << m->getFunc() << " in: " << this << std::endl;
            else
              std::cout << " -> Writing to " << name << " = " << m << " in: " << this << std::endl;
          }
          KEY = m;
        }
      } catch (std::exception& e) {
        std::cerr << " ! Error: " << e.what() << std::endl;
        return 1;
      }
    } else {
      // Else write variable to the parent scope
      return this->parent->write(name, m);
    }
  }

  return 0;
}

Memory* Environment::read(std::string name)
{
  // Return is special case, always global
  if (name == "return" && this->parent != NULL) {
    return this->parent->read(name);
  } else {
    // Check if key dosen't exists then check parent
    if ( !this->isReadable(name) ) {
      // Try to access variable from parent scope
      if ( this->parent != NULL ) {
        try {
          // Try finding key in the parent scope
          return this->parent->read(name);
        } catch (std::exception& e) {
          throw e;
        }
      } else {
        // Key is not declared anywhere
        //throw Error("Tried to access undeclared variable");
        return new Memory(); //! @warning potential memoryleak
      }
    } else {
      if (debug)
        std::cout << " ? Reading " << name << " in: " << this << std::endl;
      // Else key is in this scope
      return KEY;
    }
  }
}
