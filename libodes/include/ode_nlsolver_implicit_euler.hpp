#include "ode_system_implicit_euler.hpp"

//Todo Includes
namespace ode
{

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    class NLSystem_Implicit_Euler : public System_Implicit_Euler<SYS, TP>, public Nonlinear::System<TS, TP, NS, NP>
    {
    public:
        System_Implicit_Euler(SYS &, const VTS &, const TP &);
        VTS f();
        MTS dfdx();
    };

    template <typename SYS, typename TS, typename TP, int NS, int NP>
    class NLSolver_Implicit_Euler : public Solver<SYS, TP>
    {
        typename Nonlinear::Solver<TS, TP, NS, NP> &_nlsol;

    public:
        using Ode::Solver<SYS, TP>::_T_end;
        using Ode::Solver<SYS, TP>::_nts;
        NLSolver_Implicit_Euler(Nonlinear::Solver<TS, TP, NS, NP> &, const TP &, const int);
        void solve(SYS &);
    };

#include "../src/ode_nlsolver_implicit_euler.cpp"
}