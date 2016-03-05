
#include "Environment.h"
#include "Memory.h"
#include "Node.h"

Node::Node()
{
  this->id = 0;
  this->type = Type::Undefined;
  this->value = "";
}

Node::Node(Type type)
{
  this->id = 0;
  this->type = type;
  this->value = "";
}

Node::Node(Type type, std::string value)
{
  this->id = 0;
  this->type = type;
  this->value = value;
}

Node::~Node()
{
  #if (DEBUG)
    std::cout << "Deleting node (" << getType() << ")" << std::endl;
  #endif

  for (auto child : this->children)
    delete child;
}

std::string Node::getType()
{
    switch (this->type) {
        case Node::Type::ExpressionList: return "ExpressionList";
        case Node::Type::VariableList: return "VariableList";
        case Node::Type::FunctionName: return "FunctionName";
        case Node::Type::FunctionCall: return "FunctionCall";
        case Node::Type::FunctionBody: return "FunctionBody";
        case Node::Type::Function: return "Function";
        case Node::Type::MemberFunction: return "MemberFunction";
        case Node::Type::ListName: return "ListName";
        case Node::Type::Stat: return "Stat";
        case Node::Type::Field: return "Field";
        case Node::Type::FieldElement: return "FieldElement";
        case Node::Type::DoubleDot: return "DoubleDot";
        case Node::Type::Hash: return "Hash";
        case Node::Type::Negate: return "Negate";
        case Node::Type::Name: return "Name";
        case Node::Type::Tridot: return "Tridot";
        case Node::Type::Return: return "Return";
        default:
            return "Undefined";
    }
}

int Node::print(int id, std::ofstream& file)
{
  // Print children first to get correct id order
  for (auto child : this->children)
    id = child->print(id, file);

  // Grab this id
  this->id = ++id;

  // Print this tag
  #if PRINT_LEAF_VALUES
    if (this->children.size() == 0) {
      file << this->id << " " << "[label=\"" << this->value << "\"]" << std::endl;
    } else {
      file << this->id << " " << "[label=\"" << this->getType() << "\"]" << std::endl;
    }
  #else
    file << this->id << " " << "[label=\"" << this->getType() << "\"]" << std::endl;
  #endif

  // Print link to children
  for(auto child : this->children)
    file << this->id << " -> " << child->getNodeID() << std::endl;

  return this->id;
}

Node* Node::getChild(unsigned int i)
{
  if ( i > this->children.size() - 1 || this->children.size() == 0 )
    return new Node();

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
    case Function:
      {
        #if (DEBUG)
          std::cout << "Creating new Function" << std::endl;
        #endif
        Memory* mem = new Memory(RIGHT);
        env.write(LEFT->children[0]->value, mem);
        return true;
      }
    case FunctionCall:
      if (VAL_LEFT == "print") std::cout << EVAL_STR_RIGHT << std::endl;
      else {
        Memory* func = env.read(LEFT->value);
        // @todo save right hand value as input paramater, need lookahead at function node for Name
        func->execute(env); // @bug don't work with memberfunction
      }
      return true;
    case FunctionBody:
      {
        Environment f = env;
        EXEC_RIGHT;
      }

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

int Node::evalInt(Environment& env) {
  switch (this->type) {
      case Name:  return env.read(this->value)->evalInt(env);
      case Hash:  return env.read(LEFT->value)->length();

      default:
        throw Error("Warning: Tried to evaluate invalid integer value of node");
  }
}

std::string Node::evalStr(Environment& env) {
  switch (this->type) {
      case Name:    return env.read(this->value)->evalStr(env);

      default:
        throw Error("Warning: Tried to evaluate invalid string value of node");
  }
}
