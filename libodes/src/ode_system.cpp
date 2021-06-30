namespace Ode
{
    template <typename TS, int NS>
    System<TS, NS>::
        System(int ns) : _x(ns) {}

    template <typename TS, int NS>
    typename System<TS,NS>::VTS& System<TS, NS>::
        x(){ return _x;}

    template <typename TS, int NS>
    int System<TS, NS>::
        ns(){ return _x.size();}

    template <typename TS, typename TP, int NS, int NP>
    Nonlinear_System<TS, TP, NS, NP>::
        Nonlinear_System(int ns, int np) : System<TS,NS>(ns), _p(np) {}

    template <typename TS, typename TP, int NS, int NP>
    int Nonlinear_System<TS, TP, NS, NP>::np() { return _p.size(); }

    template <typename TS, typename TP, int NS, int NP>
    typename Nonlinear_System<TS, TP, NS, NP>::VTS &Nonlinear_System<TS, TP, NS, NP>::x() { return _x; }

    template <typename TS, typename TP, int NS, int NP>
    typename Nonlinear_System<TS, TP, NS, NP>::VTP &Nonlinear_System<TS, TP, NS, NP>::p() { return _p; }


    template <typename TS, int NS>
    Linear_System<TS,NS>::
                        Linear_System(int ns) : System<TS,NS>(ns), _b(ns), _A(ns,ns) {}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::VTS &Linear_System<TS,NS>::b() {return _b;}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::MTS &Linear_System<TS,NS>::A() {return _A;}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::VTS Linear_System<TS,NS>::g() {return _A* _x + _b;}

    //template <typename TS, int NS>
    //typename Linear_System<TS,NS>::MTS Linear_System<TS,NS>::dgdx() {return _A;}

}
