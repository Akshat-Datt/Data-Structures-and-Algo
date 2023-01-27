#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node * head){
    struct Node * ptr = head;
    while(ptr->next != head){
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    cout<<"Element : "<<ptr->data<<endl;
}

struct Node * insertFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    //dynamic memory allocation for nodes in the linked list
    head  = (struct Node *)malloc(sizeof(struct Node));
    second  = (struct Node *)malloc(sizeof(struct Node));
    third  = (struct Node *)malloc(sizeof(struct Node));
    fourth  = (struct Node *)malloc(sizeof(struct Node));

    // linking first and second node
    head->data = 7;
    head->next = second;

    // linking second and third node
    second->data = 67;
    second->next = third;

    // terminating linked list
    third->data = 70;
    third->next = fourth;

    fourth->data = 71;
    fourth->next = head;

    cout<<"Before insertion"<<endl;
    traversal(head);

    // insertion at first
    cout<<"After insertion"<<endl;
    head = insertFirst(head, 1);
    traversal(head);
    return 0;
}