// naumann@stce.rwth-aachen.de

#pragma once

#include "nonlinear_system.hpp"
#include "utils.hpp"

#include "dco.hpp"

namespace Diffusion {

const int NS=Utils::Dynamic;
const int NP=3;

template<typename TS, typename TP>
class System : public Nonlinear::System<TS,TP,NS,NP> {
  using Nonlinear::System<TS,TP,NS,NP>::_x;
  using Nonlinear::System<TS,TP,NS,NP>::_p;
public:
  System(int);
  typename Nonlinear::System<TS,TP,NS,NP>::VTS f();
  typename Nonlinear::System<TS,TP,NS,NP>::MTS dfdx();

};

}

#include "../src/nonlinear_system_diffusion.cpp"

