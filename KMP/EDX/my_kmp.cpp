#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

#define log(msg) do{ std::cout<<msg<<std::endl; }while(0)

void printNext(const std::vector<int> &next){
  int len = next.size();
  std::cout<<"next      : [";
  for(int i(0);i<len;++i){
    if(next[i]<0)
      std::cout<<next[i]<<" ";
    else
      std::cout<<" "<<next[i]<<" ";
  }
  std::cout<<" ]"<<std::endl;
}


void buildNext(const std::string & pattern,std::vector<int> & next){
  if( next.size() != pattern.size() ){
    log("ERROR:  next.size() != pattern.szie()");
    return;
  }

  int pattern_len = pattern.size();
  int pattern_i = 0;
  int t = -1;
  next[0] = -1;

  while(pattern_i < pattern_len - 1){
    if( t < 0 || pattern[pattern_i] == pattern[t] ){
      t++; pattern_i++;
      if(pattern[pattern_i]==pattern[t]) next[pattern_i]=next[t];
      else                               next[pattern_i]=t;
    } else {
      t = next[t];
    }
  }
}

int match(const std::string & text, const std::string & pattern){
  if(pattern.empty() || text.empty()) return -1;

  std::vector<int> next(pattern.size(),0);

  buildNext(pattern,next);
  printNext(next);

  int text_len = text.size();
  int pattern_len = pattern.size();
  int text_i(0),pattern_i(0);

  while(pattern_i<pattern_len && text_i<text_len){
    if(pattern_i<0 || text[text_i]==pattern[pattern_i]){
      text_i++;
      pattern_i++;
    } else {
      pattern_i = next[pattern_i];
    }
  }

  return (text_i - pattern_i);
}


int main(){
  log("KMP");
  std::string pattern("chinchichi");
  std::string text("xxxchinchichicccc");

  int m = match(text,pattern);
  log("match point:"<<m);

}
