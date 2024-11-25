#include <stdio.h>
#include <stdlib.h>
#include "linefunction.h"

void displayLine(int current,char line[]){
  system("clear");
  int i=0;
  while(line[i]!=TERMINATOR){
     if(i==current){
         setTextColor(stdout,TC_BLUE);
         printf("%c",line[i]);
         setTextColor(stdout,TC_WHITE);
     }else{
       printf("%c",line[i]);
      }
      i++;
  }
}

void enterChar(int current,int tail,char line[],char ch){
  line[tail+1]=TERMINATOR;
  int i=0;
  for(int i=tail;i>current;i--){
     line[i]=line[i-1];
  }
  line[current]=ch;
}


void deleteChar(int current,char line[])
{
    while(line[current]!=TERMINATOR)
    {
        line[current]=line[current+1];
        current++;
    }

}



