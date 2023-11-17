#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Function to create a node
void Begin(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *temp;
    int item;
    if(ptr == NULL){
        printf("List not empty...\n");
    }
    else{
        printf("Enter item : ");
        scanf("%d" , &item);
        ptr -> data = item;
        if(head == NULL){
            head = ptr;
            ptr -> next = head;
        }
        else{
            temp = head;
            while (temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
            head = ptr;
        }
        printf("Node inserted...\n");
        show();
    }
}

// Function to insert at the end
void End(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *temp;
    int item;
    if(ptr == NULL){
        printf("List not empty...\n");
    }
    else{
        printf("Enter the item : ");
        scanf("%d" , &item);
        ptr -> data = item;
        if(head == NULL){
            head = ptr;
            ptr -> next = head;
        }
        else{
            temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
        }
        printf("Node inserted...\n");
        show();
    }
}

// Printing or Traversing
void show(){
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("List is Empty...\n");
    }
    else{
        while(ptr -> next != head){
            printf("%d -> " , ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d -> " , ptr -> data);
    }
}

int main(){
    int choice;
    do{
        printf("\nEnter 1 to Insert in Beginning\nEnter 2 to Insert at End\nEnter 3 to Exit\nEnter your Choice : ");
        scanf("%d" , &choice);
        switch(choice){
            case 1 : 
                    Begin();
                    break;
            case 2 :
                    End();
                    break;
            case 3:
                    exit(0);
            default:
                    printf("Enter valid choice...\n");
        }
    }while(choice != 3);
    
}