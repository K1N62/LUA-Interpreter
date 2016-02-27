
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
  //Nothing
}

/**
* Overloads the Type output stream operator
* @author Jim Ahlstrand
*/
std::ostream& operator<<(std::ostream& out, const Node::Type& type)
{
    switch (type) {
    case Node::Type::Undefined: out << "Undefined"; break;
    case Node::Type::ExpressionList: out << "ExpressionList"; break;
    case Node::Type::VariableList: out << "VariableList"; break;
    case Node::Type::FunctionBody: out << "FunctionBody"; break;
    case Node::Type::FunctionName: out << "FunctionName"; break;
    case Node::Type::FunctionCall: out << "FunctionCall"; break;
    case Node::Type::Function: out << "Function"; break;
    case Node::Type::MemberVariable: out << "MemberVariable"; break;
    case Node::Type::MemberFunction: out << "MemberFunction"; break;
    case Node::Type::Variable: out << "Variable"; break;
    case Node::Type::ListName: out << "ListName"; break;
    case Node::Type::Range: out << "Range"; break;
    case Node::Type::Repeat: out << "Repeat"; break;
    case Node::Type::While: out << "While"; break;
    case Node::Type::For: out << "For"; break;
    case Node::Type::If: out << "If"; break;
    case Node::Type::ElseIf: out << "ElseIf"; break;
    case Node::Type::Stat: out << "Stat"; break;
    case Node::Type::Field: out << "Field"; break;
    case Node::Type::Equal: out << "Equal"; break;
    case Node::Type::Addition: out << "Addition"; break;
    case Node::Type::Subtraction: out << "Subtraction"; break;
    case Node::Type::Division: out << "Division"; break;
    case Node::Type::Multiplication: out << "Multiplication"; break;
    case Node::Type::Power: out << "Power"; break;
    case Node::Type::Modulo: out << "Modulo"; break;
    case Node::Type::DoubleDot: out << "DoubleDot"; break;
    case Node::Type::LessThan: out << "LessThan"; break;
    case Node::Type::LessOrEq: out << "LessOrEq"; break;
    case Node::Type::GreaterThan: out << "GreaterThan"; break;
    case Node::Type::GreaterOrEq: out << "GreaterOrEq"; break;
    case Node::Type::Test: out << "Test"; break;
    case Node::Type::NotEq: out << "NotEq"; break;
    case Node::Type::And: out << "And"; break;
    case Node::Type::Or: out << "Or"; break;
    case Node::Type::Not: out << "Not"; break;
    case Node::Type::Hash: out << "Hash"; break;
    case Node::Type::Comma: out << "Comma"; break;
    case Node::Type::SemiColon: out << "SemiColon"; break;
    case Node::Type::Name: out << "Name"; break;
    case Node::Type::Nil: out << "Nil"; break;
    case Node::Type::False: out << "False"; break;
    case Node::Type::True: out << "True"; break;
    case Node::Type::Number: out << "Number"; break;
    case Node::Type::String: out << "String"; break;
    case Node::Type::Tridot: out << "Tridot"; break;
    default: out << "Undefined"; break;
    }

    return out;
}

int Node::print(int id, std::ofstream& file)
{
  // Print children first to get correct id order
  for (auto &child : this->children) {
    id = child.print(id, file);
  }

  // Grab this id
  this->id = ++id;

  // Print this tag
  if (this->children.size() == 0) {
    file << this->id << " " << "[label=\"" << this->value << "\"]" << std::endl;
  } else {
    file << this->id << " " << "[label=\"" << this->type << "\"]" << std::endl;
  }

  // Print link to children
  for(auto &child : this->children) {
    file << this->id << " -> " << child.getNodeID() << std::endl;
  }

  return this->id;
}

int Node::addChild(Node& child)
{
  //! \todo add tests for child here
  this->children.push_back(child);
  return 0;
}

Node Node::getChild(unsigned int i)
{
  if ( i > this->children.size() - 1 || this->children.size() == 0 )
    return Node();

  return this->children[i];
}
