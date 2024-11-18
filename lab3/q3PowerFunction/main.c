#include <stdio.h>
#include <stdlib.h>

long long calculatePower(long long , long long );

int main()
{
    long long base=0, power=0;
    printf("Enter base: ");
    scanf("%d",&base);
    printf("Enter power: ");
    scanf("%d",&power);
    printf("base ^ power = %d ",calculatePower(base,power));
    return 0;
}
long long calculatePower(long long base,long long power)
{
    if(power==0)return 1;
    if(power==1)return base;
    long long answer= calculatePower(base,power/2);
    answer*=answer;
    if(power%2!=0)
        answer*=base;
    return answer;
}
