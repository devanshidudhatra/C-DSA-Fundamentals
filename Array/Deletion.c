#include<stdio.h>

int main(){
    int arr[10] = {1,3,5,7,9};
    int len =5 , i, num , pos , temp=0; 
    // Array before Deletion
    printf("Array before Deletion : ");
    for (i=0 ; i<len ; i++){
        printf("%d " , arr[i]);
    }

    // // Deletion at a specific index
    // printf("\nEnter the position at which u want to delete the element : ");
    // scanf("%d" , &pos);
    // for(i=pos ; i<len ; i++){
    //     arr[i] = arr[i+1];
    // }

    // Delete a specific element
    printf("\nEnter the element u want to delete : ");
    scanf("%d" , &num);
        // Searching the index of element
        for(i =0 ; i<5 ; i++){
        if(arr[i] == num){
           pos = i;
        }
        else{
            temp++;
            continue;
        }
        if (temp == 5){
        printf("Number not found");
        }
        // Deletion
        for(i=pos ; i<len ; i++){
        arr[i] = arr[i+1];
        }
    }

    // Array after Deletion
    printf("Array after Deletion : ");
    for (i=0 ; i<len-1 ; i++){
        printf("%d " , arr[i]);
    }
}