#include <iostream>
#include "parser.h"
#include "Node.h"

#define PRINT_FILE  "graph.dot"

extern Node root;

void yy::parser::error(std::string const&err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
  yy::parser parser;
  parser.parse();

  // Open file
  ofstream file;
  file.open(PRINT_FILE, ios::out);
  // print header
  file << "digraph {" << endl;

  // Print file
  root.print(0, file);

  // print footer
  file << "}" << endl;
  //close file
  file.close();

  return 0;
}
