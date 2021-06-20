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
  using DCO_T=typename dco::gt1s<T>::type;
  typename Linear::System<DCO_T,N>::MT A_t(n,n);
  typename Linear::System<DCO_T,N>::VT b_t(n);
  for (auto i=0;i<n;i++) {
    for (auto j=0;j<n;j++) A_t(j,i)=A(j,i);
    b_t(i)=b(i);
  }
  for (auto i=0;i<n;i++) {
    dco::derivative(b_t(i))=1;
    g(i)=dco::derivative(f<DCO_T,N>(A_t,b_t)); 
    dco::derivative(b_t(i))=0;
  }
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

