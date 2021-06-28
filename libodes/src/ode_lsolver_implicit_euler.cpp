namespace Ode
{

    template<typename SYS,typename TS, int NS>
    LSystem_Implicit_Euler<SYS,TS,NS>::
        LSystem_Implicit_Euler(
            SYS &odes,
            const typename LSystem_Implicit_Euler<SYS,TS,NS>::VTS &x_prev,
            const TS &dt) : Linear::System<TS, NS>(odes.ns()),
                            System_Implicit_Euler<SYS,TS>(odes,x_prev,dt)
    {
        Linear::System<TS,NS>::x() = _x_prev;
    }

    template<typename SYS,typename TS, int NS>
    void LSystem_Implicit_Euler<SYS,TS,NS>::
    solve(SYS &odes)
    {

    }
}
