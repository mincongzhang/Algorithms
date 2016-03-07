#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html

const int N = 100, W = 100000;
std::vector<int> value(N,0), weight(N,0);
int high_value_map[N + 1][W + 1] = {};

void printHighValueMap(int n, int w){
  for (int i = 0; i <= n; ++i){
    for (int j = 0; j <= w; ++j){
      std::cout<<high_value_map[i][j]<<" ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void knapsack(int n, int w){

  std::cout << "item number: " << n << std::endl;
  std::cout << "bag can carry weight: " << w << std::endl;
  std::cout << std::endl;

  for (int i = 0; i < n; ++i){     // for each item
    for (int j = 0; j <= w; ++j){  // for each weight
      if (j - weight[i] < 0){      // not enough weight in bag
        high_value_map[i+1][j] = high_value_map[i][j];
      } else {                     // enough weight
        high_value_map[i+1][j] = std::max( high_value_map[i][j],
                              /*Give up*/
                              high_value_map[i][j - weight[i]] + value[i]
                              /*Take current item:-weight, +value*/
                              //high_value_map[i][j - weight[i]] is the best solution without weight[i], then add current value
                              );
      }
      std::cout << "current n: ["<<i<<"] current w: ["<<j<<"]"<<std::endl;
      printHighValueMap(n,w);
    }
  }
  std::cout << "highest value: " << high_value_map[n][w] << std::endl;
}


int main(){
  value[0] = 2;
  value[1] = 4;
  value[2] = 5;

  weight[0] = 4;
  weight[1] = 6;
  weight[2] = 7;

  std::cout<<"knapsack"<<std::endl;
  knapsack(3,10);
  //system("PAUSE");
}
