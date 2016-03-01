
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

int Loop::execute(Environment& env)
{
    switch (this->type) {
        case Repeat:
            while (!EXEC_RIGHT) EXEC_LEFT;
            return TRUE;
        case While:
            while (EXEC_LEFT) EXEC_RIGHT;
            return TRUE;
        case For:
            //! \todo implement for loop execution
            return TRUE;
        case Do:
            //! \todo implement do loop execution
            return TRUE;
    default:
        throw Error("Invalid binary operation");
    }
}
