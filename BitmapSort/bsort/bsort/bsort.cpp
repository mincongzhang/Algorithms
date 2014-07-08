#include <iostream>
#include <windows.h>
using namespace std;
 
 
void bitmap_sort(int array[],int arrayMax)
{
	//in a very limitted condition
	bool *bitmap = new bool[arrayMax+1]();
	for(unsigned int i=0; i<7;i++)
	{
		bitmap[array[i]] = true;
	}

	int id = 0;
	for(unsigned int j=0;j<=arrayMax;j++)
	{
		if(bitmap[j])
		{
			array[id] = j;
			id++;
		}
	}

	delete[] bitmap;

}
 
int main()
{
    int array[] = {7,6,5,4,3,2,1};
	int arrayMax = 7;
	// a[] is the array to be sorted. ArraySize is the size of a[] ...
	bitmap_sort(array,arrayMax);  

    for(int i = 0; i < sizeof(array) / sizeof(*array); i++)
	cout << array[i] << ' ';
    cout << endl;

	Sleep(100000);
 
    return 0;
}