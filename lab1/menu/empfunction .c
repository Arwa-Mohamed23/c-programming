#include <stdio.h>
#include <stdlib.h>
#include "empfunction.h"

char uniqcode[101]= {0};

void enterNewEmployee (employee e[],int index)
{
    char checkvalid;
    char isvalide=1;
    while(isvalide)
    {
        printf("Enter employee code: ");
        if(scanf("%d%c",&e[index].code, &checkvalid)!=2||checkvalid!='\n')
        {
            printf("employee code not valide\n");
            while (getchar() != '\n');  // Clear invalid input from buffer
        }
        else if(e[index].code<0||e[index].code>100)
            printf("employee code must be between 0 and 100\n");
        else if(uniqcode[e[index].code]==1)
            printf("employee code must be uniqe\n");
        else
        {
            uniqcode[e[index].code]=1;
            isvalide=0;
        }
    }
    printf("Enter employee name: ");
    scanf("%s",e[index].name);
    isvalide=1;
    while(isvalide)
    {
        printf("Enter employee salary: ");
        if(scanf("%d%c",&e[index].salary, &checkvalid)!=2||checkvalid!='\n')
        {
            printf("employee salary not valide\n");
            while (getchar() != '\n');
        }
        else if(e[index].salary<0)
            printf("employee salary must be positive\n");
        else isvalide=0;
    }
}

void displayEmployee (employee e[],int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Employee code: %d\n",e[i].code);
        printf("Employee name: %s\n",e[i].name);
        printf("Employee salary: %d\n",e[i].salary);
        printf("***************************************\n");
    }
}

void displayIdEmployee(employee e[],int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Code Employee %d : %d\n",i+1,e[i].code);
    }
}

void deletEmployee(employee e[],int size)
{
    int id;
    char checkvalid;
    char isvalide=1;
    while(isvalide)
    {
        printf("Enter the employee id you want to delete : ");
        if(scanf("%d%c",&id, &checkvalid)!=2||checkvalid!='\n')
        {
            printf("employee id not valid\n");
            while (getchar() != '\n');
        }
        else
        {
            char foundindex=0;
            for(int i=0; i<size; i++)
            {
                if(foundindex)
                {
                    e[i-1]=e[i];
                }
                if(e[i].code==id)
                {
                    foundindex=1;
                    uniqcode[id]=0;
                    isvalide=0;
                }
            }
            if(foundindex==0)
            {
                printf("employee id not found\n");
            }
        }
    }
}

