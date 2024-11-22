#include <stdio.h>
#include <stdlib.h>
#include "empfunction.h"

int main()
{
    employee emp[SIZE]= {0};
    int size=0,option=0;
    char ch;
    switchoption(option);
    while(1)
    {
        ch=getch();
        if(ch==EXTENDCHAR)
        {
            ch=getch();
            if(ch==ARROW)
            {
                ch=getch();
                if(ch==DOWN)
                {
                    option=(option+1)%NUMOFLIST;
                }
                else if(ch==UP)
                {
                    option=(((option-1)%NUMOFLIST)+NUMOFLIST)%NUMOFLIST;
                }
                else if(ch==HOME)
                {
                    option=0;
                }
                else if(ch==END)
                {
                    option=4;
                }
                switchoption(option);
            }
        }
        else if(ch==BACK)
        {
            system("clear");
            switchoption(option);
        }
        else if(ch==ENTER)
        {
            char validsize;
            if(option==NEW)
            {
                validsize=1;
                do{
                    if(size==SIZE)
                    {
                        system("clear");
                        printf("The storage space is full,You can not add employee\n");
                        validsize=0;
                    }
                    else
                    {
                        system("clear");
                        enterNewEmployee(emp,size);
                        size++;
                        printf("Do you want enter another employee Yes(y) or No(n)?\n");
                        char isenter=1;
                        while(isenter)
                        {
                            ch=getch();
                            if(ch==NO)
                            {
                                system("clear");
                                switchoption(option);
                                isenter=0;
                            }
                            else if(ch==YES)
                                isenter=0;
                        }
                    }
                }while(ch==YES&&validsize);
            }
            else if(option==DISPLAY)
            {
                system("clear");
                if(size==0)
                    printf("No employee added\n");
                else
                    displayEmployee(emp,size);
            }
            else if(option==DELETE)
            {
                validsize=1;
                do{
                    if(size==0)
                    {
                        system("clear");
                        printf("No employee added\n");
                        validsize=0;
                    }
                    else
                    {
                        system("clear");
                        displayIdEmployee(emp,size);
                        deletEmployee(emp,size);
                        size--;
                        printf("Do you want delet another employee Yes(y) or No(n)?\n");
                        char isenter=1;
                        while(isenter)
                        {
                            ch=getch();
                            if(ch==NO)
                            {
                                system("clear");
                                switchoption(option);
                                isenter=0;
                            }
                            else if(ch==YES)
                                isenter=0;
                        }
                    }
                }while(ch==YES && validsize);
            }
            else if(option==MODIFIE)
            {
                 validsize=1;
                 do{
                    if(size==0)
                    {
                        system("clear");
                        printf("No employee added\n");
                        validsize=0;
                    }
                    else
                    {
                        system("clear");
                        displayIdEmployee(emp,size);
                        modifieEmployee(emp,size);
                        printf("Do you want modifie another employee Yes(y) or No(n)?\n");
                        char isenter=1;
                        while(isenter)
                        {
                            ch=getch();
                            if(ch==NO)
                            {
                                system("clear");
                                switchoption(option);
                                isenter=0;
                            }
                            else if(ch==YES)
                                isenter=0;
                        }
                    }
                }while(ch==YES && validsize);
            }
            else
            {
                system("clear");
                printf("exit\n");
                return 0;
            }
        }
    }
}
