#include <iostream> 
#include <stdlib.h>
using namespace std;

// O(n) - time complexity for traversing through the linked list having n number of elements.

struct Node{
    int data;
    struct Node* next;
};

// struct Node * ptr pointing to a struct type
void traversal(struct Node * ptr){
    while(ptr != NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

struct Node * insertAtBegin(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAtIndex(struct Node * head, int data, int index) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * insertAfter(struct Node *head, struct Node *prev, int data){
    struct Node * ptr =  (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prev->next;
    prev->next = ptr;

    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    //dynamic memory allocation for nodes in the linked list
    head  = (struct Node *)malloc(sizeof(struct Node));
    second  = (struct Node *)malloc(sizeof(struct Node));
    third  = (struct Node *)malloc(sizeof(struct Node));

    // linking first and second node
    head->data = 7;
    head->next = second;

    // linking second and third node
    second->data = 67;
    second->next = third;

    // terminating linked list
    third->data = 70;
    third->next = NULL;

    traversal(head);

    // head = insertAtBegin(head, 56);
    // traversal(head);

    cout<<"*******************"<<endl;

    // head = insertAtIndex(head, 19, 2);
    // traversal(head);

    // head = insertAtEnd(head, 69);
    // traversal(head);

    head = insertAfter(head, second, 69);
    traversal(head);

    return 0;
}