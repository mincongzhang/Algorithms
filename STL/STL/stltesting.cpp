#include <map>  
#include <string>  
#include <iostream>  
#include <windows.h>
using namespace std;  
int main()  
{  
    map<int, string> mapStudent;  
    mapStudent.insert(pair<int, string>(1, "student_one"));  
    mapStudent.insert(pair<int, string>(2, "student_two"));  
    mapStudent.insert(pair<int, string>(3, "student_three"));  
    map<int, string>::iterator iter;  
    iter = mapStudent.find(1);  
    if(iter != mapStudent.end())  
    {  
        cout<<"Find, the value is "<<iter->second<<endl;  
    }  
    else  
    {  
        cout<<"Do not Find"<<endl;  
    }  
    iter = mapStudent.find(6);  
    if(iter != mapStudent.end())  
    {  
        cout<<"Find, the value is "<<iter->second<<endl;  
    }  
    else  
    {  
        cout<<"Do not Find"<<endl;  
    }  

	int a = 1;

	int b = a<<1;
	cout<<a<<endl;
	cout<<b<<endl;

	int c = -a;
	printf("c = %d",c);

	Sleep(100000);
}  