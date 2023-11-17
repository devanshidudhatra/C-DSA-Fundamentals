#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

// Insert from end
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
            head = ptr ;
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

// Function to search
void search(){
    struct Node *ptr;
    int num;
    if(head == NULL){
        printf("List is Empty...\n");
    }
    else{
        printf("Enter the number to search : ");
        scanf("%d" , &num);
        ptr = head;
        int temp =0;
        while(ptr->next != head){
            if(ptr -> data == num){
                printf("The number is found...\n");
                temp = 0;
            }
            else{
                temp = 1;
            }
            ptr = ptr -> next;
        }
        if(temp == 1){
            printf("Number not found...\n");
        }
    }
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
        printf("\nEnter 1 for insert\nEnter 2 for search\nEnter 3 to Exit\nEnter your Choice : ");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                    insert();
                    break;
            case 2:
                    search();
                    break;
            case 3:
                    exit(0);
            default:
                    printf("Enter vaid choice...\n");
        }
    }while(choice != 3);
}