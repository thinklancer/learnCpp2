#include <iostream>
#include <string>

/* (1) */
class C1{
public:
  class Warn{
    std::string content;
  public:
    Warn(const std::string &a):content(a){}
    void print() const{std::cout<<content<<std::endl;}
    ~Warn(){std::cout<<"destroyed"<<std::endl;} // (6) 
  };
  void memb(){throw(Warn("warning here"));}
};

/* (4) */
class C4{
  static int num;
public:
  void* operator new[](size_t);
  C4();
  static C4& reclaim();
};

class OutofMem{};

void sub1();
void sub4();
