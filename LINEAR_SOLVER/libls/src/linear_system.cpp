namespace Linear {

template<typename T, int N>
System<T,N>::System(int n) : _x(n), _b(n), _A(n,n) {}

template<typename T, int N>
typename System<T,N>::VT& 
System<T,N>::x() { return _x; }

template<typename T, int N>
typename System<T,N>::VT& 
System<T,N>::b() { return _b; }

template<typename T, int N>
typename System<T,N>::MT& 
System<T,N>::A() { return _A; }

}
