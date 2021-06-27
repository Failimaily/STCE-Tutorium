// naumann@stce.rwth-aachen.de

#include <iostream>
#include <cassert>

#include "ode_system_lotka_volterra.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"
#include "ode_nlsolver_implicit_euler.hpp"

int main(int argc, char *argv[]) {
  assert(argc==4);
  using T=double;
  T T_end=std::stof(argv[1]); assert(T_end>0);
  int nts=std::stoi(argv[2]); assert(nts>0);
  T eps=std::stof(argv[3]); assert(eps>0);
  Lotka_Volterra::System<T,T> odesys;
  using SYS = Lotka_Volterra::System<T,T>;
  Linear::Solver_QR<T,Lotka_Volterra::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP> nlsol(lsol,eps);
  Ode::Solver_Implicit_Euler<SYS,T,T,Lotka_Volterra::NS,Lotka_Volterra::NP> odesol(nlsol,T_end,nts);
  odesys.p()=Ode::System<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP>::VTP::Random(odesys.np());
  odesys.x()=Ode::System<T,T,Lotka_Volterra::NS,Lotka_Volterra::NP>::VTS::Random(odesys.ns());
  odesol.solve(odesys);
  std::cout << odesys.x() << std::endl;
  return 0;
}

