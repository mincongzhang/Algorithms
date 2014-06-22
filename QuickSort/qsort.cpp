#include <windows.h>
#include <stdio.h>

#define LENGTH  10


void swap(int a[], int i, int j)
{
 int temp = a[i];
 a[i] = a[j];
 a[j] = temp;
}

void qSort_getID(int array[], int left, int right)
{
 int i,j,k,last;
 if(left >= right)
  return;
 i = (left + right)/2;
 //swap(array,left, i);
 last = left;
 for(i = left+1; i<=right; i++)
 {
  if(array[i] < array[left])
   swap(array,++last, i);
 }
 swap(array,last,left);
 qSort_getID(array,left,last-1);
 qSort_getID(array,last+1, right);
}

void printarray(int a[],int length)
{
 int i;
 printf("Elements of the array is:");
 if(length <= 0)
  return;
 for(i = 0;i <length; i++)
  printf("%d ", a[i]);
}


int main(void)
{ int a[LENGTH] = {10,9,3,49,37,38,0,434,3,10};
 qsort(a, 0, LENGTH-1); 
 printarray(a,LENGTH);
 Sleep(10000);
 return 0;
}
