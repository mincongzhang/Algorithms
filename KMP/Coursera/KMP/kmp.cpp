#include <windows.h>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

//特征向量：最长的首尾配串值k
int *findNext(string P){
int m = P.length();
assert( m > 2 );

int *next = new int[m];
assert( next != 0);
next[0] = -1;
next[1] =  0; 

int k = 0;
for(int j=2;j<m;j++)
{
	if(P[k]==P[j-1]) k++;
	else             k=0;
	next[j]=k;
}

return next;
}

int KMPStrMatching(string T, string P,  int *N) {
    int i = 0;							// 模式的下标变量
    int j = 0;							// 目标的下标变量
    int pLen = P.length();             		// 模式的长度
    int tLen = T.length();					// 目标的长度

    if (tLen < pLen) 				    		// 如果目标比模式短，匹配无法成功
        return (-1);

    while ( i < pLen  &&  j < tLen)  {  		// 反复比较对应字符来开始匹配
       		if ( i == -1  ||  T[j] == P[i]) 
    			i++,  j++;
			//向后移动位数 = 已匹配的字符数N[i] - 对应的部分匹配值
			//等价于重新从N[i]表示的那个数开始计数
    		else i = N[i];	

    }

    if ( i >= pLen)
    		return (j - pLen);
    else return (-1);
}

int main(int argc, char *argv[])
{
    //string t = "bbc abcdab abcdabcdabde";
	string t = "abcdabxabcdabd";
    string p = "abcdabd";
    int *N;     
    cout << "the text to be matched is :" << t;
    cout << endl;
     
    N = findNext(p);
    cout << "the next array of pattern " << p << " is :" << endl;
    for (int i=0; i< p.length(); i++)
        cout << N[i] << " " ;
    cout << endl;
         
    cout <<  KMPStrMatching(t, p, N) << endl;
	Sleep(100000);

}
