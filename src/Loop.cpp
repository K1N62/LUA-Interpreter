
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
        case Loop::Type::Do:        return "Do";

    default:
        return "Undefined";
    }
}

bool Loop::execute(Environment& env)
{
    switch (this->type) {
        case Repeat:
            while (!EVAL_INT_RIGHT) EXEC_LEFT; //! @bug won't run first time if right isn't true
            return true;
        case While:
            while (EVAL_INT_LEFT) EXEC_RIGHT;
            return true;
        case For:
            //! \todo implement for loop execution
            return true;
        case Do:
            //! \todo implement do loop execution
            return true;
    default:
        throw Error("Invalid binary operation");
    }
}
