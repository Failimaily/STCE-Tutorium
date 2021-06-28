#include "ode_system_implicit_euler.hpp"
namespace Ode{

    template <typename SYS,typename TS, int NS>
    class LSystem_Implicit_Euler : public Linear::System<TS,NS>
    {

        using VTS = typename Ode::System_Implicit_Euler<SYS,TS>::VTS;
        using Ode::System_Implicit_Euler<SYS,TS>::_odes;
        using Ode::System_Implicit_Euler<SYS,TS>::_x_prev;
        using Ode::System_Implicit_Euler<SYS,TS>::_dt;
        public:
            LSystem_Implicit_Euler(SYS &,const VTS &,const TS &);
    };

    template <typename SYS,typename TS, int NS>
    class LSolver_Implicit_Euler : public Solver<SYS,TS>
    {
        Linear::Solver<TS,NS> &lsol;

        public:
            using Ode::Solver<SYS,TS>::_T_end;
            using Ode::Solver<SYS,TS>::_nts;
            LSolver_Implicit_Euler(Linear::Solver<TS,NS> &, const TS &, const int);
            void solve(SYS &);
    };
}


#include "../src/ode_lsolver_implicit_euler.cpp"