// naumann@stce.rwth-aachen.de

#pragma once

#include <Eigen/Dense>

namespace Nonlinear {

template<typename TS, typename TP, int NS, int NP>
class System
{
public:
  using VTS=Eigen::Matrix<TS,NS,1>;
  using MTS=Eigen::Matrix<TS,NS,NS>;
  using VTP=Eigen::Matrix<TP,NP,1>;
protected:
  VTS _x; VTP _p;
public:

  System(int,int);
  int ns(); int np();
  VTS& x(); VTP& p(); 
  virtual VTS f()=0;  
  virtual MTS dfdx()=0;  
};

}

#include "../src/nonlinear_system.cpp"
