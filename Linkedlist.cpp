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

    return 0;
}