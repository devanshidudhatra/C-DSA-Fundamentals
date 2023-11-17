#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head;

void Begin(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    int item;
    if(ptr == NULL){
        printf("List not Empty...\n");
    }
    else{
        printf("Enter the item : ");
        scanf("%d" , &item);
        ptr -> data = item;
        if(head == NULL){
            ptr -> prev = NULL;
            ptr -> next = NULL;
            head = ptr;
        }
        else{
            head -> next = NULL;
            ptr -> next = head;
            head -> prev = ptr;
            
            ptr -> prev = NULL;
            head = ptr;
        }
        printf("Node inserted...\n");
        show();
    }
}

void End(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *temp;
    int item;
    if(ptr == NULL){
        printf("List not Empty...\n");
    }
    else{
        printf("Enter item : ");
        scanf("%d" , &item);
        ptr -> data = item;
        if(head == NULL){
            ptr -> prev = NULL;
            ptr -> next = NULL;
            head = ptr;
        }
        else{
            temp = head;
            while(temp != NULL){
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = NULL;
            ptr -> prev = temp;
        }
        printf("Node inserted...\n");
        show();
    }
}

void Position(){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *temp;
    int item , pos , i =0;
    if(ptr == NULL){
        printf("List not empty...\n");
    }
    else{
        printf("Enter item : ");
        scanf("%d" , &item);
        printf("Enter the position : ");
        scanf("%d" , &pos);
        ptr -> data = item;
        temp = head;
        while(i != pos){
            temp = temp -> next;
            i++;
        }
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        temp -> next = ptr;
        ptr -> prev = temp;
        printf("Node created...\n");
        show();
    }
}

void show(){
    struct Node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d -> " , ptr -> data);
        ptr = ptr -> next;
    }
    printf(" NULL");
}

int main(){
    int choice;
    do{
        printf("\nEnter 1 to insert in beginning\nEnter 2 to insert in end\nEnter 3 to insert in middle\nEnter 4 to exit\nEnter your choice : ");
        scanf("%d" , &choice);
        switch(choice){
            case 1 :
                    Begin();
                    break;
            case 2 :
                    End();
                    break;
            case 3 :
                    Position();
                    break;
            case 4 :
                    exit(0);
            default :
                    printf("Enter valid choice...\n");
        }
    }while(choice != 4);
}