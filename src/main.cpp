#include "algorithm.h"
#include "common.h"
#include "Graph.h"
#include "Transition.h"
#include "utils.h"


//Command line input is <filename> <df> <value>
int main(int argc, char** argv){
  
  string filename = argv[1];
  int df = stoi(argv[2]);
  int value = stoi(argv[3]);

  Graph* gamegraph = readGraph(filename);
  gamegraph->printAll();

  
  mpq_class a, b, c, cost;

  cost = valueiterate(gamegraph, df);

  cout << cost << endl;
  
  a = 1234.5;
  b = (5,2);
  c = a+b;
  
  cout << cmp(b,a) << endl;
  
  cout << "sum is " << c << "\n";

  
  
  cout << "absolute value is " << abs(c) << "\n";

  return 0;
}
