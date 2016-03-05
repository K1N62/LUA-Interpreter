
#include "Test.h"

Test::Test() : Node()
{
  this->type = Type::Undefined;
  this->value = "false";
}

Test::Test(Type type) : Node()
{
  this->type = type;
  if (type == Type::False)
    this->value = "false";
  else if (type == Type::True)
    this->value = "true";
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

int Test::evalInt(Environment& env)
{
    switch (this->type) {
        case LessThan:          return EVAL_INT_LEFT < EVAL_INT_RIGHT ? TRUE : FALSE;
        case LessOrEqual:       return EVAL_INT_LEFT <= EVAL_INT_RIGHT ? TRUE : FALSE;
        case GreaterThan:       return EVAL_INT_LEFT > EVAL_INT_RIGHT ? TRUE : FALSE;
        case GreaterOrEqual:    return EVAL_INT_LEFT >= EVAL_INT_RIGHT ? TRUE : FALSE;
        case EqualEqual:        return EVAL_INT_LEFT == EVAL_INT_RIGHT ? TRUE : FALSE;
        case NotEqual:          return EVAL_INT_LEFT != EVAL_INT_RIGHT ? TRUE : FALSE;
        case And:               return EVAL_INT_LEFT && EVAL_INT_RIGHT ? TRUE : FALSE;
        case Or:                return EVAL_INT_LEFT || EVAL_INT_RIGHT ? TRUE : FALSE;
        case Not:               return !EVAL_INT_LEFT ? TRUE : FALSE;
        case False:             return FALSE;
        case True:              return TRUE;
    default:                    throw Error("Invalid test case");
    }
}

std::string Test::evalStr(Environment& env)
{
  return this->execute(env) == true ? "true" : "false";
}
