namespace Ode
{
    /*
    template <typename TS, typename TP, int NS, int NP>
    Solver<TS, TP, NS, NP>::Solver(const TP &T_end, const int nts) : _T_end(T_end), _nts(nts) {}
    */

    template <typename SYS,typename TP>
    Solver<SYS, TP>::Solver(const TP &T_end, const int nts) : _T_end(T_end), _nts(nts) {}
}
