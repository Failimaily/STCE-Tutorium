// naumann@stce.rwth-aachen.de

#pragma once

#include "linear_system.hpp"
#include "linear_solver.hpp"

namespace Linear {

/**
 * Linear solver based on LR factorization of system matrix
 */
template<typename T, int N>
class Solver_LR : public Solver<T,N> {

public:

  void solve(System<T,N>&);
};

}

#include "../src/linear_solver_lr.cpp"
