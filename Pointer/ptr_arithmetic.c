#include<stdio.h>

void main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = a;
    printf("Initially a is: %d\n" , *p);
    p++;
    printf("After adding by 1 a is : %d\n" , *p);
    p=p+2;
    printf("After adding by 1 a is : %d\n" , *p);
    p++;
    printf("After adding by 1 a is : %d\n" , *p);
    p++;
    printf("After adding by 1 a is : %d\n" , *p);
    p=p+3;
    printf("After adding by 1 a is : %d\n" , *p);
    p++;
    printf("After adding by 1 a is : %d\n" , *p);
}