#include<stdio.h>

void main()
{   int i;
    int *p;
    
    for (i=65; i<91 ;i++)
    {   p=&i;
        printf("%c\t", *p);
    }
}