#include<stdio.h>
#include<stdlib.h>

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

// Function to search in Node
void search(){
    int num , flag = 0;
    struct Node *ptr ;
    ptr = head;
    if (ptr == NULL){
        printf("List is Empty...\n");
    }
    else{
        printf("Enter the number u want to search : ");
        scanf("%d" , &num);
        while(ptr != NULL){
            if(ptr -> data == num){
                printf("Number is found... \n");
                flag =0;
            }
            else{
                flag = 1;
            }
            ptr = ptr -> next;
        }
    }
    if(flag == 1){
        printf("Number not found...\n");
    }
}

int main(){
    int choice , item;
    do{
    printf("Enter 1 to Create Node\n Enter 2 to Search \n Enter 3 to Exit \n Enter Your Choice : ");
    scanf("%d" , &choice);
    switch(choice){
        case 1:
                printf("Enter Item : ");
                scanf("%d" , &item);
                createNode(item);
                printf("Node Created\n");
                break;

        case 2:
                search();
                break;

        case 3:
                printf("End...");
                exit(0);
        default:
                printf("Invalid Choice ... \n");
    }
    }while(choice!=3);
}