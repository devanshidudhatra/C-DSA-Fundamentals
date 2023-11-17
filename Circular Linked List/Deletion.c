#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Function to insert node at the end
void insert(){
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
        }
        printf("Node inserted...\n");
        show();
    }
}

// Function to delete node from beginning
void begin(){
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("List is Empty...");
    }
    else{
        if(ptr -> next == head){
            head = NULL;
            free(head);
        }
        else{
            while (ptr -> next != head){
            ptr = ptr -> next;
            }
            ptr -> next = head -> next;
            free(head);
            head = ptr -> next;
        }
        show();
    }
    

}

// Function to delete the Node from end
void end(){
    struct Node *ptr , *preptr;
    ptr = head;
    while(ptr -> next != head){
        preptr = ptr;
        ptr = ptr -> next ;
    }
    preptr -> next = ptr -> next;
    free(ptr);
    show();
}

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
        printf("\nEnter 1 to insert\nEnter 2 to Delete from beginning\nEnter 3 to Delete from End\nEnter 4 to Exit\nEnter your choice: ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                    insert();
                    break;
            case 2:
                    begin();
                    break;
            case 3:
                    end();
                    break;
            case 4:
                    exit(0);
            default:
                    printf("Enter valid choice...\n");
        }
    }while(choice!=4);
}