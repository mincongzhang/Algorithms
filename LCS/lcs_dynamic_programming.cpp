#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define log(msg) std::cout<<msg<<std::endl

typedef std::vector< std::vector<int> > LCSMap;

void printLCS(const LCSMap & lcs_map){
  for(LCSMap::const_iterator lcs_it=lcs_map.begin();lcs_it!=lcs_map.end();++lcs_it){
    for(std::vector<int>::const_iterator it=lcs_it->begin();it!=lcs_it->end();++it){
      std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
  }
}

int LCS(std::string & a, std::string & b){
  std::vector<int> a_array(a.size(),0);
  LCSMap lcs_map(b.size(),a_array);

  log("LCS input strings: ["<<a<<"],["<<b<<"]");
  log("LCS map before:");
  printLCS(lcs_map);

  int a_size = a.size();
  int b_size = b.size();

  //lcs_map[b][a]
  for(int a_i(0); a_i<a_size; ++a_i){
    for(int b_i(0); b_i<b_size; ++b_i){
      if(a[a_i]==b[b_i]){
        //get left&top +1
        if(a_i-1<0 || b_i-1<0){continue;}
        lcs_map[b_i][a_i] = lcs_map[b_i-1][a_i-1]+1;
      }else{
        //get max(left,top)
        int left(0),top(0);
        if(a_i-1>0) left = lcs_map[b_i][a_i-1];
        if(b_i-1>0) top  = lcs_map[b_i-1][a_i];
        lcs_map[b_i][a_i]= std::max(left,top);
      }
    }
  }

  log("LCS map after:");
  printLCS(lcs_map);

  return lcs_map.back().back();
}


int main(){
  log("LCS:");

  //xyz
  std::string a="abxcaybzcabc";
  std::string b="dxefydefzdef";
  int lcs = LCS(a,b);
  log("Longest common subsequence: ["<<lcs<<"]");
}
