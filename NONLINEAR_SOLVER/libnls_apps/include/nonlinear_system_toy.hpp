// naumann@stce.rwth-aachen.de

#pragma once

#include "nonlinear_system.hpp"

namespace Toy {

const int NS=1;
const int NP=1;

template<typename TS, typename TP>
class System : public Nonlinear::System<TS,TP,1,1>
{
  using Nonlinear::System<TS,TP,NS,NP>::_x;
  using Nonlinear::System<TS,TP,NS,NP>::_p;
public:
  System();
  typename Nonlinear::System<TS,TP,NS,NP>::VTS f();
  typename Nonlinear::System<TS,TP,NS,NP>::MTS dfdx();
};

}

#include "../src/nonlinear_system_toy.cpp"

