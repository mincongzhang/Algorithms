#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html

typedef std::vector< std::vector<int> > BestValueMap;
typedef std::vector<int> WeightMap;

class Item{
private:
	int m_value;
	int m_weight;
public:
	Item(int value,int weight):m_value(value),m_weight(weight){};
	int getValue(){return m_value;};
	int	getWeight(){return m_weight;};
};

void printHighValueMap(BestValueMap & map){
	for(BestValueMap::const_iterator i=map.begin(); i!=map.end();++i){
		for(WeightMap::const_iterator w=i->begin(); w!=i->end();++w){
			std::cout<<*w<<" ";
		}	
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void knapsack(std::vector<Item> & items, int available_weight){

	std::cout << "item number: " << items.size() << std::endl;
	std::cout << "bag can carry weight: " << available_weight << std::endl;
	std::cout << std::endl;

	WeightMap weights(available_weight+1,0);
	BestValueMap best_value_map(items.size()+1,weights);

	for (int i = 0; i < items.size(); ++i){           // for each item
		for (int j = 0; j <= available_weight; ++j){  // for each weight
			int weight_i = items[i].getWeight();
			int value_i  = items[i].getValue();

			// not enough weight in bag
			if (j - weight_i < 0){      
				best_value_map[i+1][j] = best_value_map[i][j];

				// enough weight
			} else {                     
				best_value_map[i+1][j] = std::max( 
					/*Give up*/
					best_value_map[i][j],

					/*Take current item:-weight, +value*/
					//best_value_map[i][j - weight[i]] is the best solution without weight[i], then add current value
					best_value_map[i][j - weight_i] + value_i
					);
			}
			std::cout << "current item: ["<<i<<"] current available_weight: ["<<j<<"]"<<std::endl;
			printHighValueMap(best_value_map);
		}
	}
	std::cout << "highest value: " << best_value_map[items.size()][available_weight] << std::endl;
}


int main(){
	Item i1(2,4);
	Item i2(4,6);
	Item i3(5,7);

	std::vector<Item> items;
	items.push_back(i1);
	items.push_back(i2);
	items.push_back(i3);

	std::cout<<"knapsack"<<std::endl;
	knapsack(items,10);
	system("PAUSE");
}
