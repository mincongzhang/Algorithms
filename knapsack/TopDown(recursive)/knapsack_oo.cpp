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
  int getWeight(){return m_weight;};
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

int KSrecursive(std::vector<Item> & items, BestValueMap & best_value_map, int item_i, int weight_i){
  std::cout<<"Item:["<<item_i<<"]  Weight:["<<weight_i<<"]"<<std::endl;

  if(weight_i < 0) return -10000000;
  if(item_i   < 0) return 0;
  if(best_value_map[item_i][weight_i]) return best_value_map[item_i][weight_i]; //greater than 0 means it has been calculated

  best_value_map[item_i][weight_i] = std::max(
                                         KSrecursive(items, best_value_map, item_i-1, weight_i-items[item_i].getWeight()) + items[item_i].getValue(),
                                         KSrecursive(items, best_value_map, item_i-1, weight_i)
                                         );

  std::cout<<"Item["<<item_i<<"] value:"<<items[item_i].getValue()<<std::endl;
  printHighValueMap(best_value_map);

  return best_value_map[item_i][weight_i];
}


int main(){
  //value | weight
  Item i1(2,4);
  Item i2(4,6);
  Item i3(5,7);

  std::vector<Item> items;
  items.push_back(i1);
  items.push_back(i2);
  items.push_back(i3);

  int available_weight = 10;
  WeightMap weights(available_weight+1,0);
  BestValueMap best_value_map(items.size(),weights);

  std::cout<<"KS"<<std::endl;
  int result = KSrecursive(items,best_value_map,items.size()-1,available_weight);
  std::cout<<"Best value :"<<result<<std::endl;
  //system("PAUSE");

}
