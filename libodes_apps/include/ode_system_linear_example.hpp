/*
Case Study for the our implementation of a solver for linear ode systems.
For simplicity we chose a system which does not posess a parameter vector.

The eqaution is some like 
vector(x') = matrix(A) * vector(x) + vector(b)
*/
#include "ode_system.hpp"
#include "utils.hpp"

#include "dco.hpp"

namespace Example
{
    const int NE = 3;

    template <typename TS>
    class Linear_System : public Ode::Linear_System<TS, NE>
    {
        // the vector _x is the initial state of the system,
        // it will be changed by the linear solver to the next step of x.
        using Ode::Linear_System<TS, NE>::_x;
        // the matrix _A is the coefficient matrix of the system.
        using Ode::Linear_System<TS, NE>::_A;
        // the vector _b is  a parameter vector, indepentant from any x .
        using Ode::Linear_System<TS, NE>::_b;

    public:
        Linear_System();
        using VTS = typename Ode::Linear_System<TS, NE>::VTS;
        using MTS = typename Ode::Linear_System<TS, NE>::MTS;
        int np();
        //VTS G(VTS,int); //???
        MTS dgdx();
    };

    template <typename TS>
    class Nonlinear_System : public Ode::Nonlinear_System<TS,TS,NE,NE>
    {
        using Ode::Nonlinear_System<TS, TS, NE, NE>::_x;
        //using Ode::Nonlinear_System<TS, TS, NE, NE>::_p;
        typename Ode::Linear_System<TS,NE>::MTS _A;
        typename Ode::Linear_System<TS,NE>::VTS _b;   
    public:
        Nonlinear_System(typename Ode::Linear_System<TS,NE>::MTS,typename Ode::Linear_System<TS,NE>::VTS);
        typename Ode::Nonlinear_System<TS, TS, NE, NE>::VTS &x();
        typename Ode::Nonlinear_System<TS, TS, NE, NE>::VTS g();
        typename Ode::Nonlinear_System<TS, TS, NE, NE>::MTS dgdx();
    };

}

#include "../src/ode_system_linear_example.cpp"