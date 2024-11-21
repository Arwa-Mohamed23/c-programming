#include <stdio.h>
#include <stdlib.h>
#include "implementfunction.h"
#define SIZE 100

int main()
{
    char dest[SIZE]={'a','r','w','a','\0'};
    char src[SIZE]="Mohammed";

    printf("length of %s string = %d\n",dest,stringLength(dest));

    printf("***********************************\n");

    printf("source string : %s\n",src);
    printf("destination string before concate : %s\n",dest);
    stringConcat(dest,src,SIZE);
    printf("destination after concate : %s\n",dest);

    printf("***********************************\n");

    printf("source string : %s\n",src);
    printf("destination before copy : %s\n",dest);
    stringCopy(dest,src,SIZE);
    printf("destination after copy : %s\n",dest);

    printf("***********************************\n");

    printf("compare between %s and %s : ",dest,src);
    stringCompare(dest,src);

    printf("***********************************\n");

    convertStringToUpper(dest);
    printf("string after convert to uppercase : %s\n",dest);

    printf("***********************************\n");

    convertStringToLower(dest);
    printf("string after convert to lowercase : %s\n",dest);
    return 0;
}
