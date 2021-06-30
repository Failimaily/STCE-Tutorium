#include "ode_system_implicit_euler.hpp"

namespace Ode
{

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    class NLSystem_Implicit_Euler : public System_Implicit_Euler<SYS,TS>, public Nonlinear::System<TS, TP, NS, NP>
    {
        /*
        SYS &_odes;
        typename SYS::VTS _x_prev;
        TP _dt;
        */
    public:
        using Ode::System_Implicit_Euler<SYS,TP>::_odes;
        using Ode::System_Implicit_Euler<SYS,TP>::_x_prev;
        using Ode::System_Implicit_Euler<SYS,TP>::_dt;
        NLSystem_Implicit_Euler(SYS &, const typename SYS::VTS &, const TP &);
        typename SYS::VTS f();
        typename SYS::MTS dfdx();
    };

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    class NLSolver_Implicit_Euler : public Solver<SYS, TP>
    {
        using VTS = typename SYS::VTS;
        using MTS = typename SYS::MTS;
        typename Nonlinear::Solver<TS, TP, NS, NP> &_nlsol;

    public:
        using Ode::Solver<SYS, TP>::_T_end;
        using Ode::Solver<SYS, TP>::_nts;
        NLSolver_Implicit_Euler(Nonlinear::Solver<TS, TP, NS, NP> &, const TP &, const int);
        void solve(SYS &);
    };
}

#include "../src/ode_nlsolver_implicit_euler.cpp"