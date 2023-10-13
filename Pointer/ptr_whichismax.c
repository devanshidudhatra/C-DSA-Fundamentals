#include<stdio.h>

float max_num(float *num1 , float *num2);

int main()
{
    float num1 , num2;
    //taking two numbers
    printf("Enter two numbers:");
    scanf("%f %f" , &num1 , &num2);
    max_num(&num1,&num2);
    return 0;
}

float max_num(float *num1 , float *num2)
{
    if(*num1 > *num2)
    {
        printf("%f" , *num1);
    }
    else if(*num1 < *num2)
    {
        printf("%f" , *num2);
    }
    else{
        printf("both numbers are same.");
    }
}