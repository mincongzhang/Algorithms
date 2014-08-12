#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>

#include <string>
#include <vector>
#include <complex>
#include <algorithm>
#include <valarray>
#include <windows.h>

using namespace std;

const double PI = 3.141592653589793238460;

typedef unsigned int uint;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

Complex cAbs(const Complex & num){
	Complex result(sqrt(num.real()*num.real()+num.imag()*num.imag()),0.0);
	return result;
}

void getWave(string filename,vector<double> & seconds,vector<Complex> & volts)
{
	//get csv file
	ifstream fin(filename);		

	//traverse each line
	string line;    
	while (getline(fin, line)) {
		istringstream sin(line);    
		vector<string> fields;    
		string field;

		while (getline(sin, field, ',')) {
			fields.push_back(field);    
		}
		if(fields[0]=="Seconds")  continue;	 //jump over the first line

		stringstream sec_s(fields[0]);
		stringstream vol_s(fields[1]);
		double sec_d; sec_s>>sec_d;
		double vol_d; vol_s>>vol_d;
		Complex vod_c(vol_d,0.0);

		seconds.push_back(sec_d);
		volts.push_back(vod_c);
	}

	cout<<filename<<":"<<endl;
}

inline uint myFloor(const uint data_length){
	/*
	get floor of the length with max power of 2
	e.g. length==5000; n==12; 2^n = 4096
	so that to avoid zero padding in FFT 
	*/
	uint n = 0;
	while(data_length>>n) n++;	n--;
	return uint(pow(2,n));
}

// Cooley�CTukey FFT (in-place)
void fft(CArray & x)
{
	const size_t N = x.size();
	if (N <= 1) return;

	// divide
	CArray even = x[std::slice(0, N/2, 2)];
	CArray  odd = x[std::slice(1, N/2, 2)];

	// conquer
	fft(even);
	fft(odd);

	// combine
	for (size_t k = 0; k < N/2; ++k)
	{
		Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
		x[k    ] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

double getMaxFreqPos(const vector<double> & seconds,const vector<Complex> & volts,uint N)
{
	//get volts in CArray
	Complex * volts_tmparray;
	volts_tmparray = new Complex [N];

	for(uint i=0;i<N;i++) volts_tmparray[i] = volts[i];	

	CArray freq(volts_tmparray, N);
	delete [] volts_tmparray;

	//FFT
	fft(freq);

	//get absolute value of frequency
	CArray abs_freq_tmp = freq.apply(cAbs);
	vector<double> abs_freq;
	abs_freq.reserve(N);

	//get position of max frequency 
	for(uint i=0;i<N;i++) abs_freq.push_back(abs_freq_tmp[i].real()); 
	int pos = int(max_element(abs_freq.begin(),abs_freq.end())-abs_freq.begin());
	std::cout<<"Max freq position:";
	std::cout<< pos <<" in "<<N<<endl;

	//get max frequency
	double max_t = seconds.at(N-1);
	double Fs    = (N-1)/max_t;
	double f_max = abs(double(pos) - double(N/2))*Fs/N;
	cout<<"max freq:";
	cout<<f_max<<endl;

	return f_max;
}

void readAllFile()
{
	cout<<"reading..."<<endl;

	ifstream inputFile;
	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	hFind = FindFirstFile("./*.csv", &FindData);
	cout << FindData.cFileName << endl;

	while (FindNextFile(hFind, &FindData))
	{
		cout << FindData.cFileName << endl;
	}

	inputFile.close();
}

int main()
{
	readAllFile();

	//initial Seconds Volts
	vector<double> seconds;
	vector<Complex> volts;
	seconds.reserve(20000);
	volts.reserve(20000);

	getWave("Wave000.csv",seconds,volts);

	uint N = myFloor(seconds.size());
	seconds.resize(N);
	volts.resize(N);

	/*get max freq*/
	double freq = getMaxFreqPos(seconds,volts,N);



	Sleep(100000);
	return 0;
}