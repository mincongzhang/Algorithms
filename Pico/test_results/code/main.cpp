#include "toolbox.h"

int main()
{
	//check files in current directory 
	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	hFind = FindFirstFile("./Wave*.csv", &FindData);
	if( hFind == INVALID_HANDLE_VALUE )
	{
		cout << "There is no file in current directory"<<endl;
		system("pause");
		return -1;
	}

	//get first file with .csv extension
	FMap freq_map;

	double maxfreq = getMaxFreqFromFile(FindData.cFileName);
	freq_map.insert(FMap::value_type(maxfreq,FindData.cFileName));

	//for each other file with .csv extension
	while (FindNextFile(hFind, &FindData)){
		maxfreq = getMaxFreqFromFile(FindData.cFileName);
		freq_map.insert(FMap::value_type(maxfreq,FindData.cFileName));
	}

	//Sort and write the results 
	writeResult(freq_map);

	system("pause");
	return 0;
}