#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
    struct Node* head;
};

void display(struct LinkedList *list){
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current = list->head;
    if(current == NULL)
    {
        printf("Linked list is empty");
        return;
    }
    while(current!=NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL");
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void addNode(struct LinkedList *list, int data) {
    struct Node *current = list->head;
    struct Node *newNode = createNode(data);
    
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    printf("\nAdded the node successfully\n");
}


void insertNode(struct LinkedList *list, int data, int position){
    struct Node* current = list->head;
    struct Node* newNode = createNode(data);
    if(position == 0){
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    else{
        for(int i = 0;i<position-1;i++){
            if(current == NULL){
                printf("\nPosition is out of bounds");
                free(newNode);
                return;
            } 
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("\nInserted the node successfully\n");
}

void deleteNode(struct LinkedList *list, int position){
    if(list->head == NULL){
        printf("\nDeletion is not possible");
        return;
    }
    
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current = list->head;
    if(position == 0){
        list->head = current->next;
        free(current);
        return;
    }
    else{
        struct Node* prev = NULL;
        for (int i = 0; i < position; i++) {
        if (current == NULL) {
            printf("\nPosition out of bound. Deletion not possible");
            return;
        }
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // If prev is NULL, it means we are deleting the head
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    }
    printf("\nDeleted the node successfully\n");
}

int main()
{
    struct LinkedList list = {.head = NULL};
    int choice, data, position;
    do{
        printf("\nEnter your choice of Linked List operations");
        printf("\n1.Add a node");
        printf("\n2.Insert a node");
        printf("\n3.Delete a Node");
        printf("\n4.Display the linked list");
        printf("\n0.Exit");
        
        printf("\nChoice: ");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1:
            printf("\nEnter the data to be added in the node: ");
            scanf("%d",&data);
            addNode(&list,data);
            break;
            
            case 2:
            printf("\n Enter the data to be added in the node: ");
            scanf("%d",&data);
            printf("\n Enter the position: ");
            scanf("%d",&position);
            insertNode(&list,data,position);
            break;
            
            case 3:
            printf("\n Enter the position to delete: ");
            scanf("%d",&position);
            deleteNode(&list,position);
            break;
            
            case 4:
            display(&list);
            break;
            
            case 0:
            printf("\nExiting...");
            break;
            
            default:
            printf("\nInvalid option");
        }
    } while(choice!=0);
    
    return 0;
}
