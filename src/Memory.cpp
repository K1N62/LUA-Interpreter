
#include "Memory.h"

Memory::Memory() : Node()
{
  this->type = Type::FieldList;
  this->func = NULL;
}

Memory::Memory(int value) : Node()
{
  this->type = Type::Number;
  this->integer = value;
  this->value = std::to_string(value);
  this->func = NULL;
}

Memory::Memory(std::string value) : Node()
{
  this->type = Type::String;
  this->value = value;
  this->str = value;
  this->func = NULL;
}

Memory::Memory(Node* func) : Node()
{
  this->type = Type::Function;
  this->func = func;
}

Memory::~Memory()
{
  #if (DEBUG)
    std::cout << " - Deleting memory " << getType() << " ( " << this << " )" << std::endl;
  #endif
}

std::string Memory::getType()
{
  switch (this->type) {
    case Nil:           return "Nil";
    case Number:        return "Number";
    case String:        return "String";
    case Function:      return "Function";
    case FieldList:     return "FieldList";

    default:
      return "Undefined";
  }
}

bool Memory::execute(Environment& env)
{
  switch (this->type) {
    case Function:
      if (this->func != NULL)
        return this->func->execute(env);
      else
        throw Error("Tried to execute null function");

  default:
    throw Error("Tried to execute non-executable memory (" + this->getType() + ")");
  }
}

int Memory::evalInt(Environment& env)
{
  switch (this->type) {
    case Nil:       return 0;
    case Number:    return this->integer;
    case String:    return stoi(this->str);

  default:
    throw Error("Tried to evaluate invalid integer value from constant");
  }
}

std::string Memory::evalStr(Environment& env)
{
  switch (this->type) {
    case Nil:       return "";
    case Number:    return std::to_string(this->integer);
    case String:    return this->str;

  default:
    throw Error("Tried to evaluate invalid string value from constant");
  }
}

unsigned int Memory::length()
{
  switch (this->type) {
    case Nil:       return 0;
    case String:    return this->str.length();
    case FieldList: return this->size();

  default:
    throw Error("Tried to evaluate invalid string value from constant");
  }
}
