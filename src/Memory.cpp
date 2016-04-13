
#include "Memory.h"

Memory::Memory() : Node()
{
    if (debug)
        std::cout << " + Creating new FieldList " << " ( " << this << " )" << std::endl;
    this->type = Type::FieldList;
    this->func = NULL;
}

Memory::Memory(int value, bool local) : Node()
{
    if (debug)
        std::cout << " + Creating new Integer " << " ( " << this << " )" << std::endl;
    this->type = Type::Number;
    this->integer = value;
    this->value = std::to_string(value);
    this->local = local;
    this->func = NULL;
}

Memory::Memory(std::string value, bool local) : Node()
{
    if (debug)
        std::cout << " + Creating new String " << " ( " << this << " )" << std::endl;
    this->type = Type::String;
    this->value = value;
    this->str = value;
    this->local = local;
    this->func = NULL;
}

Memory::Memory(Node* func, bool local) : Node()
{
    if (debug)
        std::cout << " + Creating new Function " << " ( " << this << " )" << std::endl;
 	this->type = Type::Function;
 	this->func = func;
 	this->local = local;
}

Memory::~Memory()
{
    if (debug)
        std::cout << " - Deleting memory " << getType() << " ( " << this << " )" << std::endl;
    //if (this->func != NULL)
    //    delete this->func;
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
            if (this->func != NULL) {
                if (debug)
                        std::cout << " $ Executing function ( " << this << " )" << std::endl;
                return this->func->execute(env);
            } else
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
