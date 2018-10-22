#include <iostream>

class A{
public:
  template<typename T> void func(T a){
    std::cout << a << std::endl;
  }
};

template void A::func(int a);
template void A::func(char const *);
