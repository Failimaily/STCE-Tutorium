// naumann@stce.rwth-aachen.de

#pragma once

#include <Eigen/Dense>

namespace Linear {

template<typename T, int N>
class System {

public:
  using MT=Eigen::Matrix<T,N,N>;
  using VT=Eigen::Matrix<T,N,1>;

protected:
  VT _x,_b; MT _A;

public:
  System(int); 
  VT& x(); VT& b(); MT& A(); 
};

}

#include "../src/linear_system.cpp"
