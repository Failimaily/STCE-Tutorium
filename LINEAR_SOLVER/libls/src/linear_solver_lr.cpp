namespace Linear {

template<typename T, int N>
void Solver_LR<T,N>::solve(System<T,N>& s) {
  Eigen::PartialPivLU<typename System<T,N>::MT> LR(s.A()); 
  s.x()=LR.solve(s.b());
}

}
