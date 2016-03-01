
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
  for (auto child : this->children)
    delete child;
}

std::string Node::getType()
{
    switch (this->type) {
        case Node::Type::ExpressionList: return "ExpressionList";
        case Node::Type::VariableList: return "VariableList";
        case Node::Type::FunctionBody: return "FunctionBody";
        case Node::Type::FunctionName: return "FunctionName";
        case Node::Type::FunctionCall: return "FunctionCall";
        case Node::Type::Function: return "Function";
        case Node::Type::MemberFunction: return "MemberFunction";
        case Node::Type::Variable: return "Variable";
        case Node::Type::ListName: return "ListName";
        case Node::Type::Range: return "Range";
        case Node::Type::Stat: return "Stat";
        case Node::Type::Field: return "Field";
        case Node::Type::FieldList: return "FieldList";
        case Node::Type::FieldElement: return "FieldElement";
        case Node::Type::Equal: return "Equal";
        case Node::Type::DoubleDot: return "DoubleDot";
        case Node::Type::Hash: return "Hash";
        case Node::Type::Negate: return "Negate";
        case Node::Type::Name: return "Name";
        case Node::Type::Nil: return "Nil";
        case Node::Type::Number: return "Number";
        case Node::Type::String: return "String";
        case Node::Type::Tridot: return "Tridot";
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
  if (this->children.size() == 0) {
    file << this->id << " " << "[label=\"" << this->value << "\"]" << std::endl;
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

int Node::execute(Environment& env)
{
    switch (this->type) {
        case Number: return stoi(this->value);
        default:
            for(auto child : this->children) {
                try {
                    child->execute(env);
                } catch (std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
            return 0;
            break;
    }
}
