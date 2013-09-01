#include "except.hpp"
using namespace std;
void sub1(){
  C1 c;
  try{
    c.memb();
  } catch(C1::Warn a){
    a.print();
    throw;
  }
}

void* C4::operator new[](size_t n){
  cout << "create with new "<<endl;
  return ::new C4[n];  // it create twice [@1]
}

int C4::num = 0;

C4::C4(){
  num++;
  cout<<num<<endl;
  if (num>10){
    throw(C1::Warn("faile to allocate"));
  }
}

C4& C4::reclaim(){
  cout<<"recovered"<<endl;
}

void sub4(){
  C4 *p;
  try{
    while(1){
      p = new C4[2]; // create twice [ref: @1]
    }
  } catch(C1::Warn a){
    a.print();
    C4::reclaim();
  }
}
