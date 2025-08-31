#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createN(int data){
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    newN->data = data;
    newN->next = NULL; 
    return newN;
}

void insertAtEnd(int data){
    struct Node* newN = createN(data);
    if (head == NULL){
        head = newN;
        tail = newN;
    }
    else{
        tail->next = newN;
        tail = newN;
    }
}

void print(){
    struct Node* a = head;
    while(a != NULL){
        printf("%d -> ", a->data);
        a = a->next;
    }printf("NULL\n");
}

void searchL(int key){
    struct Node* temp = head;
    int j=1;

    while (temp!=NULL){
        if(temp->data == key){
            printf("Element %d found at position %d\n", key, j);
            return;
        }
        else{
            temp=temp->next;
            j++;
        }
    }printf("Element %d not found in the list\n", key);
}

void insertAtBeginning(int data){
    struct Node* newN = createN(data);
    newN->next = head;
    head=newN;
    if (tail == NULL)
        tail=newN;
}

void insertAtPosition(int data, int pos){
    if (pos <= 1){  
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Position out of bounds, inserting at end instead.\n");
        insertAtEnd(data);
        return;
    }

    if (temp->next == NULL){
        insertAtEnd(data);
        return;
    }
    struct Node* newN = createN(data);
    newN->next = temp->next;
    temp->next = newN;
}

void deleteAtBeginning(){
    if (head == NULL){
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    if (head == NULL)
        tail = NULL;
}

void deleteAtEnd(){
    if (head == NULL){
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (head->next == NULL){
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != tail){
        temp = temp->next;
    }
    free(tail);
    tail = temp;
    tail->next = NULL;
}

void deleteAtPosition(int pos){
    if (head == NULL){
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (pos <= 1){
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos-1 && temp->next != NULL; i++){
        temp = temp->next;
    }
    if (temp->next == NULL){
        printf("Position out of bounds, nothing to delete.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete == tail)
        tail = temp;
    free(nodeToDelete);
}

void reverse(){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    tail = head; 
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sort(){
    if (head == NULL || head->next == NULL){
        return; 
    }
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do{
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr){
            if (ptr1->data > ptr1->next->data){
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int data;
        printf("Enter node data: ");
        scanf("%d", &data);
        insertAtEnd(data);
    }

    printf("Menu:\n1. Print\n2. Insert at end\n3. Insert at beginning\n4. Insert at position\n5. Delete at end\n6. Delete at beginning\n7. Delete at position\n8. Search\n9. Reverse\n10. Sort\n11. Exit\n");
    int choice;
    int data; int key;
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: print();
                    break;
            case 2: printf("Enter node data: ");
                    scanf("%d", &data);
                    insertAtEnd(data);
                    break;
            case 3: printf("Enter node data: ");
                    scanf("%d", &data);
                    insertAtBeginning(data);
                    break;
            case 4: printf("Enter node data and position: ");
                    int pos;                
                    scanf("%d %d", &data, &pos);
                    insertAtPosition(data, pos);
                    break;
            case 5: deleteAtEnd();
                    break;
            case 6: deleteAtBeginning();
                    break;
            case 7: printf("Enter position to delete: ");
                    int p;  
                    scanf("%d", &p);
                    deleteAtPosition(p);
                    break;     
            case 8: printf("Enter element to search: ");
                    scanf("%d", &key);
                    searchL(key);
                    break;
            case 9: reverse();
                     break; 
            case 10: sort();
                     break;
            case 11: exit(0);
                    break;
            default: printf("Invalid choice\n");
                    break;
        }
    }
}