namespace Ode  {


  template <typename TS, typename TP, int NS, int NP>
  Solver_Linear<TS, TP, NS, NP>::
      Solver_Linear(Linear::Solver<TS, TP, NS, NP> &lsol, const TP &T_end, const int nts) : Ode::Solver<TS, TP, NS, NP>(T_end, nts), _lsol(lsol) {}


}
