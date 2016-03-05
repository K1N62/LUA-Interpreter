
#include "Condition.h"

Condition::Condition() : Node()
{
  this->type = Type::Undefined;
}

Condition::Condition(Type type) : Node()
{
  this->type = type;
}

std::string Condition::getType()
{
    switch (type) {
        case Condition::Type::If:       return "If";
        case Condition::Type::ElseIf:   return "ElseIf";

        default:
          return "Undefined";
    }
}

bool Condition::execute(Environment& env)
{
    switch (this->type) {
        case If:
            if (EVAL_INT_LEFT) EXEC_RIGHT;
            else for (unsigned int i = 2; i < this->size(); i++)
                try {
                    if (this->getChild(i)->execute(env)) return true;
                } catch (std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            return true;
        case ElseIf:
            if (EVAL_INT_LEFT) {
                EXEC_RIGHT;
                return true;
            }
            return true;

    default:
        throw Error("Invalid contition");
    }
}
