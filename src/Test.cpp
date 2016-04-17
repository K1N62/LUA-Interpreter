
#include "Test.h"
#include "Memory.h"

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

int Test::evalInt(Environment& env)
{
    Memory *l = EVAL_LEFT, *r = EVAL_RIGHT;
    int left = l->evalInt(env), right = r->evalInt(env);
    delete l;
    delete r;

    switch (this->type) {
        case LessThan:          return left < right ? TRUE : FALSE;
        case LessOrEqual:       return left <= right ? TRUE : FALSE;
        case GreaterThan:       return left > right ? TRUE : FALSE;
        case GreaterOrEqual:    return left >= right ? TRUE : FALSE;
        case EqualEqual:        return left == right ? TRUE : FALSE;
        case NotEqual:          return left != right ? TRUE : FALSE;
        case And:               return left && right ? TRUE : FALSE;
        case Or:                return left || right ? TRUE : FALSE;
        case Not:               return !left ? TRUE : FALSE;
        case False:             return FALSE;
        case True:              return TRUE;
    default:                    throw Error("Invalid test case");
    }
}

std::string Test::evalStr(Environment& env)
{
  return this->execute(env) == true ? "true" : "false";
}
