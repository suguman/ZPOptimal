#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <gmpxx.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <boost/algorithm/string.hpp>

int main(){
  std::cout << "Howdy" << std::endl;

  mpz_class a, b, c;

  a = 1234;
  b = 123;
  c = a+b;
  std::cout << "sum is " << c << "\n";
  std::cout << "absolute value is " << abs(c) << "\n";

  return 0;
}
