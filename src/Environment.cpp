
#include "Memory.h"
#include "Environment.h"

Environment::~Environment()
{
  #if (DEBUG)
    std::cout << "-=Deleting environment=-" << std::endl;
  #endif

  for (std::map<std::string, Memory*>::iterator it = this->memory.begin(); it != this->memory.end(); it++)
    delete it->second;
}

int Environment::write(std::string name, Memory* memory)
{
  try {
    // Check if key exists
    if ( this->memory.find(name) == this->memory.end() ) {
      #if (DEBUG)
        std::cout << "writing to " << name << ": " << memory << std::endl;
      #endif
      this->memory[name] = memory;
    }
    // Else delete old value and then write
    else {
      delete this->memory[name];
      #if (DEBUG)
        std::cout << "writing to " << name << " = " << memory << std::endl;
      #endif
      this->memory[name] = memory;
    }
  } catch (std::exception& e) {
    std::cerr << "Error (Memory): " << e.what() << std::endl;
    return 1;
  }

  return 0;
}

Memory* Environment::read(std::string name)
{
  #if (DEBUG)
    std::cout << "reading " << name << std::endl;
  #endif

  // Check if key exists
  if ( this->memory.find(name) == this->memory.end() )
    throw Error("Trying to read uninitialized memory " + name);

  return this->memory[name];
}
