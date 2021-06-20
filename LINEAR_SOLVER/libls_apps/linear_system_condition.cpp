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
typename Linear::System<T,N>::VT x(
    const typename Linear::System<T,N>::MT& A, 
    const typename Linear::System<T,N>::VT& b
) {
  auto n=b.size();
  Linear::System<T,N> lsys(n);
  lsys.A()=A; lsys.b()=b; 
  Linear::Solver_QR<T,N> lsol;
  lsol.solve(lsys);
  return lsys.x();
}

template<typename T, int N>
typename Linear::System<T,N>::MT dxdb(
    const typename Linear::System<T,N>::MT& A, 
    const typename Linear::System<T,N>::VT& b
) {
  auto n=b.size();
  typename Linear::System<T,N>::MT r(n,n);
  using DCO_T=typename dco::gt1s<T>::type;
  typename Linear::System<DCO_T,N>::MT A_t(n,n);
  typename Linear::System<DCO_T,N>::VT b_t(n);
  for (auto i=0;i<n;i++) 
    for (auto j=0;j<n;j++) A_t(j,i)=A(j,i);
  for (auto i=0;i<n;i++) {
    for (auto j=0;j<n;j++) b_t(j)=b(j);
    dco::derivative(b_t(i))=1;
    typename Linear::System<DCO_T,N>::VT x_t=x<DCO_T,N>(A_t,b_t); 
    for (auto j=0;j<n;j++) r(j,i)=dco::derivative(x_t(j));
  }
  return r;
}

int main(int argc, char* argv[]) {
  assert(argc==2); int n=std::stoi(argv[1]); 
  using T=double; const int N=Utils::Dynamic;
  Linear::System<T,N>::MT A=Linear::System<T,N>::MT::Random(n,n); 
  Linear::System<T,N>::VT b=Linear::System<T,N>::VT::Random(n); 
  std::cout << "A=" << std::endl << A << std::endl;
  Linear::System<T,N>::MT dA=dxdb<T,N>(A,b);
  // should be equal to inverse
  std::cout << "dxdb=" << std::endl << dA << std::endl << "=A^-1="
            << std::endl << A.partialPivLu().inverse() << std::endl;
  // should be equal to identity
  std::cout << "A*dxdb=" << std::endl << A*dA << std::endl;
  // should be equal to condition
  std::cout << "||A||*||dxdb||=" << A.norm()*dA.norm() << "=cond(A)="
            << A.norm()*A.partialPivLu().inverse().norm() << std::endl;
  return 0;
}
