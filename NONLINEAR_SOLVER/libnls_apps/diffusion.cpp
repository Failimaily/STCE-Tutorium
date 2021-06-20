// naumann@stce.rwth-aachen.de

#include<iostream>
#include<cassert>

#include "nonlinear_system_diffusion.hpp"
#include "linear_solver_lr.hpp"
#include "nonlinear_solver_newton.hpp"

int main(int argc, char *argv[]) {
  assert(argc==2); int s=std::stoi(argv[1]); assert(s>1);
  using T=double;
  Diffusion::System<T,T> nlsys(s);
  Linear::Solver_LR<T,Diffusion::NS> lsol;
  Nonlinear::Solver_Newton<T,T,Diffusion::NS,Diffusion::NP> nlsol(lsol,1e-7);
  nlsys.p()=Nonlinear::System<T,T,Diffusion::NS,Diffusion::NP>::VTP::Random(nlsys.np());
  nlsys.x()=Nonlinear::System<T,T,Diffusion::NS,Diffusion::NP>::VTS::Random(nlsys.ns());
  std::cout << "x^T=" << nlsys.x().transpose() << std::endl;
  nlsol.solve(nlsys);
  std::cout << "x^T=" << nlsys.x().transpose() << std::endl;
  std::cout << "||f(x)||=" << nlsys.f().norm() << std::endl;
  return 0;
}

  
