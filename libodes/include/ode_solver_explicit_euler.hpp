// naumann@stce.rwth-aachen.de

#pragma once

#include "ode_system.hpp"
#include "ode_solver.hpp"

namespace Ode
{

  /*
  template <typename TS, typename TP, int NS, int NP>
  class Solver_Explicit_Euler : public Solver<TS, TP, NS, NP>
  {
    using Solver<TS, TP, NS, NP>::_T_end;
    using Solver<TS, TP, NS, NP>::_nts;

  //TODO Linear System Solve
  public:
    Solver_Explicit_Euler(const TP &, const int);
    void solve(System<TS, TP, NS, NP> &);
  };
  */

  template <typename SYS, typename TP>
  class Solver_Explicit_Euler : public Solver<SYS, TP>
  {
    using Solver<SYS, TP>::_T_end;
    using Solver<SYS, TP>::_nts;

  //TODO Linear System Solve
  public:
    Solver_Explicit_Euler(const TP &, const int);
    void solve(SYS &);
  };

}

#include "../src/ode_solver_explicit_euler.cpp"
