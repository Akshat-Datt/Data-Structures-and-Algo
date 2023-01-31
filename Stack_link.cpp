#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

int isEmpty(struct Node * t){
    if(t == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node * t){
    // if memory in heap can't be allocated, then it's regarded as full
    struct Node * p = (struct Node *)malloc(sizeof(int));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node * push(struct Node * top, int x){
    if(isFull(top)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node ** top){
    if(isEmpty(*top)){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        struct Node * n = (*top);
        (*top) = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

void traversal(struct Node * ptr){
    while(ptr != NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main(){
    struct Node * top = NULL;
    top = push(top, 78);
    top = push(top, 67);
    top = push(top, 56);
    traversal(top);

    int element = pop(&top);
    cout<<"Popped element : "<<element<<endl;
    traversal(top);
    return 0;
}