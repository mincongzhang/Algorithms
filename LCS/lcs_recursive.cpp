#include <iostream>
#include <string>

#define log(msg) do{std::cout<<msg<<std::endl;}while(0)
std::string LCS(std::string & a, int a_end, std::string & b, int b_end){
  if(a_end<0 || b_end<0) return "";

  if(a[a_end] == b[b_end]){
    return LCS(a,a_end-1,b,b_end-1) + a[a_end];
  } else {
    std::string a_lcs = LCS(a,a_end,b,b_end-1);
    std::string b_lcs = LCS(a,a_end-1,b,b_end);
    return (a_lcs.size()>b_lcs.size())? a_lcs : b_lcs;
  }
}


int main(){
  log("LCS:");

  //xyz
  std::string a="abxcaybzcabc";
  std::string b="dxefydefzdef";
  std::string lcs = LCS(a,a.size()-1,b,b.size()-1);
  log(lcs);
}
