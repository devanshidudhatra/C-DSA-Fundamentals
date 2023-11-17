#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Function to insert at Beggining
void Beginning(){
    int item;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter the item : ");
    scanf("%d" , &item);
    if(ptr == NULL){
        printf("List not Empty... Overflow\n");
    }
    else{
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node inserted at Beginning...\n");
        print();
    }
}

// Function to insert at the end
void End(){
    int item;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    
    if(ptr == NULL){
        printf("List not empty... Overflow\n");
    }
    else{
        printf("Enter the item :");
        scanf("%d" , &item);
        ptr -> data = item;
        if(head == NULL){
            ptr -> next = NULL;
            head = ptr;
        }
        else{
            struct Node *temp;
            temp = head;
            while(temp -> next !=NULL){
            temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = NULL;
            printf("Node inserted at end...\n");
            print();
        }
        
     }
}

// Function to insert at Any Position
void Position(){
    int item , pos;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *temp;
    if(ptr == NULL){
        printf("List not Empty... Overflow\n");
    }
    else{
        printf("Enter the item : ");
        scanf("%d" , &item);
        printf("Enter the position : ");
        scanf("%d" , &pos);
        ptr -> data = item;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
        }
        else{
            temp = head;
            int i=1;
            while(i != pos){
                temp = temp->next;
                i++;
            }
            ptr -> next = temp -> next;
            temp -> next = ptr;
            printf("Node inserted at specified position...\n");
            print();
        }
    }
}

// Function to print List
void print(){
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
    int choice;
    do{
        printf("\nEnter 1 for insertion in Beginning\nEnter 2 for Insertion in End\nEnter 3 for Insertion at any Position\n Enter 4 to Exit\n Enter your choice : ");
    scanf("%d" , &choice);
    switch(choice){
        
        case 1:
                Beginning();
                break;
        case 2:
                End();
                break;
        case 3:
                Position();
                break;
        case 4:
                printf("End...");
                exit(0);
        default:
                printf("Enter valid Choice...");
    }
    }while(choice!=4);
    
}
    


