#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void traversal(struct Node * head, struct Node * fourth){
    struct Node * ptr = head;
    while(ptr != NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    if (ptr == NULL){
            cout<<"Reversal"<<endl; 
            struct Node * p = fourth;
            while(p != NULL){
                cout<<"Element : "<<p->data<<endl;
                p = p->prev;
            }
        }
    
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;
    head->prev = NULL;

    second->data = 4;
    second->next = third;
    second->prev = head;

    third->data = 6;
    third->next = fourth;
    third->prev = second;

    fourth->data = 8;
    fourth->next = NULL;
    fourth->prev = third;

    traversal(head, fourth);
    return 0;
}

