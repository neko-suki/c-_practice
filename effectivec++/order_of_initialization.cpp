#include <iostream>

class A{
public:
  A(){
    std::cout << "Default constructor of A is called" << std::endl;
  }
};

class B{
public:
  B(){
    std::cout << "Default constructor of B is called" << std::endl;
  }
};

class C{
public:
  C(){
    std::cout << "Default constructor of C is called" << std::endl;
  }
};

class D{
public:
  D(): c(), b(), a(){
    std::cout << "Default constructor of D is called" << std::endl;
  }
private:
  // initialization order is A, B, C. not C, B, A as declared at initialization list
  A a;
  B b;
  C c;
};


int main(){
  D d;
  return 0;
}
