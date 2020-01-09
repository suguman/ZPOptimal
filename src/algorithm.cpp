//============================================================================
// Name        : algorithm.cpp
// Author      : Suguman Bansal
// Version     :
// Copyright   : Your copyright notice
// Description : algorithm functions
//============================================================================

#include "algorithm.h"
#include "common.h"
#include "Graph.h"
#include "Transition.h"
#include "utils.h"

using namespace std;

int valueiterate(Graph* gg, int df, int safety, mpq_class threshold){

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

  mpq_class lowerlimit;
  mpq_class upperlimit;
  mpq_class distance = maxval;
  
  unordered_map<int, vector<Transition*>> :: iterator p;
  for (p = transfunc->begin(); p != transfunc->end(); p++){

    int state = p->first;
    vector<Transition*> translist = p->second;
    
    int playerid = stateplayermap->at(state);
    
    for (auto & element : translist){
      mpq_class val = element->getWt(); 
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
  }

  //Conduct value iteration
  //to check number of iterations
  //int numiterations = numstates*numstates;

  int numstates = gg->getStateNum();
  int numiterations = numstates*numstates;

  //int numiterations = 5;

  for(int i=0; i<numiterations; i++){
    
    //Initialize costvectoraux

    //Based on player id, we maximize or minimize
    //Player 0 is max player
    //Player 1 is min player

    unordered_map<int, mpq_class> costvectoraux;
    unordered_map<int, int> :: iterator q;
    for(q = stateplayermap->begin(); q != stateplayermap->end(); q++){
      int state = q->first;
      int playerid = q->second;

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
      
      for (auto & element : translist){

	int deststate = element->getDest();
	int transweight = element->getWt();
	temp = transweight + (costvector[deststate]/df);
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
    }

    // Obtain return value
    // If the game is a safety game, then determine limits
    // If there is no difference between costvector and costvectoraux , then both games can be terminated. Simply compare value wiht the threshold

    mpq_class returnvalue = costvector.at(gg->getInitial()); 

    if (terminate){
      //return value for early termination      
      if (cmp(returnvalue, threshold)<=0){
	return 1;
      }
      else{
	return 0;
      }
    }
    //If the safety game is being played
    if (safety==1){
      upperlimit = returnvalue + distance;
      lowerlimit = returnvalue - distance;
      distance = distance/2;

      cout << lowerlimit << "; " << returnvalue << "; " << upperlimit << "; " << threshold << endl;

      if (cmp(threshold, lowerlimit)<=0){
	cout << cmp(threshold, lowerlimit) << endl;
	//winner = 0;
	return 0;
      }
      if (cmp(upperlimit, threshold)<=0){
	cout << cmp(upperlimit, threshold) << endl;
	//winner = 1;
	return 1;
      }
    }
  }
  //If optimization is being played
  //Optimization game is played after return value is obtained

  mpq_class returnvalue = costvector.at(gg->getInitial()); 
  if (safety == 0){
    if (cmp(returnvalue, threshold)<=0){
      return 1;
    }
    else{
      return 0;
    }
  }
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
