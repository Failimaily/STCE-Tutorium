// naumann@stce.rwth-aachen.de

#include <iostream>
#include <cassert>

#include "ode_system_lotka_volterra.hpp"
#include "ode_solver_explicit_euler.hpp"

int main(int argc, char *argv[]) {
  assert(argc==3); 
  using T=double;
  const int NS=Lotka_Volterra::NS, NP=Lotka_Volterra::NP;
  T T_end=std::stof(argv[1]); assert(T_end>0);
  int nts=std::stoi(argv[2]); assert(nts>0);
  Lotka_Volterra::System<T,T> odesys;
  using SYS = Lotka_Volterra::System<T,T>;
  Ode::Solver_Explicit_Euler<SYS,T> odesol(T_end,nts);
  odesys.p()=Ode::System<T,T,NS,NP>::VTP::Random(odesys.np());
  odesys.x()=Ode::System<T,T,NS,NP>::VTS::Random(odesys.ns());
  odesol.solve(odesys);
  std::cout << odesys.x() << std::endl;
  return 0;
}
