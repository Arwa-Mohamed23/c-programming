#include <stdio.h>
#include <stdlib.h>

int main()
{

    int sum=0,number=0;
    do{
      printf("enter number: ");
      scanf(" %d",&number);
      sum+=(int)number;
      printf("sum: %d\n",sum);

    }while(sum<=100);
    return 0;
}
