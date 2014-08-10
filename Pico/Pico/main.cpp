#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class _T1,class _T2>
struct my_pair
{
	_T1 first;
	_T2 second;

	//constructor 1
	my_pair():first(),second(){};

	//constructor 2
	my_pair(const _T1 & __a,const _T2 & __b):first(__a),second(__b){};

	//constructor 3
	template<class _U1,class _U2>
	my_pair(const my_pair<_U1,_U2> & __p):first(__p.first),second(__p.second){};

	//operator()
	my_pair<_T1,_T2> operator()(const _T1 &__a,const _T2 & __b){
		this->first = __a; this->second = __b; return *this;
	};
};

my_pair<vector<double>,vector<double>> get_wave(string filename)
{
	//get csv file
	ifstream fin(filename);		

	//initial Seconds Volts
	vector<double> seconds;
	vector<double> volts;
	seconds.reserve(20000);
	volts.reserve(20000);

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
		double vol_d;vol_s>>vol_d;

		seconds.push_back(sec_d);
		volts.push_back(vol_d);
		//cout <<"data accessed: "<<sec_d<< "," << vol_d << endl; 
	}

	my_pair<vector<double>,vector<double>> signals(seconds,volts);
	cout<<filename<<" get;"<<endl;
	return signals;
}

int main()
{
	my_pair<vector<double>,vector<double>> signals = get_wave("Wave000.csv");

	return 0;
}