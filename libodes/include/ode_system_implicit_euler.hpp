// naumann@stce.rwth-aachen.de

#pragma once

#include "ode_system.hpp"
#include "ode_solver.hpp"
#include "nonlinear_system.hpp"
#include "linear_system.hpp"

namespace Ode
{

  /*
  template <typename TS, typename TP, int NS, int NP>
  class System_Implicit_Euler : public Nonlinear::System<TS, TP, NS, NP>
  {
    using VTS = typename Ode::System<TS, TP, NS, NP>::VTS;
    using MTS = typename Ode::System<TS, TP, NS, NP>::MTS;
    typename Ode::System<TS, TP, NS, NP> &_odes;
    VTS _x_prev;
    TP _dt;

  public:
    System_Implicit_Euler(typename Ode::System<TS, TP, NS, NP> &, const VTS &, const TP &);
    VTS f();
    MTS dfdx();
  };

  template <typename TS, typename TP, int NS, int NP>
  class Solver_Implicit_Euler : public Solver<TS, TP, NS, NP>
  {
    //Linear Algebra Solver
    typename Nonlinear::Solver<TS, TP, NS, NP> &_nlsol;
    //typename Linear::Solver<TS,NS> &_lsol; 

  public:
    using Ode::Solver<TS, TP, NS, NP>::_T_end;
    using Ode::Solver<TS, TP, NS, NP>::_nts;
    Solver_Implicit_Euler(Nonlinear::Solver<TS, TP, NS, NP> &, const TP &, const int);
    //Solver_Implicit_Euler(Linear::Solver<TS,NS> &);
    void solve(Ode::System<TS, TP, NS, NP> &);
  };y
  */

  template <typename SYS, typename TP>
  class System_Implicit_Euler
  {
    using VTS = typename SYS::VTS;
    using MTS = typename SYS::MTS;
    

  protected:
    SYS &_odes;
    VTS _x_prev;
    TP _dt;
    System_Implicit_Euler(SYS &, const typename SYS::VTS &, const TP &);

  public:
    
  };

}

#include "../src/ode_system_implicit_euler.cpp"
