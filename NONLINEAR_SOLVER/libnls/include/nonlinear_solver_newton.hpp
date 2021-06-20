// naumann@stce.rwth-aachen.de

#pragma once

#include "linear_solver.hpp"
#include "nonlinear_system.hpp"
#include "nonlinear_solver.hpp"

namespace Nonlinear {

template<typename TS, typename TP, int NS, int NP>
class Solver_Newton : public Solver<TS,TP,NS,NP> {
  Linear::Solver<TS,NS>& _lsol;
  TS _eps;
public:
  Solver_Newton(Linear::Solver<TS,NS>&, const TS&);
  void solve(System<TS,TP,NS,NP>&);
};

}

#include "../src/nonlinear_solver_newton.cpp"
