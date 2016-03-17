#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>

void windowspause(){
  #ifdef WIN32
    system("PAUSE");
  #endif
}

void generatePrime(const int & range){
  std::cout<<"generatePrime:"<<std::endl;
  for(int i = 2; i<range; ++i){

    int count(0);
    for(int j = 1; j<=i; ++j){
      if(i%j == 0){ count++; }
    }

    if(count==2){
      std::cout<<i<<" ";
    }
  }

  std::cout<<std::endl;
}



void generatePrime2(const int & range){
  std::cout<<"generatePrime2:"<<std::endl;

  if(range < 2) return;
  std::cout<<2<<" ";

  for(int i = 3; i<range; ++i){
    bool prime = true;
    for(int j = 2; j < i; ++j){
      if(i%j==0){ prime = false; break; }
    }
    if(prime){
      std::cout<<i<<" ";
    }
  }

  std::cout<<std::endl;
}


int main(){
  int range;
  std::cout<<"Prime: input your range: "<<std::endl;
  std::cin>>range;

  std::cout<<"your range: "<<range<<std::endl;

  generatePrime(range);
  generatePrime2(range);


  windowspause();
}
