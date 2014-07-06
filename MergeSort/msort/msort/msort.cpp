#include <iostream>
#include <windows.h>
using namespace std;
 
 
void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high-low+1];
	int flag_at_low,flag_at_b,flag_at_mid,k;
	flag_at_low=low;
	flag_at_b=0;
	flag_at_mid=mid+1;
	// Merges the two array's into b[] until the first one is finish
	while((flag_at_low<=mid)&&(flag_at_mid<=high))
	{
		if(a[flag_at_low]<=a[flag_at_mid])
		{
			b[flag_at_b]=a[flag_at_low];
			flag_at_low++;
		}
		else
		{
			b[flag_at_b]=a[flag_at_mid];
			flag_at_mid++;
		}
		flag_at_b++;
	}
	// Completes the array filling in it the missing values
	if(flag_at_low>mid)
	{
		for(k=flag_at_mid;k<=high;k++)
		{
			b[flag_at_b]=a[k];
			flag_at_b++;
		}
	}
	else
	{
		for(k=flag_at_low;k<=mid;k++)
		{
			b[flag_at_b]=a[k];
			flag_at_b++;
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