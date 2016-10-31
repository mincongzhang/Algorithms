#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;typedef string C;typedef int I;
#define L(m) do{cout<<m<<endl;}while(0)
I B(C w,I s,I e,I m){I r=0;for(I i=s;i<e;++i){r+=abs(i-m)*(I(w[i]-'@'));}return r;}
void S(C w){for(I i=0;i<w.size();++i){I l=B(w,0,i,i);I r=B(w,i+1,w.size(),i);if(l==r){L(w.substr(0,i)<<" "<<w[i]<<" "<<w.substr(i+1)<<" - "<<l);return;}}L(w<<" does not balance");}
main(I c,char** v){ifstream f(v[1]);C w;while(getline(f,w)){S(w);}}
