
#include "Test.h"

Test::Test() : Node()
{
  this->type = Type::Undefined;
}

Test::Test(Type type) : Node()
{
  this->type = type;
}

std::string Test::getType()
{
    switch (type) {
        case Test::Type::LessThan:          return "LessThan";
        case Test::Type::LessOrEqual:       return "LessOrEqual";
        case Test::Type::GreaterThan:       return "GreaterThan";
        case Test::Type::GreaterOrEqual:    return "GreaterOrEqual";
        case Test::Type::EqualEqual:        return "EqualEqual";
        case Test::Type::NotEqual:          return "NotEqual";
        case Test::Type::And:               return "And";
        case Test::Type::Or:                return "Or";
        case Test::Type::Not:               return "Not";
        case Test::Type::False:             return "False";
        case Test::Type::True:              return "True";

        default:                            return "Undefined";
    }
}

int Test::execute(Environment& env)
{
    switch (this->type) {
        case LessThan:          return EXEC_LEFT < EXEC_RIGHT;
        case LessOrEqual:       return EXEC_LEFT <= EXEC_RIGHT;
        case GreaterThan:       return EXEC_LEFT > EXEC_RIGHT;
        case GreaterOrEqual:    return EXEC_LEFT >= EXEC_RIGHT;
        case EqualEqual:        return EXEC_LEFT == EXEC_RIGHT;
        case NotEqual:          return EXEC_LEFT != EXEC_RIGHT;
        case And:               return EXEC_LEFT && EXEC_RIGHT;
        case Or:                return EXEC_LEFT || EXEC_RIGHT;
        case Not:               return !EXEC_LEFT;
        case False:             return FALSE;
        case True:              return TRUE;
    default:                    throw Error("Invalid test case");
    }
}
