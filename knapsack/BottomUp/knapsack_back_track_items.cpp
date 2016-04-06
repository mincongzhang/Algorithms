#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html

typedef std::vector< std::vector<int> >  BestValueMap;
typedef std::vector< std::vector<bool> > TakenMap;
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

void printBestValueMap(const BestValueMap & map){
	for(BestValueMap::const_iterator i=map.begin(); i!=map.end();++i){
		for(WeightMap::const_iterator w=i->begin(); w!=i->end();++w){
			std::cout<<*w<<"  ";
		}	
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void printTakenMap(const TakenMap & map){
	for(TakenMap::const_iterator i=map.begin(); i!=map.end();++i){
		for(std::vector<bool>::const_iterator t=i->begin(); t!=i->end();++t){
			std::cout<<*t<<"  ";
		}	
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void backTrackTakenMap(TakenMap & map,std::vector<Item> & items,int available_weight){
	printTakenMap(map);

	int weight_track = available_weight;
	for(int i(items.size()); i>0;--i){
		if(map[i][weight_track]){
			std::cout<<"item taken: value["<<items[i-1].getValue()<<"] weight["<<items[i-1].getWeight()<<"]"<<std::endl;
			weight_track -= items[i-1].getWeight();
		}
	}

}

void knapsack(std::vector<Item> & items, int available_weight){

	std::cout << "item number: " << items.size() << std::endl;
	std::cout << "bag can carry weight: " << available_weight << std::endl;
	std::cout << std::endl;

	WeightMap weights(available_weight+1,0);
	BestValueMap best_value_map(items.size()+1,weights);

	std::vector<bool>  taken_weights_array(available_weight+1,false);
	TakenMap taken_map(items.size()+1,taken_weights_array);

	for (int i = 0; i < items.size(); ++i){           // for each item
		for (int j = 0; j <= available_weight; ++j){  // for each weight
			int weight_i = items[i].getWeight();
			int value_i  = items[i].getValue();

			// not enough weight in bag
			if (j - weight_i < 0){      
				best_value_map[i+1][j] = best_value_map[i][j];

				// enough weight
			} else {    
				int take_current_value = best_value_map[i][j - weight_i] + value_i;
				int not_take_current_value = best_value_map[i][j];

				if(take_current_value>not_take_current_value){
				   best_value_map[i+1][j] = take_current_value;
				   taken_map[i+1][j]      =	true;
				} else {
					best_value_map[i+1][j] = not_take_current_value;
				}
			}
			std::cout << "current item: ["<<i<<"] current available_weight: ["<<j<<"]"<<std::endl;
			printBestValueMap(best_value_map);
		}
	}
	std::cout << "highest value: " << best_value_map[items.size()][available_weight] << std::endl;

	backTrackTakenMap(taken_map,items,available_weight);
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
