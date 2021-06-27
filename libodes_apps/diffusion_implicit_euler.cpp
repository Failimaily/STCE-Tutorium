// naumann@stce.rwth-aachen.de

#include <iostream>
#include <cassert>

#include "ode_system_diffusion.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"
#include "ode_nlsolver_implicit_euler.hpp"

int main(int argc, char *argv[]) {
  assert(argc==5); 
  using T=double;
  int ns=std::stoi(argv[1]); assert(ns>1);
  T T_end=std::stof(argv[2]); assert(T_end>0);
  int nts=std::stoi(argv[3]); assert(nts>0);
  T eps=std::stof(argv[4]); assert(eps>0);
  Diffusion::System<T,T> odesys(ns);
  using SYS = Diffusion::System<T,T>;
  //using SYS = Diffusion<T,T,
  Linear::Solver_QR<T,Diffusion::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Diffusion::NS,Diffusion::NP> nlsol(lsol,eps);
  Ode::Solver_Implicit_Euler<SYS,T,T,Diffusion::NS,Diffusion::NP> odesol(nlsol,T_end,nts);
  odesys.p() << 1,0,42;
  //odesys.isLinear = true;
  odesys.x()=Ode::System<T,T,Diffusion::NS,Diffusion::NP>::VTS::Ones(odesys.ns());
  odesol.solve(odesys);
  std::cout << odesys.x().transpose() << std::endl;
  return 0;
}
