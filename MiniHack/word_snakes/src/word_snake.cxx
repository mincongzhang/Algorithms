#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

#define log(msg) do{ std::cout<<msg<<std::endl;}while(0)
std::ifstream infile("long.txt");
//std::ifstream infile("medium.txt");
const int DICT_SIZE = 26;

int main(){
  std::string line;
  while (std::getline(infile, line)){
    std::vector<int> dict(DICT_SIZE,0);

    std::vector<std::string> words;
    boost::split(words,line,boost::is_any_of(","));
    for(std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it){
      std::string word(*it);
      dict[int(word[0]-'a')]++;
      dict[int(word[word.size()-1]-'a')]--;
    }

  int count(0);
  for(int i(0); i<DICT_SIZE; ++i){
    if(dict[i] != 0){
      count++;
    }
  }

  if(count==2 || count==0){ log(1); }
  else { log(0); }

  }

}
