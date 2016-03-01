#include <iostream>
#include <exception>
#include "parser.h"

#define PRINT_FILE  "graph.dot"

extern Node* root;
extern Environment env;

using namespace std;

void yy::parser::error(std::string const&err)
{
  cout << "It's one of the bad ones... " << err << endl;
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
  root->print(0, file);

  // print footer
  file << "}" << endl;
  //close file
  file.close();

  // Execute
  try {
      root->execute(env);
  } catch (exception& e) {
      cerr << "Error: " << e.what() << endl;
  }

  delete root;

  return 0;
}
