
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

    default:
        return "Undefined";
    }
}

bool Loop::execute(Environment& env)
{
    // Make a new scope
    Environment f(&env);

    switch (this->type) {
        case Repeat:
            // Execute then test, testFirst flag is set in parser
            while (!LEFT->execute(f));
            return true;
        case While:
            // Test then execute
            while (LEFT->execute(f));
            return true;
        case For:
            return true;
    default:
        throw Error("Invalid binary operation");
    }
}
