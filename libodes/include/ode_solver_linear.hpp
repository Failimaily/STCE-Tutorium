//Implicit solver for linear equations

#pragma once

#include "ode_system.hpp"
#include "ode_solver.hpp"
#include "linear_system.hpp"

namespace Ode{

class Solver_Linear : public Solver<TS, TP, NS, NP>
  {
    typename Linear::Solver<TS,TP,NS,NP> &_lsol;

  public:
    using Ode::Solver<TS, TP, NS, NP>::_T_end;
    using Ode::Solver<TS, TP, NS, NP>::_nts;
    Solver_Linear(Linear::Solver<TS, TP, NS, NP> &, const TP &, const int);
    void solve(Ode::System<TS, TP, NS, NP> &);
  };



    #include "../src/ode_solver_linear.cpp"

}