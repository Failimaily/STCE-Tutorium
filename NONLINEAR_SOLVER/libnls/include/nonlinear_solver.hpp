// naumann@stce.rwth-aachen.de

#pragma once

#include "nonlinear_system.hpp"

namespace Nonlinear {

template<typename TS, typename TP, int NS, int NP>
class Solver {
public:
  virtual void solve(System<TS,TP,NS,NP>&)=0;
};

} 
