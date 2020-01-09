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

int valueiterate(Graph* gg, int df, int safety, mpq_class threshold);

mpq_class optimalvalue(mpq_class cost, int df);

int winner(mpq_class optval, int threshold);

#endif
