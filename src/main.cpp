
// Yes this is super global, tried with macros but want user to control debug
bool debug = false;

#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "parser.h"

#define GRAPH_PATH  "graph.dot"

extern Node* root;
extern Environment env;
extern FILE* yyin; // Dunno how to solve this in c++

using namespace std;

void yy::parser::error(std::string const&err)
{
  cout << "Invalid input: " << err << endl;
}

int main(int argc, char **argv)
{

  char graphPath[PATH_MAX];
  char filePath[PATH_MAX];
  char *gvalue = NULL;
  int c,e;

  opterr = 0;
  while ((c = getopt (argc, argv, "dg:")) != -1)
    switch (c)
      {
      case 'd':
        debug = true;
        break;
      case 'g':
        gvalue = optarg;
        break;
      case '?':
        if (optopt == 'g')
          std::cerr << "Option -g requires an argument" << std::endl;
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  // Graph path
  if (gvalue != NULL) {
    realpath(gvalue, graphPath);
    if (debug)
      std::cout << "Path for dot file: " << graphPath << std::endl;
  }

  // File path
  if (argc > 1) {
    realpath(argv[argc - 1], filePath);
    if (debug)
      std::cout << "Path for input file: " << filePath << std::endl;
  } else {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }

  // Open input
  try {
    yyin = fopen(filePath,"r");
  } catch (std::exception& e) {
    std::cerr << "Could not open file: " << e.what() << std::endl;
    return 1;
  }

  if (yyin != NULL) {
    // Get parser
    yy::parser parser;
    e = parser.parse();

    fclose(yyin);

  } else {
    std::cerr << "No file open for input" << std::endl;
    return 1;
  }

  // If no parser errors
  if (e == 0){
    // Open graph
    ofstream graph;
    if (gvalue != NULL){
      try {
        graph.open(graphPath, ios::out);
      } catch (std::exception& e) {
        std::cerr << "Could not open file: " << e.what() << std::endl;
        return 1;
      }
    } else {
      try {
        graph.open(GRAPH_PATH, ios::out);
      } catch (std::exception& e) {
        std::cerr << "Could not open file: " << e.what() << std::endl;
        return 1;
      }
    }

    if (graph.is_open()) {
      // print header
      graph << "digraph {" << endl;

      // Print graph
      root->print(0, graph);

      // print footer
      graph << "}" << endl;
      //close graph
      graph.close();
    }

    // Execute
    try {
        root->execute(env);
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
  }

  delete root;

  return 0;
}
