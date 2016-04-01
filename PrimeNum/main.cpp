#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <cmath>

void windowspause(){
  #ifdef WIN32
    system("PAUSE");
  #endif
}

/*
Input: an integer n > 1

Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.

for i = 2, 3, 4, ..., not exceeding sqrt(n)
 if A[i] is true:
   for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n
     A[j] := false

Output: all i such that A[i] is true.
*/

void generateSievePrime(const int & range){
  std::cout<<"generateSievePrime:"<<std::endl;

  std::vector<bool> integers(range,true);
  for(int i(2); i<std::sqrt(range); ++i){
    if(integers[i]==true){
      for(int j(i*i); j<range; j+=i){
        integers[j]=false;
      }
    }
  }

  for(int i(2); i<integers.size();++i){
    if(integers[i]){
      std::cout<<i<<" ";
    }
  }
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
  generateSievePrime(range);

  windowspause();
}
