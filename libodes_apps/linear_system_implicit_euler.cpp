#include <iostream>
#include <cassert>
#include <chrono>
#include "ode_system_linear_example.hpp"
#include "linear_solver_qr.hpp"
#include "nonlinear_solver_newton.hpp"
#include "ode_lsolver_implicit_euler.hpp"
#include "ode_nlsolver_implicit_euler.hpp"






int main(int argc, char *argv[])
{
    assert(argc == 4);
    using T = double;
    int _T_end = std::stoi(argv[1]); assert(_T_end > 0);
    /*
        T nts:
        number of time steps to calculate
    */
    T nts = std::stof(argv[2]); assert(nts > 0);

    /*
        T eps:
        error for newton method
    */
    T eps = std::stof(argv[3]); assert(nts > 0);

    Example::Linear_System<T> odesys;
    Example::Nonlinear_System<T> odesys2(odesys.A(),odesys.b());
    //std::cout<<odesys2.g() << std::endl;
    //std::cout<<odesys.b() << 
    //odesys2.x() = odesys.x(); 
    using SYS = Example::Linear_System<T>;
    using SYS2 = Example::Nonlinear_System<T>;
    Linear::Solver_QR<T,Example::NE> lsol;
    Linear::Solver_QR<T,Example::NE> lsol2;
    Nonlinear::Solver_Newton<T,T,Example::NE,Example::NE> nlsol(lsol2,eps);
    Ode::LSolver_Implicit_Euler<SYS,T,Example::NE> odesol(lsol,_T_end,nts);
    Ode::NLSolver_Implicit_Euler<SYS2,T,T,Example::NE,Example::NE> nlodesol(nlsol,_T_end,nts);

    auto linear_start = std::chrono::system_clock::now(); 
    odesol.solve(odesys);
    std::cout << odesys.x().transpose() << std::endl;
    auto linear_end = std::chrono::system_clock::now();
    std::chrono::duration<double> linear_time = linear_end - linear_start;
    std::cout << "Linear Method, elapsed time: " << linear_time.count() << std::endl;

    //Nonlinear Example 
    auto nonlinear_start = std::chrono::system_clock::now();
    nlodesol.solve(odesys2);
    std::cout << odesys2.x().transpose() << std::endl;
    auto nonlinear_end = std::chrono::system_clock::now();
    std::chrono::duration<double> nonlinear_time = nonlinear_end - nonlinear_start;
    std::cout << "Nonlinear Method, elapsed time: " << nonlinear_time.count() << std::endl;

    return 0;
}