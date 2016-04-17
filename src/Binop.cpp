
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

bool Binop::execute(Environment& env)
{
  switch (this->type) {
    case Equal:
        env.write(EVAL_STR_LEFT, EVAL_RIGHT, LEFT->getLocal());
        return true;

  default:
    throw Error("Tried to execute invalid binary operation");
  }
}

Memory* Binop::eval(Environment& env)
{
  return new Memory(this->evalInt(env));
}

int Binop::evalInt(Environment& env)
{
  Memory *l = EVAL_LEFT, *r = EVAL_RIGHT;
  int left = l->evalInt(env), right = r->evalInt(env);
  delete l;
  delete r;

  switch (this->type) {
    case Addition:          return left + right;
    case Subtraction:       return left - right;
    case Division:          return left / right;
    case Multiplication:    return left * right;
    case Power:             return pow(left, right);
    case Modulo:            return left % right;
  default:
    throw Error("Tried to evaluate invalid integer value from binary operation");
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
