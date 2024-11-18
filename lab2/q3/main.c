#include <stdio.h>
#include <stdlib.h>

int main()
{

   printf("1-windows\n2-linux\n3-macos\n");
    char choice=0;
    scanf(" %d",&choice);
    switch(choice){
       case 1:
         printf("windows\n");
         break;
       case 2:
         printf("linux\n");
         break;
       case 3:
         printf("macos\n");
         break;
       default:
         printf("wrong choice\n");
         break;
    }
    return 0;
}
