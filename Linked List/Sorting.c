#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Function to create node
void create(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    int item;
    if(ptr == NULL){
        printf("List is Full...\n");
    }
    else{
        printf("Enter item: ");
        scanf("%d" , &item);
        ptr -> data = item;
        ptr -> next = head;
        head = ptr;
        printf("Node created...\n");
    }
}

// Function to sort the list
// void swap(struct Node *head){
    
    
// }

// Print list
void show(){
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("List is empty...\n");
    }
    else{
        while(ptr != NULL){
            printf("%d -> " , ptr -> data);
            ptr = ptr -> next;
        }
        printf("Null\n");
    }
}

int main(){
    int len;
    printf("Enter the number of elements of list : ");
    scanf("%d" , &len);
    int i = 0;
    while(i != len){
        create();
        i++;
    }
    printf("Before swapping : \n");
    show();
    int swapped;
    struct Node *ptr;
    ptr = head;
    do{
        swapped = 0;
        
    while(ptr -> next != NULL){
        if(ptr->data > (ptr->next)->data){
            int temp = ptr->data;
            ptr->data = (ptr->next)->data;
            (ptr->next)->data = temp;
            swapped = 1;
        }
        ptr = ptr -> next;
    }
  }while(swapped);
    printf("After swapping : \n");
    show();
}