#include "dco.hpp"

namespace Lotka_Volterra {

template<typename TS, typename TP>
System<TS,TP>::System() : Nonlinear::System<TS,TP,NS,NP>::System(NS,NP) {}

template<typename TS, typename TP>
static inline typename Nonlinear::System<TS,TP,NS,NP>::VTS
F(const typename Nonlinear::System<TS,TP,NS,NP>::VTS& x, const typename Nonlinear::System<TS,TP,NS,NP>::VTP& p) { 
  typename Nonlinear::System<TS,TP,NS,NP>::VTS r(NS);
  r(0)=(p(0)-p(1)*x(1))*x(0);
  r(1)=-(p(2)-p(3)*x(0))*x(1);
  return r;
}

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::VTS
System<TS,TP>::f() { return F<TS,TP>(_x,_p); }

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::MTS
System<TS,TP>::dfdx() { 
  typename Nonlinear::System<TS,TP,NS,NP>::MTS drdx(NS,NS);
  using DCO_T=typename dco::gt1s<TS>::type;
  typename Nonlinear::System<DCO_T,TP,NS,NP>::VTS x_t,r_t;
  for (auto i=0;i<NS;i++) 
    dco::value(x_t(i))=_x(i);
  for (auto i=0;i<NS;i++) {
    dco::derivative(x_t(i))=1;
    r_t=F<DCO_T,TP>(x_t,_p);
    for (auto j=0;j<NS;j++) 
      drdx(j,i)=dco::derivative(r_t(j)); 
    dco::derivative(x_t(i))=0;
  }
  return drdx;
}

}
