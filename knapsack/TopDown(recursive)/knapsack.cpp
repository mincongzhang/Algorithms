#include <iostream>

//http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html

const int N = 100;
const int W = 100000;

int cost[N], weight[N];
int c[N + 1][W + 1];

int knapsack(int n, int w)
{
    if (w < 0) return -1e9;
    if (n == 0) return 0;
    if (c[n][w]) return c[n][w];

    return c[n][w] = std::max(
        knapsack(n-1, w-weight[n]) + cost[n],
        knapsack(n-1, w)
    );
}

int main(){
  cost[1]=2;
  cost[2]=4;
  cost[3]=5;
  weight[1]=4;
  weight[2]=6;
  weight[3]=7;
  int ks_result = knapsack(4,10);
  std::cout<<"Best value :"<<ks_result<<std::endl;
}
