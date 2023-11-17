#include<stdio.h>
int main(){
    int arr[10] = {1,3,5,7,9};
    int len = 5 ;
    int pos , num;
    // Array before insertion
    printf("Array before insertion : ");
    for (int i =0 ; i< len ; i++){
        printf("%d " , arr[i]);
    }
    len++;
    printf("\nEnter the number that u want to insert in array : ");
    scanf("%d" , &num);
    printf("\nEnter the index where u want to insert the number : ");
    scanf("%d" , &pos);
    // Insertion
   for (int i = len-1; i >= pos; i--)  
        arr[i] = arr[i - 1];  
    arr[pos - 1] = num;  
    
    // Array after insertion
    printf("\nArray after Insertion : ");
    for(int i=0 ; i<len ; i++){
        printf("%d " , arr[i]);
    }
    return 0;
}