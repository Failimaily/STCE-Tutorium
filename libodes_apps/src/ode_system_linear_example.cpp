namespace Example
{
    template<typename TS>
    Linear_System<TS>::
    Linear_System() : Ode::Linear_System<TS,NE>(NE)
    {
        _A = MTS::Random(NE,NE);
        _b = VTS::Random(NE);
        _x = VTS::Ones(NE);
    };

    template<typename TS>
    int Linear_System<TS>::np()
    {
        return NE;
    }
 
    template<typename TS>
    static inline typename Linear_System<TS>::
    VTS G(
        typename Linear_System<TS>::VTS x,
        typename Linear_System<double>::MTS A,
        typename Linear_System<double>::VTS b,
        int j
    )
    {
        typename Ode::Linear_System<TS,NE>::VTS r(NE);
        for(int i = 0;i<NE;i++)
        {
            r(i) = A(j,i) * x(i) + b(i);
        }
        return r;
    }

    template<typename TS>
    typename Linear_System<TS>::MTS Linear_System<TS>::dgdx()
    {
        typename Linear_System<TS>::MTS drdx(NE,NE);
        using DCO_T = typename dco::gt1s<TS>::type;
        typename Ode::Linear_System<DCO_T,NE>::VTS x_dco(NE),r_dco(NE);
        for(int i=0;i<NE;i++)
        {
            dco::value(x_dco(i)) = _x(i);
        }
        for(int i=0;i<NE;i++)
        {
            dco::derivative(x_dco(i))=1;
            r_dco = G<DCO_T>(x_dco,_A,_b,i);
            for(int j=0;j<NE;j++)
            {
                drdx(i,j)=dco::derivative(r_dco(j));
            }
            dco::derivative(x_dco(i))=0;

        }
        //std::cout << drdx << std::endl;
        //std::cout << _A << std::endl;
        return drdx;
         
    }

    template<typename TS>
    Nonlinear_System<TS>::
    Nonlinear_System(
    typename Ode::Linear_System<TS,NE>::MTS A,
    typename Ode::Linear_System<TS,NE>::VTS b
    ) : Ode::Nonlinear_System<TS,TS,NE,NE>(NE,NE),
    _A(A),_b(b)
    { 
        _x = Ode::Nonlinear_System<TS,TS,NE,NE>::VTS::Ones(NE);
    };

    template<typename TS>
    typename Ode::Nonlinear_System<TS, TS, NE, NE>::VTS
    Nonlinear_System<TS>::g()
    {
        return _A * _x + _b;
    }

    template<typename TS>
    typename Ode::Nonlinear_System<TS, TS, NE, NE>::VTS&
    Nonlinear_System<TS>::x()
    {
        return _x;
    }

    template<typename TS>
    typename Ode::Nonlinear_System<TS, TS, NE, NE>::MTS Nonlinear_System<TS>::dgdx()
    {
        typename Nonlinear_System<TS>::MTS drdx(NE,NE);
        using DCO_T = typename dco::gt1s<TS>::type;
        typename Ode::Nonlinear_System<DCO_T,DCO_T,NE,NE>::VTS x_dco(NE),r_dco(NE);
        for(int i=0;i<NE;i++)
        {
            dco::value(x_dco(i)) = _x(i);
        }
        for(int i=0;i<NE;i++)
        {
            dco::derivative(x_dco(i))=1;
            r_dco = G<DCO_T>(x_dco,_A,_b,i);
            for(int j=0;j<NE;j++)
            {
                drdx(i,j)=dco::derivative(r_dco(j));
            }
            dco::derivative(x_dco(i))=0;

        }
        //std::cout << drdx << std::endl;
        //std::cout << _A << std::endl;
        return drdx;
         
    }
}