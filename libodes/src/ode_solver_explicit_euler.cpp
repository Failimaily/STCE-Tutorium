namespace Ode
{
/*
  template <typename TS, typename TP, int NS, int NP>
  Solver_Explicit_Euler<TS, TP, NS, NP>::
      Solver_Explicit_Euler(const TP &T_end, const int nts) : Solver<TS, TP, NS, NP>(T_end, nts) {}

  template <typename TS, typename TP, int NS, int NP>
  void
  Solver_Explicit_Euler<TS, TP, NS, NP>::
      solve(System<TS, TP, NS, NP> &odes)
  {
    for (int i = 0; i < _nts; i++)
      odes.x() = odes.x() + _T_end / _nts * odes.g();
  }
*/
  template <typename SYS, typename TP>
    Solver_Explicit_Euler<SYS, TP>::
        Solver_Explicit_Euler(const TP &T_end, const int nts) : Solver<SYS, TP>(T_end, nts) {}

    template <typename SYS, typename TP>
    void
    Solver_Explicit_Euler<SYS, TP>::
        solve(SYS &odes)
    {
      for (int i = 0; i < _nts; i++)
        odes.x() = odes.x() + _T_end / _nts * odes.g();
    }
}
