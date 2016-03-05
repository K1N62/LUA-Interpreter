#include <iostream>
#include <exception>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "parser.h"

#define PATH_FILE  "graph.dot"

extern Node* root;
extern Environment env;

using namespace std;

void yy::parser::error(std::string const&err)
{
  cout << "It's one of the bad ones... " << err << endl;
}

int main(int argc, char **argv)
{

  char filePath[PATH_MAX];
  bool userPath = false;

  for (int i = 1; i < argc; i++) {
    std::string a = argv[i];
    if (a == "-p") {
      if (++i > argc - 1 || strlen(argv[i]) > PATH_MAX - 1) {
        std::cerr << "Invalid parameters" << std::endl;
        return 1;
      }
      realpath(argv[i], filePath);
      userPath = true;
      #if (DEBUG)
        std::cout << "Path for dot file: " << filePath << std::endl;
      #endif
    }
  }

  yy::parser parser;
  parser.parse();

  // Open file
  ofstream file;
  if (userPath){
    try {
      file.open(filePath, ios::out);
    } catch (std::exception& e) {
      std::cerr << "Could not open file: " << e.what() << std::endl;
      return 1;
    }
  } else {
    try {
      file.open(PATH_FILE, ios::out);
    } catch (std::exception& e) {
      std::cerr << "Could not open file: " << e.what() << std::endl;
      return 1;
    }
  }

  if (file.is_open()) {
    // print header
    file << "digraph {" << endl;

    // Print file
    root->print(0, file);

    // print footer
    file << "}" << endl;
    //close file
    file.close();
  }
  // Execute
  try {
      root->execute(env);
  } catch (exception& e) {
      cerr << "Error: " << e.what() << endl;
  }

  delete root;

  return 0;
}
