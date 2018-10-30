#include <iostream>
#include <chrono>
#include <iomanip>

class B{
public:
  enum{NUM=1000000};
  B(){
    tmp = 0;
    std::cout << "default constructor of B is called" << std::endl;
    for(int i = 0;i < NUM;i++){
      array[i] = i;
    }
  }
  B(const B & obj){
    tmp = 1;
    std::cout << "copy constructor of B is called" << std::endl;
    for(int i = 0;i < NUM;i++){
      array[i] = i;
    }
  }
  B &operator=(const B & tb){
    std::cout << "= operator of B is called" << std::endl;
    (*this).tmp = 2;
    for(int i = 0;i < NUM;i++){
      array[i] = i;
    }
    return (*this);
  }
  int GetTmp(){
    return tmp;
  }
private:
  int tmp;
  int array[NUM];
};

class A{
public:
  A(){
  }
  A(const B & tmp_b);
 
private:
  B b;
};

#ifndef MEMBER_INITIALIZE
A::A(const B & tmp_b){
  // default constructor of B is called
  std::cout <<"- " << b.GetTmp() << std::endl;
  // = operator of B is called
  b = tmp_b;
  std::cout <<"- " << b.GetTmp() << std::endl;
}
#endif

#ifdef MEMBER_INITIALIZE 
A::A(const B & tmp_b) : b(tmp_b){
  //copy constructor is called
}
#endif

int main(){
  B tmp_b;
  std::cout << "=====================" << std::endl;
  auto chrono_start = std::chrono::system_clock::now();
  A a(tmp_b);
  auto chrono_end = std::chrono::system_clock::now();
  std::cout << std::setprecision(10) << "Elapsed time(C++):" << std::chrono::duration_cast<std::chrono::microseconds>(chrono_end - chrono_start).count() << "[ms]" << std::endl;

  return 0;
}
