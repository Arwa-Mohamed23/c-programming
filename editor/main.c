#include <stdio.h>
#include <stdlib.h>
#include "linefunction.h"

int main()
{
    char line[SIZE];
    int current=-1,tail=-1;
    char ch,clickInsert=0;
    while(1)
    {
        ch=getch();
        if(ch==EXTENDCHAR)
        {
            ch=getch();
            if(ch==ARROW)
            {
                ch=getch();
                if(ch==LEFT&&current>0)
                {
                    current--;
                    displayLine(current,line);
                }
                else if(ch==RIGHT&&current<tail)
                {
                    current++;
                    displayLine(current,line);
                }
                else if(ch==UP&&current>0)
                {
                    current=0;
                    displayLine(current,line);
                }
                else if(ch==DOWN)
                {
                    current=tail;
                    displayLine(current,line);
                }
                else if(ch==DELETE)
                {
                    ch=getch();
                    if(ch==INSDEL)
                    {
                        if(tail>current)
                        {
                            deleteChar(current+1,line);
                            tail--;
                            displayLine(current,line);
                        }

                    }
                }
                else if(ch==INSERT)
                {
                    ch=getch();
                    if(ch==INSDEL)
                    {
                        clickInsert = (clickInsert == 1 ? 0 : 1);
                    }
                }
            }

        }
        else if((ch>='a'&&ch<='z')||
                (ch>='A'&&ch<='Z')||
                (ch>='0'&&ch<='9')||ch==SPACE)
        {
          if(clickInsert){
             line[current]=ch;
          }
          else if(tail<(SIZE-2)){
            current++,tail++;
            enterChar(current,tail,line,ch);
          }
          displayLine(current,line);
        }
        else if(ch==BACK)
        {
            deleteChar(current,line);
            tail--;
            current==0?current=0:current--;
            if(tail==-1)current=-1;
            displayLine(current,line);
        }

    }
    return 0;
}
