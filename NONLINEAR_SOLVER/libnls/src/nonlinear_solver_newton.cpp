namespace Nonlinear {

template<typename TS, typename TP, int NS, int NP>
Solver_Newton<TS,TP,NS,NP>::Solver_Newton(Linear::Solver<TS,NS>& lsol, const TS& eps) : _lsol(lsol), _eps(eps) {}

template<typename TS, typename TP, int NS, int NP>
void 
Solver_Newton<TS,TP,NS,NP>::solve(System<TS,TP,NS,NP>& nlsys) {
  Linear::System<TS,NS> lsys(nlsys.ns());
  while (nlsys.f().norm()>_eps) {
    lsys.A()=nlsys.dfdx(); lsys.b()=-nlsys.f();
    _lsol.solve(lsys);
    nlsys.x()+=lsys.x();
    //std::cout<<lsys.A()<<std::endl;
    //std::cout<<lsys.b().transpose()<<std::endl;
  }
}

}
