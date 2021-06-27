namespace Ode
{

    template <typename TS, typename TP, int NS, int NP>
    System<TS, TP, NS, NP>::
        System(int ns, int np) : _x(ns), _p(np) {}

    template <typename TS, typename TP, int NS, int NP>
    int System<TS, TP, NS, NP>::ns() { return _x.size(); }

    template <typename TS, typename TP, int NS, int NP>
    int System<TS, TP, NS, NP>::np() { return _p.size(); }

    template <typename TS, typename TP, int NS, int NP>
    typename System<TS, TP, NS, NP>::VTS &System<TS, TP, NS, NP>::x() { return _x; }

    template <typename TS, typename TP, int NS, int NP>
    typename System<TS, TP, NS, NP>::VTP &System<TS, TP, NS, NP>::p() { return _p; }


    template <typename TS, int NS>
    Linear_System<TS,NS>::
                        Linear_System(int ns) : _x(ns), _b(ns), _A(ns) {}

    template <typename TS, int NS>
    int Linear_System<TS,NS>::ns() {return _x.size();}
    
    template <typename TS, int NS>
    typename Linear_System<TS,NS>::VTS &Linear_System<TS,NS>::x() {return _x;}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::VTS &Linear_System<TS,NS>::b() {return _b;}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::MTS &Linear_System<TS,NS>::A() {return _A;}

    template <typename TS, int NS>
    typename Linear_System<TS,NS>::VTS Linear_System<TS,NS>::g() {return _A* _x + _b;}


}
