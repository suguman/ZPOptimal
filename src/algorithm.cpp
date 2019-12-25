//============================================================================
// Name        : algorithm.cpp
// Author      : Suguman Bansal
// Version     :
// Copyright   : Your copyright notice
// Description : Utility functions
//============================================================================

#include "algorithm.h"
#include "common.h"
#include "Graph.h"
#include "Transition.h"
#include "utils.h"

using namespace std;

mpq_class valueiteratie(Graph* gg, int df){

  unordered_map<int, vector< Transition*>>* transfunc = gg->getTrans();
  int maxval = gg->getWt();

  unordered_map<int, mpq_class> costvector;

  //initialization of cost vector

  unordered_map<int, vector<Transition*>> :: iterator p;
  for (p = transfunc->begin(); p != transfunc->end(); p++){

    int state = p->first;
    vector<Transition*> translist = p->second;
    
    costvector[state] = -1*maxval;
    //cout << state << " " << costvector[state] << endl;
    //cout << "The translist size is " << translist.size() << endl;

    for (auto & element : translist){
      mpq_class val = element->getWt();
      //cout << val << endl;
      if (cmp(val, costvector[state]) >= 0){
	costvector[state] = val;
      }
    }
    cout << "Initial value of state " << state << " is " << costvector[state] << endl;
  }

  //TODO:: Make a second copy of costvector

  
  //Conduct value iteration
  int numstates = gg->getStateNum();
  int numiterations = numstates*numstates;

  for(int i=0; i<numiterations; i++){
    cout << i << ", " << numiterations << endl;
    
    unordered_map<int, vector<Transition*>> :: iterator p;
    for (p = transfunc->begin(); p != transfunc->end(); p++){
      int state = p->first;
      vector<Transition*> translist = p->second;
      mpq_class prior = costvector[state];
      
    }
  }
    
  return -1;
}

mpq_class optimalvalue(mpq_class cost, int df){
  //TODO
  return 0;
}

