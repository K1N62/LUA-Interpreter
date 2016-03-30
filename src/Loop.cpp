
#include "Environment.h"
#include "Loop.h"

Loop::Loop() : Node()
{
    this->type = Type::Undefined;
}

Loop::Loop(Type type) : Node()
{
    this->type = type;
}

std::string Loop::getType()
{
    switch (type) {
        case Loop::Type::Repeat:    return "Repeat";
        case Loop::Type::While:     return "While";
        case Loop::Type::For:       return "For";

    default:
        return "Undefined";
    }
}

bool Loop::execute(Environment& env)
{
    // Make a new scope
    Environment f(&env);
    if (debug)
      std::cout << " + Creating new Environment ( " << &f << " ) -> " << &env << std::endl;

    switch (this->type) {
        case Repeat:
            while (!EVAL_INT_RIGHT) LEFT->execute(f); //! @bug won't run first time if right isn't true
            return true;
        case While:
            while (EVAL_INT_LEFT) RIGHT->execute(f);
            return true;
        case For:
            return true;
    default:
        throw Error("Invalid binary operation");
    }
}
