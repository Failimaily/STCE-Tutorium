// naumann@stce.rwth-aachen.de

//#pragma once

#include "ode_system.hpp"
#include "ode_solver.hpp"

namespace Ode
{

  template <typename TS, typename TP, int NS, int NP>
  class Solver_Explicit_Euler : public Solver<TS, TP, NS, NP>
  {
    using Solver<TS, TP, NS, NP>::_T_end;
    using Solver<TS, TP, NS, NP>::_nts;

  public:
    Solver_Explicit_Euler(const TP &, const int);
    void solve(System<TS, TP, NS, NP> &);
  };

}

#include "../src/ode_solver_explicit_euler.cpp"
