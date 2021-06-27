// naumann@stce.rwth-aachen.de

#pragma once

#include <Eigen/Dense>

namespace Ode
{

  template <typename TS, typename TP, int NS, int NP>
  class System
  {

  public:
    using VTS = Eigen::Matrix<TS, NS, 1>;
    using MTS = Eigen::Matrix<TS, NS, NS>;
    using VTP = Eigen::Matrix<TP, NP, 1>;

  protected:
    VTS _x;
    VTP _p;


  public:
    System(int, int);
    int ns();
    int np();
    VTS &x();
    VTP &p();
    virtual VTS g() = 0;
    virtual MTS dgdx() = 0; //Jacobian
  };

  //New Class only for linear ode systems.
  //TODO Inheritance
  template <typename TS, int NS>
  class Linear_System
  {

  public:
    using VTS = Eigen::Matrix<TS, NS, 1>;
    using MTS = Eigen::Matrix<TS, NS, NS>;

  protected:
    VTS _x;
    VTS _b;
    MTS _A;


  public:
    Linear_System(int);
    int ns();
    VTS &x();
    VTS &b();
    MTS &A();
    VTS g();
  };

}

#include "../src/ode_system.cpp"
