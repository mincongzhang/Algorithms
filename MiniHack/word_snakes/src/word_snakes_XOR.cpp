#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

#define log(msg) do{ std::cout<<msg<<std::endl;}while(0)
std::ifstream infile("short.txt");
//std::ifstream infile("medium.txt");
const int ALPHABET_SIZE = 26;

int main(){
  std::string line;
  while (std::getline(infile, line)){
    std::vector<int> dict(ALPHABET_SIZE,0);

    int prefix_count(0),suffix_count(0);
    std::vector<std::string> words;
    boost::split(words,line,boost::is_any_of(","));
    for(std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it){
      std::string word(*it);
      prefix_count ^= int(word[0]-'a');
      suffix_count ^= int(word[word.size()-1]-'a');
    }

    //NOTE: this approach is wrong.....

    //2 same numbers will eliminate the bits in XOR
    //If we only have a valid letter(0-26) in prefix/suffix
    //that means our words can form a snake
    if( (prefix_count>=0 && prefix_count<=ALPHABET_SIZE) &&
        (suffix_count>=0 && suffix_count<=ALPHABET_SIZE) ){
      log(1);
    } else {
      log(0);
    }
  }
}

