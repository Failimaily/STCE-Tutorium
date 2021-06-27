namespace Ode
{

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    NLSystem_Implicit_Euler<SYS, TS, TP, NS, NP>::
        NLSystem_Implicit_Euler(
            SYS &odes,
            const typename SYS::VTS &x_prev,
            const TP &dt) : Nonlinear::System<TS, TP, NS, NP>(odes.ns(), odes.np()),
                            _odes(odes), _x_prev(x_prev), _dt(dt)
    {
        Nonlinear::System<TS, TP, NS, NP>::x() = _x_prev;
    }

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    typename SYS::VTS
    NLSystem_Implicit_Euler<SYS, TS, TP, NS, NP>::
        f()
    {
        _odes.x() = Nonlinear::System<TS, TP, NS, NP>::x();
        return _odes.x() - _x_prev - _dt * _odes.g();
    }

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    typename SYS::MTS NLSystem_Implicit_Euler<SYS, TS, TP, NS, NP>::
        dfdx()
    {
        _odes.x() = Nonlinear::System<TS, TP, NS, NP>::x();
        return SYS::MTS::Identity(_odes.x().size(), _odes.x().size()) - _dt * _odes.dgdx();
    }

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    NLSolver_Implicit_Euler<SYS, TS, TP, NS, NP>::
        NLSolver_Implicit_Euler(Nonlinear::Solver<TS, TP, NS, NP> &nlsol, const TP &T_end, const int nts) : Ode::Solver<SYS, TP>(T_end, nts), _nlsol(nlsol) {}

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    void
    NLSolver_Implicit_Euler<SYS, TS, TP, NS, NP>::
        solve(
            SYS &odes)
    {
        for (int i = 0; i < _nts; i++)
        {
            typename SYS::VTS x_prev = odes.x();
            typename Ode::NLSystem_Implicit_Euler<SYS, TS, TP, NS, NP> nlsys(odes, x_prev, _T_end / _nts);
            _nlsol.solve(nlsys);
            odes.x() = nlsys.x();
        }
    }

}