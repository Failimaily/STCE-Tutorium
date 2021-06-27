#include "ode_system_implicit_euler.hpp"
namespace ode{

    template <typename SYS,typename TS, int NS>
    class LSystem_Implicit_Euler : public Linear::System<TS,NS>
    {
        public:
            LSystem_Implicit_Euler(SYS &,const VTS &,const TS &);
    };

    template <typename SYS,typename TS, int NS>
    class LSolver_Implicit_Euler : public Solver<SYS,TP>
    {
        Linear::Solver<TS,NS> &lsol;

        public:
            using Ode::Solver<SYS,TP>::_T_end;
            using Ode::Solver<SYS,TP>::_nts;
            LSolver_Implicit_Euler(Linear::Solver<TS,NS> &, const TS &, const int);
            void solve(SYS &);
    };
}


#include "../src/ode_lsolver_implicit_euler.cpp"