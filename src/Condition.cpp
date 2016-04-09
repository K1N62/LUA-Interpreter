
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
            for (auto child : this->children)
              try {
                  if (child->execute(env)) return true;
              } catch (std::exception& e) {
                  std::cerr << "Error: " << e.what() << std::endl;
              }
            return false;
        case ElseIf:
            return EXEC_LEFT;

    default:
        throw Error("Invalid contition");
    }
}
