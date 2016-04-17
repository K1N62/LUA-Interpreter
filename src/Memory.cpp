
#include "Memory.h"
#include "Environment.h"

Memory::Memory() : Node()
{
    this->type          = Type::Nil;
    this->str           = "Nil";
    this->integer       = 0;
    this->func          = NULL;
}

Memory::Memory(int value) : Node()
{
    if (debug)
        std::cout << " + Creating new Integer " << " ( " << this << " )" << std::endl;
    this->type          = Type::Number;
    this->str           = std::to_string(value);
    this->integer       = value;
    this->func          = NULL;
}

Memory::Memory(std::string value, bool isConstant) : Node()
{
    if (debug)
        std::cout << " + Creating new String " << " ( " << this << " )" << std::endl;
    this->type          = isConstant ? Type::String : Type::Variable;
    this->str           = value;
    this->integer       = 0;
    this->func          = NULL;
}

Memory::Memory(Node* func, bool isSoftLink) : Node()
{
    if (debug)
        std::cout << " + Creating new Function " << " ( " << func << " )" << std::endl;
 	this->type          = Type::Function;
    this->str           = "*func";
    this->integer       = 0;
 	this->func          = func;
 	this->isSoftLink    = isSoftLink;
}

Memory::~Memory()
{
    if (debug)
        std::cout << " - Deleting memory " << getType() << " ( " << this << " )" << std::endl;
    if (this->func != NULL && !this->isSoftLink)
        delete this->func;
}

std::string Memory::getType()
{
  switch (this->type) {
    case Nil:           return "Nil";
    case Number:        return "Number";
    case String:        return "String";
    case Function:      return "Function";
    case Variable:      return "Variable";

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

Memory* Memory::eval(Environment& env)
{
    Memory* m;
    switch (this->type) {
        case Variable:
            m = new Memory();
            *m = *env.read(this->str);
            return m;
        case Nil:           return new Memory();
        case Number:        return new Memory(this->integer);
        case String:        return new Memory(this->str);
        case Function:      return new Memory(this->func, true);

        default:
            return NULL;
    }
}

int Memory::evalInt(Environment& env)
{
    return this->integer;
}

std::string Memory::evalStr(Environment& env)
{
    return this->str;
}

unsigned int Memory::length()
{
  switch (this->type) {
    case Nil:       return 0;
    case String:    return this->str.length();
    case Function:  return this->func->size();
    case Number:    return sizeof(this->integer);

  default:
    throw Error("Tried to evaluate invalid length");
  }
}
