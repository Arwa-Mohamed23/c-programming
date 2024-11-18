#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
int main()
{
    int arr[SIZE];
    printf("Enter array of %d elements: ",SIZE);
    for(int i=0; i<SIZE; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0], min=arr[0];
    for(int i=0; i<SIZE; i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    printf("maximum value = %d\nminimum value = %d",max,min);
    return 0;
}
