// naumann@stce.rwth-aachen.de

#pragma once

#include "ode_system.hpp"

/*namespace Ode
{

  template <typename TS, typename TP, int NS, int NP>
  class Solver
  {
  protected:
    TP _T_end;
    int _nts;

  //TODO Check Inheritance for Linear System in function solve
  public:
    Solver(const TP &, const int);
    virtual void solve(System<TS, TP, NS, NP> &) = 0;
    virtual void solve_lodes(Linear_System<TS,NS> &);
  };

}*/

namespace Ode
{

  template <typename SYS, typename TP>
  class Solver
  {
  protected:
    TP _T_end;
    int _nts;

  //TODO Check Inheritance for Linear System in function solve
  public:
    Solver(const TP &, const int);
    virtual void solve(SYS &) = 0;
  };

}

#include "../src/ode_solver.cpp"
