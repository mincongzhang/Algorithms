#include <iostream>

using namespace std;

int main(){  
	const int size = 3;
	int S[size] = {1, 2, 3};    
	int total_sets = 1 << size;	//2^n

	for (int idx = 0; idx < total_sets; idx++){  
		int temp_idx = idx;  
		int element_id = 0;  
		cout<<"{";  
		while (temp_idx){  
			if (temp_idx & 1)	cout<<S[element_id];  
			temp_idx >>= 1;  
			++element_id;  
		}  
		cout<<"}"<<endl;  
	}  

	system("pause");
	return 0;  
}  