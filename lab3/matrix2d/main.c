#include <stdio.h>
#include <stdlib.h>

#define ROW 1
#define COL 2
int main()
{
    float arr[ROW][COL];
    printf("Enter 2D array of size %dx%d:\n",ROW,COL);
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            scanf("%f",&arr[i][j]);
            //printf("\nascii=%d\n",(char)arr[i][j]);
        }
    }
    float sumOfRow,avrgOfCol;
    for(int i=0; i<ROW; i++)
    {
        sumOfRow=0;
        for(int j=0; j<COL; j++)
        {
            sumOfRow+=arr[i][j];
        }
        printf("sum of row %d = %0.2f\n",i+1,sumOfRow);
    }

    for(int i=0; i<COL; i++)
    {
        avrgOfCol=0;
        for(int j=0; j<ROW; j++)
        {
            avrgOfCol+=arr[j][i];
        }
        printf("average of column %d = %0.2f\n",i+1,avrgOfCol/ROW);
    }
    return 0;
}
