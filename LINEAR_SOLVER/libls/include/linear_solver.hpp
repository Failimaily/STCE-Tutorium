// naumann@stce.rwth-aachen.de

#pragma once

#include "linear_system.hpp"

namespace Linear {

template<typename T, int N>
struct Solver { 
  virtual void solve(System<T,N>&)=0;
};

}
