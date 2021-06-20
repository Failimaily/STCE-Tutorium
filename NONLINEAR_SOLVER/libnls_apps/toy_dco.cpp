// naumann@stce.rwth-aachen.de

#include <iostream>

#include "nonlinear_system_toy.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"

#include "dco.hpp"

int main() {
  using T=dco::gt1s<double>::type;
  Toy::System<T,T> nlsys;
  Linear::Solver_QR<T,Toy::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Toy::NS,Toy::NP> nlsol(lsol,1e-7);
  nlsys.x()(0)=1;
  nlsys.p()(0)=2;
  dco::derivative(nlsys.p()(0))=1;
  nlsol.solve(nlsys);
  std::cout << "x=" << nlsys.x() << std::endl;
  std::cout << "|f(x)|=" << nlsys.f().norm() << std::endl;
  std::cout << "dxdp=" << dco::derivative(nlsys.x()(0)) << std::endl;
  return 0;
}
