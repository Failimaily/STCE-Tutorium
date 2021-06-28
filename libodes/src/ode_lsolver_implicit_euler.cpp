namespace Ode
{

    template <typename SYS, typename TS, int NS>
    LSystem_Implicit_Euler<SYS, TS, NS>::
        LSystem_Implicit_Euler(
            SYS &odes,
            const typename LSystem_Implicit_Euler<SYS, TS, NS>::VTS &x_prev,
            const TS &dt) : Linear::System<TS, NS>(odes.ns()),
                            System_Implicit_Euler<SYS, TS>(odes, x_prev, dt)
    {
        
        Linear::System<TS, NS>::b() = _x_prev + _dt*_odes.b();
        Linear::System<TS, NS>::A() = SYS::MTS::Identity(_odes.x().size(),_odes.x().size()) - dt*_odes.A();
    }
    template <typename SYS, typename TS, int NS>
    LSolver_Implicit_Euler<SYS, TS, NS>::
        LSolver_Implicit_Euler(
            Linear::Solver<TS, NS> &lsol,
            const TS &T_end,
            const int nts) :   Solver<SYS,TS>(T_end,nts),
                                _lsol(lsol)
    {
    }

    template <typename SYS, typename TS, int NS>
    void LSolver_Implicit_Euler<SYS, TS, NS>::
        solve(SYS &odes)
    {
        for (int i = 0; i < _nts; i++)
        {
            TS dt = (_T_end / _nts);
            typename SYS::VTS x_prev = odes.x();
            typename Ode::LSystem_Implicit_Euler<SYS, TS, NS> lsys(odes, x_prev, dt);
            _lsol.solve(lsys);
            odes.x() = lsys.x();
        }
    }
}
