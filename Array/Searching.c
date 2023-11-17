#include<stdio.h>
int main(){
    int arr[5] = {1,3,5,7,9};
    int num , i , temp = 0;
    printf("Enter the element u want to search in array : ");
    scanf("%d" , &num);
    for(i =0 ; i<5 ; i++){
        if(arr[i] == num){
            printf("Number %d is found at index %d " , num , i+1);
        }
        else{
            temp++;
            continue;
        }
    }
    if (temp == 5){
        printf("Number not found");
    }
    return 0;
}