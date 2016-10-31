#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#define log(msg) do{std::cout<<msg<<std::endl;}while(0)

int getBalance(const std::string& word, int begin, int end, int mid){
  int balance=0;
  for(int i=begin;i<end;++i){
    balance += abs(i-mid)*(int(word[i]-'A')+1);
  }
  return balance;
}

void solveLine(const std::string& line){
  for(int i=0;i<line.size();++i){
    int left = getBalance(line,0,i,i);
    int right = getBalance(line,i+1,line.size(),i);
    if(left==right){
      log(line.substr(0,i)<<" "<<line[i]<<" "<<line.substr(i+1)<<" - "<<left);
      return;
    }
  }
  log(line<<" does not balance");
}

int main(int argc, const char* argv[]) {
  std::ifstream file(argv[1]);
  std::string line;
  while (getline(file, line)){
    solveLine(line);
  }
}
