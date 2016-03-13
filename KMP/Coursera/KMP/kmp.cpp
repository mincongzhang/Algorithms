#include <windows.h>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

//���������������β�䴮ֵk
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
    int i = 0;							// ģʽ���±����
    int j = 0;							// Ŀ����±����
    int pLen = P.length();             		// ģʽ�ĳ���
    int tLen = T.length();					// Ŀ��ĳ���

    if (tLen < pLen) 				    		// ���Ŀ���ģʽ�̣�ƥ���޷��ɹ�
        return (-1);

    while ( i < pLen  &&  j < tLen)  {  		// �����Ƚ϶�Ӧ�ַ�����ʼƥ��
       		if ( i == -1  ||  T[j] == P[i]) 
    			i++,  j++;
			//����ƶ�λ�� = ��ƥ����ַ���N[i] - ��Ӧ�Ĳ���ƥ��ֵ
			//�ȼ������´�N[i]��ʾ���Ǹ�����ʼ����
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
