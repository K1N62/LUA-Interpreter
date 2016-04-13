
#include "Memory.h"
#include "Node.h"
#include "Environment.h"

Environment::Environment()
{
  // Init return value
  this->memory["return"] = NULL;
  // Init parent scope
  this->parent = NULL;
}

Environment::Environment(Environment* parent)
{
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

int Environment::write(std::string name, Memory* memory, bool local)
{
  // return is a special case, always global
  if (name == "return" && this->parent != NULL) {
    return this->parent->write(name, memory);
  } else {
    // If varibale is found in this scope consider it local
    if (this->memory.find(name) != this->memory.end())
      local = true;
    // If it's a local variable or scope has no parent (global)
    if ( local || this->parent == NULL ) {
      try {
        // Check if key dosen't exists
        if ( this->memory.find(name) == this->memory.end() ) {

          if (debug) {
              if (memory->getType() == "Function")
                std::cout << " -> Writing to " << name << " = " << memory << " -> " << memory->getFunc() << " in: " << this << std::endl;
              else
                std::cout << " -> Writing to " << name << " = " << memory << " in: " << this << std::endl;
          }

          KEY = memory;
        }
        // Else delete old value and then write
        else {
          if (KEY != NULL)
            delete KEY;

          if (debug) {
            if (memory->getType() == "Function")
              std::cout << " -> Writing to " << name << " = " << memory << " -> " << memory->getFunc() << " in: " << this << std::endl;
            else
              std::cout << " -> Writing to " << name << " = " << memory << " in: " << this << std::endl;
          }

          KEY = memory;
        }
      } catch (std::exception& e) {
        std::cerr << " ! Error: " << e.what() << std::endl;
        return 1;
      }
    } else {
      // Else write variable to the parent scope
      return this->parent->write(name, memory);
    }
  }

  return 0;
}

//! This is shit
int Environment::write(std::string name, Node* node, bool local)
{
  // Check if node is of Memory type already
  //! @remark Really ugly this one is
  if (node->getType() == "Number"   ||
      node->getType() == "String"   ||
      node->getType() == "Function"  ||
      node->getType() == "FieldList"  ) {
    if (debug)
        std::cout << " ! Converting shitty Node to Memory " << std::endl;
    // Make copy of node
    Memory* mem = new Memory(); // Memory leaks?
    *mem = *dynamic_cast<Memory*>(node);
    return this->write(name, mem, local);
  } else {
    if (debug)
        std::cout << " ! Creating fake Memory to store expression results " << std::endl;
    // else assume it's an expression with numbers
    Memory* mem = new Memory(node->evalInt(*this));
    return this->write(name, mem, local);
  }
}

Memory* Environment::read(std::string name)
{
  // Return is special case, always global
  if (name == "return" && this->parent != NULL) {
    return this->parent->read(name);
  } else {
    // Check if key dosen't exists then check parent
    if ( this->memory.find(name) == this->memory.end() ) {
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
        throw Error("Variable not in scope: " + name);
      }
    } else {
      if (debug)
        std::cout << " ? Reading " << name << " in: " << this << std::endl;
      // Else key is in this scope
      return KEY;
    }
  }
}
