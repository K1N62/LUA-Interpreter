
#include "Environment.h"
#include "Memory.h"
#include "Binop.h"

Binop::Binop() : Node()
{
  this->type = Type::Undefined;
}

Binop::Binop(Type type) : Node()
{
  this->type = type;
}

std::string Binop::getType()
{
    switch (type) {
        case Binop::Type::Equal:            return "Equal";
        case Binop::Type::Addition:         return "Addition";
        case Binop::Type::Subtraction:      return "Subtraction";
        case Binop::Type::Division:         return "Division";
        case Binop::Type::Multiplication:   return "Multiplication";
        case Binop::Type::Power:            return "Power";
        case Binop::Type::Modulo:           return "Modulo";

        default:
            return "Undefined";
    }
}

//! @remark This small limits expressions to integers
bool Binop::execute(Environment& env)
{
  switch (this->type) {
    case Equal:
      env.write(VAL_LEFT, RIGHT);
      return true;

  default:
    throw Error("Tried to execute invalid binary operation");
  }
}

int Binop::evalInt(Environment& env)
{
  switch (this->type) {
    case Addition:          return EVAL_INT_LEFT + EVAL_INT_RIGHT;
    case Subtraction:       return EVAL_INT_LEFT - EVAL_INT_RIGHT;
    case Division:          return EVAL_INT_LEFT / EVAL_INT_RIGHT;
    case Multiplication:    return EVAL_INT_LEFT * EVAL_INT_RIGHT;
    case Power:             return pow(EVAL_INT_LEFT, EVAL_INT_RIGHT);
    case Modulo:            return EVAL_INT_LEFT % EVAL_INT_RIGHT;
  default:                  throw Error("Tried to evaluate invalid integer value from binary operation");
  }
}

//! @remark this is ugly but works
std::string Binop::evalStr(Environment& env)
{
  std::string val = std::to_string(this->evalInt(env));

  if (debug)
    std::cout << "Binary operation evaluated as string: " << val << std::endl;

  return val;
}
