#include<stdio.h>
#include<stdlib.h>

// NODE Structure
    struct Node{
        int data;
        struct Node *next;
    };
    struct Node *head;

// Function of Creating Node
    void createNode(int item) {
        struct Node *ptr = (struct Node *) malloc(sizeof(struct Node *));
    if (ptr == NULL){
        printf("\n Not Empty... Overflow !!!");
    }
    else{
        ptr -> data = item;
        ptr -> next = head;
        head = ptr;
        }
    }

    // Function to Traverse A Linked List
    void traverse(){
        struct Node *ptr;
        ptr = head;
        if (ptr == NULL){
            printf("List is Empty...");
        }
        else{
            while (ptr != NULL){
                printf("%d -> " , ptr -> data);
                ptr = ptr -> next ;
            }
            printf("NULL \n");
        }
    }

int main(){
    int choice , item;
    do{
    printf("\n Enter 1 for Creating Node \n Enter 2 for Traversing \n Enter 3 for Exit \n Enter your choice : ");
    scanf("%d" , &choice);
    
        switch(choice){
        case 1: 
                printf("Enter the item : ");
                scanf("%d" , &item);
                createNode(item);
                printf("Node Created\n");
                break;

        case 2:
                printf("\nTraversing List : ");
                traverse();
                break;

        case 3:
                printf("End...");
                exit(0);

        default:
                printf("Enter valid choice...");
    }
    }
   while(choice!=3); 

    
    
}