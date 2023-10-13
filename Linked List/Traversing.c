#include<stdio.h>
#include<stdlib.h>

// Creating a node
struct node {
    int value;
    struct node *next;
};
void main(){
    struct node *start = NULL;
    int length;

    // Get the length of linked list
    printf("Eneter the length of linked list : ");
    scanf("%d" , &length);
    printf("\n");

    struct node *p;

    // Get the elements of linked list
    // for (int i=0 ; i<length ; i++){
    //     struct node *p;
    //     printf("Enter element %d : " , i + 1);
    //     scanf("%d" , (p -> value));
    //     p = p-> next;
    // }
    while (p != NULL){
        printf("%d " , p-> value);
        p = p -> next;
    }

    while (p != NULL){
        printf("%d " , p-> value);
        p = p -> next;
    }
}