#include <stdio.h>
#include <stdlib.h>

int main() {
int x=200;
float y=5.5;
char z='a';
printf("integer= %d\nfloate= %f\nchar= %c\n",x,y,z);

printf("enter char: ");
scanf(" %c", &z);
printf("char %c has ascii code %d\n",z,z);

printf("hexa representation of integer %d is %x\n",x,x);
printf("octal representation of integer %d is %o\n",x,x);
return 0;
}
