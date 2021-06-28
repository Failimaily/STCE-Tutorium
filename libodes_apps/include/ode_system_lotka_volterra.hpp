// naumann@stce.rwth-aachen.de

#pragma once

#include "ode_system.hpp"

namespace Lotka_Volterra {

const int NS=2;
const int NP=4;

template<typename TS, typename TP>
class System : public Ode::Nonlinear_System<TS,TP,NS,NP> {
  using Ode::Nonlinear_System<TS,TP,NS,NP>::_x;
  using Ode::Nonlinear_System<TS,TP,NS,NP>::_p;
public:
  System();
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS g();
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS dgdx();
};

}

#include "../src/ode_system_lotka_volterra.cpp"
