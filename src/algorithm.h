/*
 * algorithm.h
 *
 * Created on: December 24, 2019
 * Author: Suguman Bansal
 */


#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "common.h"
#include "Graph.h"
#include "Transition.h"

using namespace std;

mpq_class valueiteratie(Graph* gg, int df);

mpq_class optimalvalue(mpq_class cost, int df);


#endif
