#ifdef WIN32
#include <windows>
#endif

#include <iostream>
#include <string>
#include <algorithm>

const int N = 100, W = 100000;
int value[N], weight[N];
int c[N + 1][W + 1];

void printc(int n, int w){
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= w; ++j){
		    std::cout<<c[i][j]<<" ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void knapsack(int n, int w){

	std::cout << "item number: " << n << std::endl;
	std::cout << "bag can carry weight: " << w << std::endl;
	std::cout << std::endl;

	memset(c, 0, sizeof(c));

	for (int i = 0; i < n; ++i){     // for each item
		for (int j = 0; j <= w; ++j){// for each weight
			if (j - weight[i] < 0){		// not enough weight in bag
				c[i+1][j] = c[i][j];
			} else {                    // enough weight
				c[i+1][j] = std::max( c[i][j], c[i][j - weight[i]] + value[i]);
			}
			std::cout << "current n: ["<< i<<"] current w: ["<<j<<"]"<<std::endl;
			printc(n,w);
		}
	}
	std::cout << "highest value: " << c[n][w] << std::endl;
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
	system("PAUSE");
}
