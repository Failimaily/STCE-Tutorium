// naumann@stce.rwth-aachen.de

#include "ode_system.hpp"
#include "utils.hpp"

#include "dco.hpp"

namespace Diffusion {

const int NS=Utils::Dynamic;
const int NP=3;

template<typename TS, typename TP>
class System : public Ode::Nonlinear_System<TS,TP,NS,NP>
{
  using Ode::Nonlinear_System<TS,TP,NS,NP>::_x;
  using Ode::Nonlinear_System<TS,TP,NS,NP>::_p;

public:
  System(int);
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::VTS g();
  typename Ode::Nonlinear_System<TS,TP,NS,NP>::MTS dgdx();
};

}

#include "../src/ode_system_diffusion.cpp"
