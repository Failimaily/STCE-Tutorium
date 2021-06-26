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
    //VTP _b;
    //MTS _A;


  public:
    System(int, int);
    int ns();
    int np();
    bool isLinear;
    VTS &x();
    VTP &p();
    //VTS &b();
    //MTS &A();
    virtual VTS g() = 0;
    virtual MTS dgdx() = 0; //Jacobian
  };

}

#include "../src/ode_system.cpp"
