#include "except.hpp"
using namespace std;

int main() try{
  sub1();
  return 0;
 } catch(...){
  cout<<"reach here"<<endl;  // (3) 
 }
