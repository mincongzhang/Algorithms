#include <windows.h>
#include <stdio.h>

#define LENGTH  11

void swap(double array[], int i, int j)
{
 double temp = array[i];
 array[i] = array[j];
 array[j] = temp;
}

void qsort_getid(double array[],double id_array[], int left_id, int right_id)
{
 int i,j,k,flag;
 if(left_id >= right_id)
  return;
 flag = left_id;
 for(i = left_id+1; i<=right_id; i++)
 {
  if(array[left_id]>array[i])
   {
   flag = flag+1;
   swap(array,flag, i);
   swap(id_array,flag, i);
   }
 }
 swap(array,flag,left_id);
 swap(id_array,flag,left_id);
 qsort_getid(array,id_array,left_id,flag-1);
 qsort_getid(array,id_array,flag+1,right_id);
}

void printarray(double array[],int length)
{
 int i;
 printf("\n Elements of the array is: ");
 if(length <= 0)
  return;
 for(i = 0;i <length; i++)
  printf("%.0f ", array[i]);
}

int main(void)
{ 
 double array[LENGTH] =    {10,9,3,49,337,38,30,434,3,6,1};
 double id_array[LENGTH] = {0,1,2,3,4,5,6,7,8,9,10};
 
 qsort_getid(array,id_array, 0, LENGTH-1); 
 printarray(array,LENGTH);
 printarray(id_array,LENGTH);
 Sleep(100000);
 return 0;
}
