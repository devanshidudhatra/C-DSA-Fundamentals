#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Function to craete Node
void createNode(){
    int item;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    if(ptr == NULL){
        printf("List not empty... Overflow\n");
    }
    else{
        printf("Enter the item : ");
        scanf("%d" , &item);
        ptr -> data = item ;
        ptr -> next = head;
        head = ptr;
        printf("Node created...\n");
        Print();
    }
   
}

// Deletion at the beginning
void Begin(){
    struct Node *ptr;
    if(head == NULL){
        printf("List is Empty... Underflow\n");
    }
    else{
        ptr = head;
       head = ptr -> next;
       free(ptr);
       printf("Node Deleted at beginning...\n");
       Print();
    }
}

// deletion at the end
void End(){
    struct Node *ptr;
    struct Node *preptr;
    if(head == NULL){
        printf("List is Empty... Underflow\n");
    }
    else{
        if(head -> next == NULL){
            head = NULL;
            free(head);
            Print();
        }
        else{
            ptr = head;
        while(ptr->next != NULL){
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = NULL;
        printf("Node deleted at End...\n");
        Print();
        }
    }
}

void Position(){
    struct Node *ptr;
    struct Node *preptr;
    int i =0 , pos;
    if(head == NULL){
        printf("List is Empty... Underflow\n");
    }
    else{
        if(head -> next == NULL){
            head = NULL;
            free(head);
            Print();
        }
        else{
            printf("Enter the position : ");
            scanf("%d" , &pos);
            ptr = head;
            while(i!=pos){
                preptr = ptr;
                ptr = ptr -> next;
                i++;
            }
            preptr -> next = ptr -> next;
            ptr -> next = NULL;
            free(ptr);
            printf("Node Deleted... \n");
            Print();
        }
    }
}

void Print(){
    struct Node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("List is Empty...\n");
    }
    else{
        while(ptr != NULL){
            printf(" %d -> " , ptr->data);
            ptr = ptr -> next;
        }
        printf("NULL ");
    }
}

int main(){
    int choice;
    do{
        printf("\nEnter 1 to Create a node\nEnter 2 to Delete at Beginning\nEnter 3 to Delete at End\nEnter 4 to Delete at Position\nEnter 5 to Exit\nEnter your choice : ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                    createNode();
                    break;
            case 2:
                    Begin();
                    break;
            case 3:
                    End();
                    break;
            case 4:
                    Position();
                    break;
            case 5:
                    printf("End...\n");
                    exit(0);
            default:
                    printf("invalid choice...");
        }
    }while(choice!=5);
}