
#include "Environment.h"
#include "Memory.h"
#include "Node.h"

Node::Node()
{
  this->id = 0;
  this->type = Type::Undefined;
  this->local = false;
}

Node::Node(Type type)
{
  this->id = 0;
  this->type = type;
  this->local = false;
}

Node::~Node()
{
    for (auto child : this->children)
        delete child;
}

std::string Node::getType()
{
    switch (this->type) {
        case Node::Type::ExpressionList:  return "ExpressionList";
        case Node::Type::VariableList:    return "VariableList";
        case Node::Type::FunctionName:    return "FunctionName";
        case Node::Type::FunctionCall:    return "FunctionCall";
        case Node::Type::FunctionBody:    return "FunctionBody";
        case Node::Type::MemberFunction:  return "MemberFunction";
        case Node::Type::ListName:        return "ListName";
        case Node::Type::Stat:            return "Stat";
        case Node::Type::Field:           return "Field";
        case Node::Type::FieldElement:    return "FieldElement";
        case Node::Type::DoubleDot:       return "DoubleDot";
        case Node::Type::Hash:            return "Hash";
        case Node::Type::Negate:          return "Negate";
        case Node::Type::Tridot:          return "Tridot";
        case Node::Type::Return:          return "Return";
        case Node::Type::Do:              return "Do";
        case Node::Type::Test:            return "Test";

        default:
            return "Undefined";
    }
}

int Node::print(int id, std::ofstream& file, Environment& env)
{
    // Print children first to get correct id order
    if (this->getType() == "Function")
        id = dynamic_cast<Memory*>(this)->getFunc()->print(id, file, env);
    else
        for (auto child : this->children)
            id = child->print(id, file, env);

  // Grab this id
  this->id = ++id;

  // Print this tag
  if (this->children.size() == 0) {
      file << this->id << " " << "[label=\""<< this->getType() << "\\n" << this->evalStr(env) << "\"]" << std::endl;
  } else {
      file << this->id << " " << "[label=\"" << this->getType() << "\"]" << std::endl;
  }

  // Print link to children
  for(auto child : this->children)
    file << this->id << " -> " << child->getNodeID() << std::endl;

  return this->id;
}

Node* Node::getChild(unsigned int i)
{
  if ( i > this->children.size() - 1 || this->children.size() == 0 )
    return NULL;

  return this->children[i];
}

int Node::moveToFront()
{

  Node* tmp = this->children.back();
  this->children.pop_back();
  this->children.insert(this->children.begin(), tmp);

  return 0;
}

bool Node::execute(Environment& env)
{
  switch (this->type) {
    case FunctionBody:
      if (debug)
        std::cout << " $ Executing function ( " << this << " )" << std::endl;
      this->size() == 1 ? EXEC_LEFT : EXEC_RIGHT;
      return true;
    case FunctionCall:
      if (EVAL_STR_LEFT == "print") {
          Memory* t = EVAL_RIGHT;
          std::cout << t->evalStr(env) << std::endl;
          delete t;
      }
      else if (LEFT->getType() == "MemberFunction") {
        if (EVAL_STR_LEFT == "io") {
          if (EVAL_STR_RIGHT == "read" ) {
            std::string tmp;
            getline(std::cin, tmp);
            std::cin.clear();
            //! @remark Some flushing required?
            Memory* mem = new Memory(tmp);
            env.write("return", mem);
        } else if (EVAL_STR_RIGHT == "write" ) {
            //! @bug doesn't output \n character
            std::cout << EVAL_STR_RIGHT;
          }
        }
      } else {
        Node* func = env.read(EVAL_STR_LEFT)->getFunc();

        // Make a new scope
        Environment f(&env);
        if (debug)
          std::cout << " + Creating new Environment ( " << &f << " ) -> " << &env << std::endl;

        //! @bug this does not include Nil values when no parameters were passed it assumes equal #params
        //! @todo fix this mess
        // Do we have any parameters?
        Node* paramList = func->getChild(0);
        if (paramList->size() == 1) {
            Node* param = paramList->getChild(0);
            f.write(param->evalStr(env), EVAL_RIGHT, true);
        } else if (paramList->size() > 1) {
            // For each parameter get the value supplied in the call
            for ( size_t i = 0; i < paramList->size(); i++) {
                f.write(paramList->getChild(i)->evalStr(env), RIGHT->getChild(i)->eval(env), true);
            }
        }

        if (debug)
          std::cout << " -=[ Calling: " << EVAL_STR_LEFT << " ( " << LEFT << " ) ]=-" << std::endl;
        // Execute function
        func->execute(f); // @bug don't work with memberfunction
      }
      return true;
    case Return:
        env.write("return", EVAL_LEFT);
        return true;
    case Test:
        return EVAL_INT_LEFT ? EXEC_RIGHT : false;

    default:
      for (auto child : this->children) {
        try {
          child->execute(env);
        } catch (std::exception& e) {
          std::cerr << "Error: " << e.what() << std::endl;
        }
      }
      return true;
    }
}

Memory* Node::eval(Environment& env) {
    Memory* m;
    switch (this->type) {
        case FunctionCall:
            this->execute(env);
            m = new Memory();
            *m = *env.read("return");
            return m;

        default:
            return NULL;
    }
}

int Node::evalInt(Environment& env) {
  switch (this->type) {
      case Hash:  return env.read(EVAL_STR_LEFT)->length();

      default:
        throw Error("Error: Tried to evaluate invalid integer value of node");
  }
}

std::string Node::evalStr(Environment& env) {
  switch (this->type) {
      case ExpressionList:
      {
        std::string tmp = "";
        // Check if all numbers
        bool allNumbers = true;
        for (auto child: this->children) {
          if (child->getType() != "Number")
            allNumbers = false;
            break;
        }
        // If all numbers add some tabs between, else don't
        for (auto child: this->children)
          tmp += allNumbers ? child->evalStr(env) + "\t" : child->evalStr(env);
        return tmp;
      }

      default:
        throw Error("Error: Tried to evaluate invalid string value of node");
  }
}

void Node::transferChildren(Node* parent) {
  for (auto child : this->children)
    parent->addChild(child);

  this->children = std::vector<Node*>();
}
