// naumann@stce.rwth-aachen.de

#pragma once

#include "nonlinear_system.hpp"

namespace Lotka_Volterra {

const int NS=2; 
const int NP=4; 

template<typename TS, typename TP=TS>
class System : public Nonlinear::System<TS,TP,NS,NP> {
  using Nonlinear::System<TS,TP,NS,NP>::_x;
  using Nonlinear::System<TS,TP,NS,NP>::_p;
public:
  System();
  typename Nonlinear::System<TS,TP,NS,NP>::VTS f();
  typename Nonlinear::System<TS,TP,NS,NP>::MTS dfdx();
};

}

#include "../src/nonlinear_system_lotka_volterra.cpp"
