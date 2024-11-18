#include <stdio.h>
#include <stdlib.h>

int main()
{
     //q4
    for(int i=1;i<=10;i++){
      for(int j=1;j<=10;j++){
        printf("%d * %d = %d\n",i,j,(i*j));
      }
      printf("*****************\n");
    }
    printf("multiplication table in descending order\n\n");
     //q5
    for(int i=10;i>=1;i--){
      for(int j=1;j<=10;j++){
        printf("%d * %d = %d\n",i,j,(i*j));
      }
      printf("*****************\n");
    }
    return 0;
}
