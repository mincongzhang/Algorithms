#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define log(msg) std::cout<<msg<<std::endl

void print_table(const std::vector<int> & table){
  log("Printing table:");
  for(std::vector<int>::const_iterator i=table.begin();i!=table.end();++i){
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

int stairs(const int & num){
  if(num <= 0) return 0;
  if(num == 1) return 1;
  if(num == 2) return 2;
  return stairs(num-1)+stairs(num-2);
}

int stairs_dp(const int & num){
  if(num <= 0) return 0;
  if(num == 1) return 1;
  if(num == 2) return 2;

  //dynamic programming
  std::vector<int> stairs_table(num+1,0);
  stairs_table[0]=0;
  stairs_table[1]=1;
  stairs_table[2]=2;

  for(int i(3);i<num+1;++i){
    stairs_table[i] = stairs_table[i-1] + stairs_table[i-2];
  }

  print_table(stairs_table);
  return stairs_table.back();
}

int main(){
  int num(0);
  log("stairs: input the stairs you wanna climb: ");
  std::cin>>num;

  int m = stairs(num);
  log("Recursive approach:           There are ["<<m<<"] ways to climb the stairs");

  int m_dp = stairs_dp(num);
  log("Dynamic Programming approach: There are ["<<m_dp<<"] ways to climb the stairs");

}
