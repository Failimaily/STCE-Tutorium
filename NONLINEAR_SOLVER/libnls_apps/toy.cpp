// naumann@stce.rwth-aachen.de

#include<iostream>

#include "nonlinear_system_toy.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"

int main() {
  using T=double; 
  Toy::System<T,T> nlsys;
  Linear::Solver_QR<T,Toy::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Toy::NS,Toy::NP> nlsol(lsol,1e-7);
  nlsys.x()(0)=1;
  nlsys.p()(0)=2;
  nlsol.solve(nlsys);
  std::cout << "x=" << nlsys.x() << std::endl;
  std::cout << "|f(x)|=" << nlsys.f().norm() << std::endl;
  return 0;
}
