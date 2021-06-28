// naumann@stce.rwth-aachen.de

#include <iostream>
#include <cassert>

#include "ode_system_diffusion.hpp"
#include "ode_solver_explicit_euler.hpp"

int main(int argc, char *argv[]) {
  assert(argc==4);
  using T=double;
  int ns= std::stoi(argv[1]); assert(ns>1);
  T T_end= std::stof(argv[2]); assert(T_end>0);
  int nts= std::stoi(argv[3]); assert(nts>0);
  Diffusion::System<T,T> odesys(ns);
  using SYS = Diffusion::System<T,T>;
  Ode::Solver_Explicit_Euler<SYS,T> odesol(T_end,nts);
  odesys.p() << 1,0,42;
  odesys.x()=Ode::Nonlinear_System<T,T,Diffusion::NS,Diffusion::NP>::VTS::Ones(odesys.ns());
  odesol.solve(odesys);
  std::cout << odesys.x().transpose() << std::endl;
  return 0;
}
