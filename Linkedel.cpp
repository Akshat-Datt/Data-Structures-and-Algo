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

// deleting node from beginning 
struct Node* delFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// deleting node from given index
struct Node * delAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// deleting node from the last
struct Node * delEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// deleting a node with a given value
struct Node * delVal(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL && q->data != value){
        p = p->next;
        q = q->next;
    }
    p->next = q ->next;
    free(q);
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

    // linking third to fourth linked list
    third->data = 90;
    third->next = fourth;

    // terminating the linked list
    fourth->data = 70;
    fourth->next = NULL;

    // before deletion
    traversal(head);

    // after deletion
    // head=delFirst(head);
    // head = delAtIndex(head, 1);
    // head = delEnd(head);
    head = delVal(head, 90);
    cout<<"List after deletion"<<endl;
    traversal(head);

    return 0;
}