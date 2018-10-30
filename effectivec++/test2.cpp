#include <iostream>

class A{
public:
  A(){
    std::cout << "Default constructor of A is called" << std::endl;
  }
private:
  int tmp;
};

class B : A{
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
private:
};

class D{
public:
  D(){
    std::cout << "default constructor of D is called" << std::endl;
  }
private:
  C c;
  B b;
};

int main(){
  D d;
}
