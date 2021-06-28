namespace Lotka_Volterra {

template<typename TS, typename TP>
System<TS,TP>::System() : Ode::Nonlinear_System<TS,TP,NS,NP>(NS,NP) {} 

template<typename TS, typename TP>
typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS
System<TS,TP>::g() { 
    typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS r;
    r(0)=(_p(0)-_p(1)*_x(1))*_x(0);
    r(1)=-(_p(2)-_p(3)*_x(0))*_x(1);
    return r;
  }

template<typename TS, typename TP>
typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS 
System<TS,TP>::dgdx() { 
    typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS drdx;
    drdx(0,0)=_p(0)-_p(1)*_x(1); 
    drdx(0,1)=-_p(1)*_x(0);
    drdx(1,0)=_p(3)*_x(1); 
    drdx(1,1)=-(_p(2)-_p(3)*_x(0));
    return drdx;
  }

}
