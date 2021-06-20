#include "dco.hpp"

namespace Diffusion {

template<typename TS, typename TP>
System<TS,TP>::System(int s) : Nonlinear::System<TS,TP,NS,NP>(s,NP) {}

template<typename TS, typename TP>
static inline typename Nonlinear::System<TS,TP,NS,NP>::VTS
F(const typename Nonlinear::System<TS,TP,NS,NP>::VTS& x, const typename Nonlinear::System<TS,TP,NS,NP>::VTP& p) {
  int s=x.size(); 
  typename Nonlinear::System<TS,TP,NS,NP>::VTS r(s);
  for (int i=0;i<s;i++) {
    if (i==0)
      r(i)=p(0)*s*s*(p(1)-2*x(i)+x(i+1));
    else if (i==s-1)
      r(i)=p(0)*s*s*(x(i-1)-2*x(i)+p(2));
    else 
      r(i)=p(0)*s*s*(x(i-1)-2*x(i)+x(i+1));
  }
  return r;
}

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::VTS
System<TS,TP>::f() { return F<TS,TP>(_x,_p); }

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::MTS
System<TS,TP>::dfdx() {
  auto s=_x.size();
  typename Nonlinear::System<TS,TP,NS,NP>::MTS drdx(s,s);
using DCO_T=typename dco::gt1s<TS>::type;
typename Nonlinear::System<DCO_T,TP,NS,NP>::VTS x_t(s), r_t(s);
  for (auto i=0;i<s;i++) dco::value(x_t(i))=_x(i);
  for (auto i=0;i<s;i++) {
    dco::derivative(x_t(i))=1;
    r_t=F<DCO_T,TP>(x_t,_p);
    for (auto j=0;j<s;j++) drdx(j,i)=dco::derivative(r_t(j));
    dco::derivative(x_t(i))=0;
  }
  return drdx;
}

}
