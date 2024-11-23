#include <stdio.h>
#include <stdlib.h>

void swapfunc1 (int *ptrx,int *ptry);
void swapfunc2 (int *ptrx,int *ptry);
void swapfunc3 (int **ptrx,int **ptry);
void swapfunc4 (int *ptrx,int *ptry);

int main()
{
    int x=5,y=10;
    printf("before swap: x= %d , y= %d\n",x,y);

    /*swapfunc1(&x,&y);
    printf("after swap with function 1: x= %d , y= %d\n",x,y);*/

    /*swapfunc2(&x,&y);
    printf("after swap with function 2: x= %d , y= %d\n",x,y);*/

    /*int *px=&x,*py=&y;
    swapfunc3(&px,&py);
    printf("after swap with function 3: x= %d , y= %d\n",*px,*py);*/

    /*swapfunc4(&x,&y);
    printf("after swap with function 4: x= %d , y= %d\n",x,y);*/

    return 0;
}

void swapfunc1 (int *ptrx,int *ptry)
{
    *ptrx=*ptrx+*ptry;
    *ptry=*ptrx-*ptry;
    *ptrx-=*ptry;
}

void swapfunc2 (int *ptrx,int *ptry)
{
    *ptrx=*ptrx*(*ptry);
    *ptry=*ptrx/(*ptry);
    *ptrx/=*ptry;
}

void swapfunc3 (int **ptrx,int **ptry)
{
    int *ptrtemp=NULL;
    ptrtemp=*ptrx;
    *ptrx=*ptry;
    *ptry=ptrtemp;
}

void swapfunc4 (int *ptrx,int *ptry)
{
    *ptrx=*ptrx^*ptry;
    *ptry=*ptrx^*ptry;
    *ptrx=*ptrx^*ptry;
}

