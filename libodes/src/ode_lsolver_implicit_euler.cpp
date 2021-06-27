namespace Ode
{

    template<typename SYS,typename TS, int NS>
    LSystem_Implicit_Euler::
        LSystem_Implicit_Euler(
            SYS &odes,
            const typename LSystem_Implicit_Euler<SYS, TS, NS>::VTS &x_prev,
            const TP &dt) : Linear::System<TS, NS>(odes.ns()),
                            _odes(odes), _x_prev(x_prev), _dt(dt)
    {
        Linear::System<TS,NS>::x() = _x_prev;
    }

    template<typename SYS,typename TS, int NS>
    void LSystem_Implicit_Euler<SYS,TS,NS>::
    solve(SYS &odes)
    {

    }
}
