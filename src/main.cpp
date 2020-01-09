#include "algorithm.h"
#include "common.h"
#include "Graph.h"
#include "Transition.h"
#include "utils.h"


//Command line input is <filename> <df> <value>
int main(int argc, char** argv){
  
  string filename = argv[1];
  int df = stoi(argv[2]);
  mpq_class value = stoi(argv[3]);
  string operation = argv[4];

  int winning;
    
  Graph* gamegraph = readGraph(filename);
  
  //gamegraph->printAll();

  if (operation == "optimize"){    
    //mpq_class cost;    
    winning = valueiterate(gamegraph, df, 0, value);
    //winning = winner(cost, value);
  }
  
  if( operation == "safety"){
    winning = valueiterate(gamegraph, df, 1, value);
  }

  cout << "Winning player is " << winning << endl;
  
  return 0;
}
