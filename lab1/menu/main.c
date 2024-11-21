#include <stdio.h>
#include <stdlib.h>
#include "empfunction.h"

int main()
{
    employee emp[SIZE]= {0};
    int size=0,option=0;
    char run=1,ch;
    switchoption(option);
    while(1)
    {
        ch=getch();
        if(ch==27)
        {
            ch=getch();
            if(ch==ARROW)
            {
                ch=getch();
                if(ch==DOWN)
                {
                    option=(option+1)%NUMOFLIST;
                    switchoption(option);
                }
                else if(ch==UP)
                {
                    option=(((option-1)%NUMOFLIST)+NUMOFLIST)%NUMOFLIST;
                    switchoption(option);
                }
            }
        }
        else if(ch==ENTER)
        {
            if(option==NEW)
            {
                do
                {
                    system("clear");
                    enterNewEmployee(emp,size);
                    size++;
                    ch=getch();
                    printf("Do you want enter another employee (yes or no)?");
                    ch=getche();
                    if(ch==NO)
                    {
                        system("clear");
                        switchoption(option);
                    }
                }
                while(ch==YES);
            }

            else if(option==DISPLAY)
            {
                system("clear");
                if(size==0)
                {
                    printf("No employee added\n");
                }
                else
                    displayEmployee(emp,size);
            }
            else if(option==DELETE)
            {
                system("clear");
                if(size==0)
                {
                    printf("No employee added\n");
                }
                else
                {
                    displayIdEmployee(emp,size);
                    printf("Enter the employee id you want to delete : ");
                    char id;
                    scanf("%c",&id);
                    if(id==BACK)
                    {
                        system("clear");
                        switchoption(option);
                    }
                    deletEmployee(emp,size,id);
                    size--;
                }
            }
            else if(option==MODIFIE)
             {
                 system("clear");
                 if(size==0)
                 {
                     printf("No employee added\n");
                 }
                 else
                 {
                     displayIdEmployee(emp,size);
                     printf("Enter the employee id you want to Modifie : ");

                 }
             }
            else
            {
                system("clear");
                printf("exit\n");
                return 0;
            }
        }

        else if(ch==BACK)
        {
            system("clear");
            switchoption(option);
        }
    }
   /* char ch;
    ch=getch();
    printf("%d\n",ch);
    ch=getch();
    printf("%d\n",ch);
    ch=getch();
    printf("%d\n",ch);
    ch=getch();
    printf("%d\n",ch);*/
    return 0;
}
