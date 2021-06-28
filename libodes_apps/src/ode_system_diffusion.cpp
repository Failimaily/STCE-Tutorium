namespace Diffusion {

template<typename TS, typename TP>
System<TS,TP>::
System(int ns) : Ode::Nonlinear_System<TS,TP,NS,NP>(ns,NP) {} 

template<typename TS, typename TP>
static inline typename Ode::
Nonlinear_System<TS,TP,NS,NP>::VTS 
G(
    typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS& x, 
    typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTP & p
) {
 int ns=x.size();
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS r(ns);
  for (int i=0;i<ns;i++) {
    if (i==0) 
      r(i)=p(0)*x(i)*ns*ns*(p(1)-2*x(i)+x(i+1));
    else if (i==ns-1)
      r(i)=p(0)*x(i)*ns*ns*(x(i-1)-2*x(i)+p(2));
    else
      r(i)=p(0)*x(i)*ns*ns*(x(i-1)-2*x(i)+x(i+1));
  }
  return r;
}

template<typename TS, typename TP>
typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS 
System<TS,TP>::
g() { return G<TS,TP>(_x,_p); }

template<typename TS, typename TP>
typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS 
System<TS,TP>::
dgdx() {
  int ns=_x.size();
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS drdx(ns,ns);
  using DCO_T=typename dco::gt1s<TS>::type; 
  typename Ode::Nonlinear_System<DCO_T,TP,NS,NP>::VTS x_dco (ns),r_dco(ns);
  for (int i=0;i<ns;i++)
    dco::value(x_dco(i))=_x(i);
  for (int i=0;i<ns;i++) {
    dco::derivative(x_dco(i))=1;
    r_dco=G<DCO_T,TP>(x_dco,_p);
    for (int j=0;j<ns;j++)
      drdx(j,i)=dco::derivative(r_dco(j));
    dco::derivative(x_dco(i))=0;
  }
  return drdx;
}

}
