namespace Linear {

template<typename T, int N>
void Solver_QR<T,N>::solve(System<T,N>& s) {
  Eigen::HouseholderQR<typename System<T,N>::MT> QR(s.A()); 
  s.x()=QR.solve(s.b());
}

}
