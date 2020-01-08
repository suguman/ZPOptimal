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

mpq_class valueiterate(Graph* gg, int df){

  unordered_map<int, vector< Transition*>>* transfunc = gg->getTrans();
  unordered_map<int, int>* stateplayermap = gg->getStateToPlayer();
  int maxval = gg->getWt();

  
  //initialization of cost vector
  //create  cost vector

  //Based on player id, we maximize or minimize
  //Player 0 is max player
  //Player 1 is min player

  unordered_map<int, mpq_class> costvector;
  
  unordered_map<int, int> :: iterator q;
  for(q = stateplayermap->begin(); q != stateplayermap->end(); q++){
    int state = q->first;
    int playerid = q->second;
    if (playerid == 0){
      costvector[state] = -1*maxval;
    }
    else{
      costvector[state] = maxval;
    }
  }

  unordered_map<int, vector<Transition*>> :: iterator p;
  for (p = transfunc->begin(); p != transfunc->end(); p++){

    int state = p->first;
    vector<Transition*> translist = p->second;
    
    int playerid = stateplayermap->at(state);
    
    for (auto & element : translist){
      mpq_class val = element->getWt();
      //cout << val << endl;

      
	if (playerid == 0){ 
	  if (cmp(val, costvector[state]) >= 0){
	    costvector[state] = val;
	  }
	}
	else{
	  if (cmp(val, costvector[state]) <= 0){
	    costvector[state] = val;
	  }
	}
    }
    //cout << "Initial value of state " << state << " is " << costvector[state] << endl;
  }

  //Conduct value iteration

  //to check number of iterations
  //int numiterations = numstates*numstates;

  
  int numstates = gg->getStateNum();
  int numiterations = numstates*numstates;

  //int numiterations = 5;

  for(int i=0; i<numiterations; i++){

    //cout << i << ", " << numiterations << endl;
    
    //Initialize costvectoraux

    //Based on player id, we maximize or minimize
    //Player 0 is max player
    //Player 1 is min player

    unordered_map<int, mpq_class> costvectoraux;
    unordered_map<int, int> :: iterator q;
    for(q = stateplayermap->begin(); q != stateplayermap->end(); q++){
      int state = q->first;
      int playerid = q->second;

      //costvectoraux[state] = costvector.at(state);
      
      if (playerid == 0){
	costvectoraux[state] = -1*maxval;
      }
      else{
	costvectoraux[state] = maxval;
      }
      
    }
      
      
    unordered_map<int, vector<Transition*>> :: iterator it;
    
    for (it = transfunc->begin(); it != transfunc->end(); it++){
      
      int state = it->first;
      vector<Transition*> translist = it->second;
      
      mpq_class temp;
      int playerid = stateplayermap->at(state);
      //cout << "Current state is " << state << endl;
      //cout << "Player id is " << playerid << endl;
      //cout << "Cost vector of state is " << costvector[state] << endl;
      
      for (auto & element : translist){
	//cout << "Trans is ";
	 //element->toString();
	int deststate = element->getDest();
	int transweight = element->getWt();
	temp = transweight + (costvector[deststate]/df);
	//cout << "Value from this transition is  " << temp << endl;

	//Based on player id, we maximize or minimize
	//Player 0 is max player
	//Player 1 is min player
	
	if (playerid == 0){ 
	  if (cmp(temp, costvectoraux[state]) >= 0){
	    costvectoraux[state] = temp;
	  }
	}
	else{
	  if (cmp(temp, costvectoraux[state]) <= 0){
	    costvectoraux[state] = temp;
	  }
	}

	//cout << "Cost vector aux (Updated value) is " << costvectoraux[state] << endl;
      }
    }

    //Update cost vector
    //Also checking for early termination at the same time
    bool terminate = true;
    unordered_map<int, mpq_class> :: iterator iter;
    for (iter = costvectoraux.begin(); iter != costvectoraux.end(); iter++){
      int state = iter->first;
      if (cmp(costvectoraux.at(state), costvector.at(state)) != 0){
        terminate = false; // cannot terminate yet
	costvector[state] = costvectoraux.at(state);
      }
      //cout << state << ", " << costvector.at(state) << endl;
    }
    if (terminate){
      //return value for early termination
      mpq_class returnvalue = costvector.at(gg->getInitial());
      return returnvalue;
    }

    //cout << "Value is " << costvector.at(gg->getInitial()) << endl;
  }

  mpq_class returnvalue = costvector.at(gg->getInitial());
  return returnvalue;
}


mpq_class optimalvalue(mpq_class cost, int df){
  
  return 0;
}

int winner(mpq_class optval, int threshold){
  if (cmp(optval, threshold)<=0){
      return 1;
    }
  else{
    return 0;
  }
}
