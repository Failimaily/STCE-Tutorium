// naumann@stce.rwth-aachen.de

#include<iostream>

#include "nonlinear_system_lotka_volterra.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"

int main() {
  using T=double;
  Lotka_Volterra::System<T,T> nlsys;
  Linear::Solver_QR<T,Lotka_Volterra::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP> nlsol(lsol,1e-7);
  nlsys.p()=Nonlinear::System<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP>::VTP::Random(nlsys.np());
  nlsys.x()=Nonlinear::System<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP>::VTS::Random(nlsys.ns());
  std::cout << "x^T=" << nlsys.x().transpose() << std::endl;
  nlsol.solve(nlsys);
  std::cout << "x^T=" << nlsys.x().transpose() << std::endl;
  std::cout << "||f(x)||=" << nlsys.f().norm() << std::endl;

}

  
