// naumann@stce.rwth-aachen.de

#pragma once

#include "ode_system.hpp"

namespace Ode {

template<typename TS, typename TP, int NS, int NP>
class Solver {
protected:
  TP _T_end;
  int _nts;
public:
  Solver(const TP &, const int);
  virtual void solve(System<TS,TP,NS,NP>&)=0;
};

}

#include "../src/ode_solver.cpp"
