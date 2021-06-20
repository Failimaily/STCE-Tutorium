// naumann@stce.rwth-aachen.de

#include "linear_system.hpp"
#include "linear_solver_qr.hpp"
#include "utils.hpp"

#include<cassert>
#include<iostream>
#include<cmath>
#include<limits>

#include "dco.hpp"

template<typename T, int N>
T f(
    const typename Linear::System<T,N>::MT& A, 
    const typename Linear::System<T,N>::VT& b
) {
  auto n=b.size();
  Linear::System<T,N> lsys(n);
  lsys.A()=A; lsys.b()=b; 
  Linear::Solver_QR<T,N> lsol;
  lsol.solve(lsys);
  return lsys.x().norm();
}

template<typename T, int N>
typename Linear::System<T,N>::VT dfdb(
    const typename Linear::System<T,N>::MT& A, 
    const typename Linear::System<T,N>::VT& b
) {
  auto n=b.size();
  typename Linear::System<T,N>::VT g(n);
  using DCO_M=typename dco::ga1s<T>;
  using DCO_T=typename DCO_M::type;
  using DCO_TT=typename DCO_M::tape_t;
  DCO_M::global_tape=DCO_TT::create();
  typename Linear::System<DCO_T,N>::MT A_a(n,n);
  typename Linear::System<DCO_T,N>::VT b_a(n);
  for (auto i=0;i<n;i++) {
    for (auto j=0;j<n;j++) A_a(j,i)=A(j,i);
    b_a(i)=b(i);
    DCO_M::global_tape->register_variable(b_a(i));
  }
  DCO_T r_a=f<DCO_T,N>(A_a,b_a); 
  DCO_M::global_tape->register_output_variable(r_a);
  dco::derivative(r_a)=1;
  DCO_M::global_tape->interpret_adjoint();
  for (auto i=0;i<n;i++) g(i)=dco::derivative(b_a(i)); 
  DCO_TT::remove(DCO_M::global_tape);
  return g;
}

int main(int argc, char* argv[]) {
  assert(argc==2); int n=std::stoi(argv[1]); 
  using T=double; const int N=Utils::Dynamic;
  Linear::System<T,N>::MT A=Linear::System<T,N>::MT::Random(n,n); 
  Linear::System<T,N>::VT b=Linear::System<T,N>::VT::Random(n); 
  std::cout << "dfdb=" << std::endl << dfdb<T,N>(A,b) << std::endl;
  return 0;
}

