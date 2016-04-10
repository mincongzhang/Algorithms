#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define log(msg) do{ std::cout<<msg<<std::endl;}while(0)

/*
Examples: num_set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.
*/


typedef std::vector<int> SumArray;
typedef std::vector<SumArray> SumMap;
typedef SumMap TakenMap;

void printMap(const SumMap & map){
	for(SumMap::const_iterator i=map.begin(); i!=map.end();++i){
		for(SumArray::const_iterator j=i->begin(); j!=i->end();++j){
			std::cout<<*j<<" ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}


int subsum(const std::vector<int> & num_set,SumMap & sum_map, TakenMap & taken_map, const int & n, const int & sum){
	for(int i(0); i<n; ++i){
		for(int s(sum); s>=0; --s){
			if(s-num_set[i] >= 0){
				sum_map[0][s] = std::max(sum_map[0][s-num_set[i]]+num_set[i],sum_map[0][s]);
			} else {
				sum_map[0][s] = sum_map[0][s];
			}
		}
		printMap(sum_map);
	}

	return 0;
}

int main(){

	int sum = 9;
	std::vector<int> num_set;
	num_set.push_back(3);
	num_set.push_back(34);
	num_set.push_back(4);
	num_set.push_back(12);
	num_set.push_back(5);
	num_set.push_back(2);

	SumArray sum_array(sum+1,0);
	SumMap sum_map(num_set.size()+1,sum_array);
	TakenMap taken_map(sum_map);

	int result = subsum(num_set,sum_map,taken_map,num_set.size(),sum);
	std::cout<<"result:"<<result<<std::endl;
	system("PAUSE");
}
