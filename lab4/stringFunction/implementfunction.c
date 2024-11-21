#define TERMINATOR '\0'

int stringLength(char str[])
{
    char size=0;
    while(str[size]!=TERMINATOR)
    {
        size++;
    }
    return size;
}


void stringConcat (char dest[],char src[],int destSize)
{
    int i= stringLength(dest);
    if(destSize < (i+stringLength(src))-1)
    {
        printf("the destination string don't large enough\n");
    }
    else
    {
        int j=0;
        while(src[j]!= TERMINATOR)
        {
            dest[i]=src[j];
            i++,j++;
        }
    }
}

void stringCopy (char dest[],char src[],int destSize)
{
    if(destSize<stringLength(src))
    {
        printf("the destination string don't large enough\n");
    }
    else
    {
        int i=0;
        while(src[i]!=TERMINATOR)
        {
            dest[i]=src[i];
            i++;
        }
        dest[i]=TERMINATOR;
    }
}

void stringCompare (char str1[],char str2[])
{
    char index=0,isequal=1;
    while(str1[index]!=TERMINATOR && str2[index]!=TERMINATOR && isequal)
    {
        if(str1[index]>str2[index])
        {
            printf("first string greater than second string\n");
            isequal=0;
        }
        else if(str2[index]>str1[index])
        {
            printf("second string greater than first string\n");
            isequal=0;
        }
        index++;
    }

    if(str1[index]==TERMINATOR && str2[index]==TERMINATOR)
    {
        printf("first string equal second string\n");
    }
    else if(str1[index]==TERMINATOR && str2[index]!=TERMINATOR)
    {
        printf("second string greater than first string\n");
    }
    else if(str1[index]!=TERMINATOR && str2[index]==TERMINATOR)
    {
        printf("first string greater than second string\n");
    }
}

void convertStringToUpper (char str[])
{
    char index=0;
    while(str[index]!=TERMINATOR)
    {
        if(str[index]>='a' && str[index]<='z')
        {
            str[index]-=32;
        }
        index++;
    }
}

void convertStringToLower(char str[])
{
    char index=0;
    while(str[index]!=TERMINATOR)
    {
        if(str[index]>='A' && str[index]<='Z')
        {
            str[index]+=32;
        }
        index++;
    }
}
