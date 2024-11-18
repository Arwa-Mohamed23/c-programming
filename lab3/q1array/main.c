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
    int row=0,col=0;
    printf("Enter number of row: ");
    scanf("%d",&row);
    if(row<=0 ||row>SIZE || SIZE%row!=0)
    {
        printf("number of row isn't valid");
    }
    else
    {
        col=SIZE/row;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                printf("%d ",arr[(col*i)+j]);
            }
            printf("\n");
        }
    }
    return 0;
}
