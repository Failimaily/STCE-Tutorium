// naumann@stce.rwth-aachen.de

#include "linear_system.hpp"
#include "linear_solver_lr.hpp"
#include "utils.hpp"

#include<cassert>
#include<iostream>

int main(int argc, char* argv[]) {
  assert(argc==2); int n=std::stoi(argv[1]); 
  using T=double;
  Linear::System<T,Utils::Dynamic> lsys(n);
  lsys.A()=Linear::System<T,Utils::Dynamic>::MT::Random(n,n); 
  lsys.b()=Linear::System<T,Utils::Dynamic>::VT::Random(n); 
  Linear::Solver_LR<T,Utils::Dynamic> lsol;
  lsol.solve(lsys);
  std::cout << "x=" << lsys.x().transpose() << std::endl;
  return 0;
}

