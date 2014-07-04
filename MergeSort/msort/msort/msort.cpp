#include <iostream>
#include <windows.h>

using namespace std;

//#ֻ��Ƀɶ�֮�g�w��Ĺ���#%
void Merge(int a[], int b[], int low, int mid, int high)
{
    int k = low;
    int begin1 = low;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = high;
    while(k <= high )
    {
        if(begin1 > end1)
            b[k++] = a[begin2++];
        else if(begin2 > end2)
            b[k++] = a[begin1++];
        else
	{
	    if(a[begin1] <= a[begin2])
		b[k++] = a[begin1++];
	    else
		b[k++] = a[begin2++];
	}
    }
 
}
 
void MergePass(int a[], int b[], int seg, int size)
{
    int seg_start_ind = 0;
    while(seg_start_ind <= size - 2 * seg) //#size - 2 * seg����˼�ǝM��ɃɃɚw�������R��ֵ#%
    {
	Merge(a, b, seg_start_ind, seg_start_ind + seg - 1, seg_start_ind + seg * 2 - 1);
	seg_start_ind += 2 * seg;
    }
    //#���һ�������ÿɚw��Ĕ�������һ�΄t������ÿɚw��Ĕ���#%
    if(seg_start_ind + seg < size)
	Merge(a, b, seg_start_ind, seg_start_ind + seg - 1, size - 1);
    else
	for(int j = seg_start_ind; j < size; j++) //#���ֻʣ��һ�λ��߸��ٵĔ���#%
	    b[j] = a[j];
}
 
void MergeSort(int array[], int size)
{
    int* temp = new int[size];
    int seg = 1;
    while(seg < size)
    {
	MergePass(array, temp, seg, size);
	seg += seg;
	MergePass(temp, array, seg, size);
	seg += seg;
    }
    delete [] temp;
}
 
int main()
{
    int array[] = {3, 5, 3, 6, 4, 7, 5, 7, 4};
    MergeSort(array, sizeof(array) / sizeof(*array));
    //#ݔ��#%
    for(int i = 0; i < sizeof(array) / sizeof(*array); i++)
	cout << array[i] << ' ';
    cout << endl;

	Sleep(100000);
 
    return 0;
}