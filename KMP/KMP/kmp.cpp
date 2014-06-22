#include <windows.h>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

//特征向量：最长的首尾配串值k
int *findNext(string P){
int m = P.length();
assert( m > 0 );

int *next = new int[m];
assert( next != 0);
next[0] = -1; 

int k = 0;
for(int j=1;j<m;j++)
{
	if(P[k]==P[j]) k++;	
	else           k=0;
	next[j]=k;
}

return next;
}

int main(int argc, char *argv[])
{
    string t = "abcabcd";
    string p = "abcdabd";
    int *N;     
    cout << "the text to be matched is :" << t;
    
     
    N = findNext(p);
    cout << "the next array of pattern" << p << "is :" << endl;
    for (int i=0; i< p.length(); i++)
        cout << N[i] << " " ;
    cout << endl;
	Sleep(100000);

}
