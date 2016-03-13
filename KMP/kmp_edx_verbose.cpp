#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>


void printPatterni(char * pattern,int pattern_i){
  int pattern_len = (int)std::strlen(pattern);
  std::cout<<"pattern_i : [ ";
  for(int i(0);i<pattern_len;++i){
    if(i == pattern_i)   std::cout<<"* ";
    else                 std::cout<<"  ";
  }
  std::cout<<"]\n"<<std::endl;
}

void printPattern(char * pattern){
  int pattern_len = (int)std::strlen(pattern);
  std::cout<<"pattern   : [ ";
  for(int i(0);i<pattern_len;++i) std::cout<<pattern[i]<<" ";
  std::cout<<"]"<<std::endl;
}

void printNext(char * pattern,int * next){
  int len = (int)std::strlen(pattern);
  std::cout<<"next      : [";
  for(int i(0);i<len;++i) std::cout<<next[i]<<" ";
  std::cout<<"]"<<std::endl;
}

void printPatternAndNext(char * pattern, int * next){
  printPattern(pattern);
  printNext(pattern,next);
}

int * buildNext( char * pattern ){
  size_t pattern_len = std::strlen(pattern), pattern_i = 0;
  int * N = new int[pattern_len];     //next[]
  int t = N[0] = -1;                  //pattern[-1] wildcard

  /*
    Should satisfy:
    Next[i+1] <= Next[i]+1
    Next[i+1] == Next[i]+1, iff P[i] == P[Next[i]], P[Next[Next[i]]] ... P[N[0]]
  */

  while (pattern_i < pattern_len - 1 ){ //Recurrent
    std::cout<<"At pattern ["<<pattern_i<<"]"<<std::endl;
    if( t < 0 || pattern[pattern_i] == pattern[t] ){ //match
      if(t>=0){
        std::cout<<"*MATCH"<<std::endl;
        std::cout<<"*pattern ["<<pattern_i<<"] == pattern ["<<t<<"]"<<std::endl;
      } else {
        std::cout<<"*t start from beginning"<<std::endl;
        std::cout<<"*t = N["<<0<<"] : ["<<N[0]<<"]"<<std::endl;
      }

      t++;  pattern_i++;
      N[ pattern_i ] = t;
      std::cout<<"*N["<<pattern_i<<"]     = ["<<t<<"]"<<std::endl;

      //N[++pattern_i] = ++t;

    } else { //mismatch
      std::cout<<"*NOT MATCH"<<std::endl;
      std::cout<<"*t = N["<<t<<"] : ["<<N[t]<<"]"<<std::endl;
      t = N[t];
    }

    printPatternAndNext(pattern,N);
    printPatterni(pattern,pattern_i-1);
  }

  return N;
}

int match(char * text, char * pattern){
  int * next = buildNext(pattern);
  int text_len = (int)std::strlen(text), text_i = 0;
  int pattern_len = (int)std::strlen(pattern), pattern_i = 0;

  std::cout<<"text len:"<<text_len<<std::endl;
  std::cout<<"text:"<<text<<std::endl;
  std::cout<<"pattern len:"<<pattern_len<<std::endl;
  printPatternAndNext(pattern,next);

  while( pattern_i < pattern_len && text_i < text_len ){
    if( pattern_i < 0 || text[text_i] == pattern[pattern_i] ){ //match OR pattern_i<0 means get next[0] == -1
      text_i++; pattern_i++;
    } else {//pattern move right, text no backout
      pattern_i = next[pattern_i];
    }
  }

  delete [] next;

  return text_i - pattern_i;
}

int main(){
  std::cout<<"KMP:"<<std::endl;

  int m = match("abchichinllabbba","chinchilla");
  //int m = match("abchichinllabbba","abcabcabcabcabcacdacdacdacdaweaweaweawe");

  std::cout<<"Match point in text: "<<m<<std::endl;

  // system("PAUSE");
}
