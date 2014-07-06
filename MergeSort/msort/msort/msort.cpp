#include <iostream>
#include <windows.h>
using namespace std;
 
 
void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high-low+1];
	int flag_array1half,b_idx,flag_array2half,k;
	flag_array1half=low;
	flag_array2half=mid+1;
	b_idx=0;
	
	// Merges the two array's into b[] until the first one is finish
	while((flag_array1half<=mid)&&(flag_array2half<=high))
	{
		if(a[flag_array1half]<=a[flag_array2half])
		{
			b[b_idx]=a[flag_array1half];
			flag_array1half++;
		}
		else
		{
			b[b_idx]=a[flag_array2half];
			flag_array2half++;
		}
		b_idx++;
	}
	// Completes the array filling in it the missing values
	if(flag_array1half>mid)
	{
		for(k=flag_array2half;k<=high;k++)
		{
			b[b_idx]=a[k];
			b_idx++;
		}
	}
	else
	{
		for(k=flag_array1half;k<=mid;k++)
		{
			b[b_idx]=a[k];
			b_idx++;
		}
	}
	// Prints into the original array
	for(k=0;k<=high-low;k++) 
	{
		a[k+low]=b[k];
	}
	delete[] b;
}
 
void merge_sort(int a[], const int low, const int high)		// Recursive sort ...
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a, low,mid);
		merge_sort(a, mid+1,high);
		merge(a, low,mid,high);
	}
}
 
int main()
{
    int array[] = {3, 5, 3, 6, 4, 7, 5, 7, 4};
	int arraySize = 9;
	// a[] is the array to be sorted. ArraySize is the size of a[] ...
	merge_sort(array, 0, (arraySize-1) );        // would be more natural to use merge_sort(a, 0, arraySize ), so please try ;-)
 
    for(int i = 0; i < sizeof(array) / sizeof(*array); i++)
	cout << array[i] << ' ';
    cout << endl;

	Sleep(100000);
 
    return 0;
}