namespace Linear {

template<typename T, int N>
void Solver_LLT<T,N>::solve(System<T,N>& s) {
  Eigen::LLT<typename System<T,N>::MT> LLT(s.A()); 
  s.x()=LLT.solve(s.b());
}

}