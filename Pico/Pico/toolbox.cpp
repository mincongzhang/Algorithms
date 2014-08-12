#include "toolbox.h"

Complex myAbs(const Complex & num){
	Complex result(sqrt(num.real()*num.real()+num.imag()*num.imag()),0.0);
	return result;
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

void myFft(CArray & x){
	const size_t N = x.size();
	if (N <= 1) return;

	// divide
	CArray even = x[std::slice(0, N/2, 2)];
	CArray  odd = x[std::slice(1, N/2, 2)];

	// conquer
	myFft(even);
	myFft(odd);

	// combine
	for (size_t k = 0; k < N/2; ++k)
	{
		Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
		x[k    ] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

bool readData(string filename,vector<double> & seconds,vector<Complex> & volts){
	//get csv file
	ifstream input_file(filename);

	//get data size	and reserve spaces
	input_file.seekg(0, std::ios::end);
	int estimate_filesize = (int)ceil(input_file.tellg()/25.0);
	input_file.seekg(0);

	if(estimate_filesize==0){
		cout<<"Error: File is empty. Frequency is saved as 0"<<endl;
		return false;
	}

	seconds.reserve(estimate_filesize);
	volts.reserve(estimate_filesize);

	//traverse each line
	string line;    
	while (getline(input_file, line)) {
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
	return true;
}

double getFreq(const vector<double> & seconds,const vector<Complex> & volts,uint N){
	//get volts in CArray
	Complex * volts_tmparray;
	volts_tmparray = new Complex [N];

	for(uint i=0;i<N;i++) volts_tmparray[i] = volts[i];	

	CArray freq(volts_tmparray, N);
	delete [] volts_tmparray;

	//FFT
	myFft(freq);

	//get absolute value of frequency
	CArray abs_freq_tmp = freq.apply(myAbs);

	//get position of max frequency
	vector<double> abs_freq;
	abs_freq.reserve(N);
	for(uint i=0;i<N;i++){ 
		abs_freq.push_back(abs_freq_tmp[i].real()); 
	}
	int pos = int(max_element(abs_freq.begin(),abs_freq.end())-abs_freq.begin());

	//get max frequency
	double max_t = seconds.at(N-1);
	double Fs    = (N-1)/max_t;
	double f_max = abs(double(pos) - double(N/2))*Fs/N;

	cout<<"frequency:";	cout<<f_max<<endl;
	return f_max;
}

double getMaxFreqFromFile(string filename){
	//initial Seconds Volts
	vector<double> seconds;
	vector<Complex> volts;

	//get seconds and volts
	if(!readData(filename,seconds,volts) || volts.size()==0) 
		return 0.0;

	//resize
	uint N = myFloor(seconds.size());
	seconds.resize(N);
	volts.resize(N);

	//get max frequency
	double freq = getFreq(seconds,volts,N);

	return freq;
}

void writeResult(const FMap & freq_map){
	// open file
	ofstream result_file;
	result_file.open("results.csv");

	//write file header
	if (result_file.is_open()){
		result_file<<"Filename,Frequency"<<endl;
		for(FMap::const_iterator i=freq_map.begin();i!=freq_map.end();i++){
			result_file<<i->second<<","<<i->first<<endl;
		}
	}
	result_file.close();

	cout<<"Results is saved in results.csv"<<endl;
}