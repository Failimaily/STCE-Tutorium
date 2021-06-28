namespace Ode
{
  /*
  template <typename TS, typename TP, int NS, int NP>
  System_Implicit_Euler<TS, TP, NS, NP>::
      System_Implicit_Euler(
          typename Ode::System<TS, TP, NS, NP> &odes,
          const typename System_Implicit_Euler<TS, TP, NS, NP>::VTS &x_prev,
          const TP &dt) : Nonlinear::System<TS, TP, NS, NP>(odes.ns(), odes.np()),
                        //: Linear::System<TS,TP,NS,NP>(odes.ns(),odes.np()),
                          _odes(odes), _x_prev(x_prev), _dt(dt)
  {
    Nonlinear::System<TS, TP, NS, NP>::x() = _x_prev;
  }

  template <typename TS, typename TP, int NS, int NP>
  typename System_Implicit_Euler<TS, TP, NS, NP>::VTS
  System_Implicit_Euler<TS, TP, NS, NP>::
      f()
  {
    _odes.x() = Nonlinear::System<TS, TP, NS, NP>::x();
    return _odes.x() - _x_prev - _dt * _odes.g();
  }

  template <typename TS, typename TP, int NS, int NP>
  typename System_Implicit_Euler<TS, TP, NS, NP>::MTS
  System_Implicit_Euler<TS, TP, NS, NP>::
      dfdx()
  {
    _odes.x() = Nonlinear::System<TS, TP, NS, NP>::x();
    return MTS::Identity(_odes.x().size(), _odes.x().size()) - _dt * _odes.dgdx();
  }

  template <typename TS, typename TP, int NS, int NP>
  Solver_Implicit_Euler<TS, TP, NS, NP>::
      Solver_Implicit_Euler(Nonlinear::Solver<TS, TP, NS, NP> &nlsol, const TP &T_end, const int nts) : Ode::Solver<TS, TP, NS, NP>(T_end, nts), _nlsol(nlsol) {}

  template <typename TS, typename TP, int NS, int NP>
  Solver_Implicit_Euler<TS, TP, NS, NP>::
      Solver_Implicit_Euler(Linear::Solver<TS, NS> &lsol) {}

  template <typename TS, typename TP, int NS, int NP>
  void
  Solver_Implicit_Euler<TS, TP, NS, NP>::
      solve(
          Ode::System<TS, TP, NS, NP> &odes)
  {
    if(odes.isLinear)
    {

    }
    else
    {
      for (int i = 0; i < _nts; i++)
      {
        typename Ode::System<TS, TP, NS, NP>::VTS x_prev = odes.x();
        typename Ode::System_Implicit_Euler<TS, TP, NS, NP> nlsys(odes, x_prev, _T_end / _nts);
        _nlsol.solve(nlsys);
        odes.x() = nlsys.x();
      }
    }
    
  }
  */

  template <typename SYS, typename TP>
  System_Implicit_Euler<SYS,TP>::
      System_Implicit_Euler(
          SYS &odes,
          const typename SYS::VTS &x_prev,
          const TP &dt) : _odes(odes), _x_prev(x_prev), _dt(dt)
          {}
}
