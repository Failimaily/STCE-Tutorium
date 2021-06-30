// naumann@stce.rwth-aachen.de

#pragma once

#include <Eigen/Dense>

namespace Ode
{
  template <typename TS, int NS>
  class System
  {
  public:
    using VTS = Eigen::Matrix<TS, NS, 1>;
    using MTS = Eigen::Matrix<TS, NS, NS>;
    VTS _x;
  public:
    System(int);
    VTS &x();
    int ns();
    virtual VTS g() = 0;
  };

  template <typename TS, typename TP, int NS, int NP>
  class Nonlinear_System : public System<TS, NS>
  {

  public:
    using VTS = typename System<TS, NS>::VTS;
    using MTS = typename System<TS, NS>::MTS;
    using VTP = Eigen::Matrix<TP, NP, 1>;

  protected:
    using System<TS,NS>::_x;
    
    VTP _p;

  public:
    Nonlinear_System(int, int);
    VTS &x();
    int np();
    VTP &p();
    virtual MTS dgdx() = 0; //Jacobian
  };

  //New Class only for linear ode systems.
  //TODO Inheritance
  template <typename TS, int NS>
  class Linear_System : public System<TS, NS>
  {

  public:
    using VTS = typename System<TS, NS>::VTS;
    using MTS = Eigen::Matrix<TS, NS, NS>;

  protected:
    VTS _b;
    MTS _A;
    using System<TS,NS>::_x;
  public:
    Linear_System(int);
    VTS &b();
    MTS &A();
    VTS g();
    //MTS dgdx();
  };

}

#include "../src/ode_system.cpp"
