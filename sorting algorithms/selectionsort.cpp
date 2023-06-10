// This is the code of selectionsort in C++
#include <iostream>
using namespace std;
inline void swap(int *x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionsort(int arr[],int n)
{
    int min;
    for(int i = 0; i<n-1; i++)
    {
        min = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
int main()
{
    int arr[5] = {4,3,1,7,5};
    selectionsort(arr,5);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}