#include "ode_system_implicit_euler.hpp"
namespace Ode
{

    template <typename SYS, typename TS, int NS>
    class LSystem_Implicit_Euler : public Linear::System<TS, NS>, public System_Implicit_Euler<SYS, TS>
    {

    public:
        using VTS = typename System_Implicit_Euler<SYS, TS>::VTS;
        using System_Implicit_Euler<SYS, TS>::_odes;
        using System_Implicit_Euler<SYS, TS>::_x_prev;
        using System_Implicit_Euler<SYS, TS>::_dt;
        LSystem_Implicit_Euler(SYS &, const VTS &, const TS &);
    };

    template <typename SYS, typename TS, int NS>
    class LSolver_Implicit_Euler : public Solver<SYS, TS>
    {
        Linear::Solver<TS, NS> &_lsol;

    public:
        using Ode::Solver<SYS, TS>::_T_end;
        using Ode::Solver<SYS, TS>::_nts;
        LSolver_Implicit_Euler(Linear::Solver<TS, NS> &, const TS &, const int);
        void solve(SYS &);
    };
}

#include "../src/ode_lsolver_implicit_euler.cpp"