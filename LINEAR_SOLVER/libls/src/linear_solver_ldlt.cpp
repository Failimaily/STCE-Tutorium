namespace Linear {

template<typename T, int N>
void Solver_LDLT<T,N>::solve(System<T,N>& s) {
  Eigen::LDLT<typename System<T,N>::MT> LDLT(s.A()); 
  s.x()=LDLT.solve(s.b());
}

}