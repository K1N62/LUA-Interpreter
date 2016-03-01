
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

int Binop::execute(Environment& env)
{
    switch (this->type) {
        case Addition:          return EXEC_LEFT + EXEC_RIGHT;
        case Subtraction:       return EXEC_LEFT - EXEC_RIGHT;
        case Division:          return EXEC_LEFT / EXEC_RIGHT;
        case Multiplication:    return EXEC_LEFT * EXEC_RIGHT;
        case Power:             return pow(EXEC_LEFT, EXEC_RIGHT);
        case Modulo:            return EXEC_LEFT % EXEC_RIGHT;
    default:                    throw Error("Invalid binary operation");
    }
}
