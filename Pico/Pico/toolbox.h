#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <valarray>

#include <string>
#include <complex>
#include <map>
#include <algorithm>

#include <cstdlib>
#include <windows.h>

using namespace std;

typedef unsigned int uint;
typedef complex<double> Complex;
typedef valarray<Complex> CArray;
typedef multimap<double,string> FMap;

const double PI = 3.141592653589793238460;

double getMaxFreqFromFile(string);
void writeResult(const FMap &);