#include "dco.hpp"

namespace Toy {

template<typename TS, typename TP>
System<TS,TP>::System() : Nonlinear::System<TS,TP,NS,NP>(NS,NP) {}

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::VTS 
System<TS,TP>::f() {
  typename Nonlinear::System<TS,TP,NS,NP>::VTS r;
  r(0)=_x(0)*_x(0)-_p(0); 
  return r;
}

template<typename TS, typename TP>
typename Nonlinear::System<TS,TP,NS,NP>::MTS 
System<TS,TP>::dfdx() {
  typename Nonlinear::System<TS,TP,NS,NP>::MTS drdx;
  drdx(0,0)=2*_x(0);
  return drdx;
} 

}
