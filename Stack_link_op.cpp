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

int peek(int pos, struct Node * top){
    struct Node * ptr = top;
    for(int i=0; (i < pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int stackTop(struct Node * top){
    return top->data;
}

int stackBottom(struct Node * top){
    struct Node * ptr = top;
    while(ptr != NULL){
        ptr = ptr->next;
        if(ptr->next == NULL){
            return ptr->data;
        }
    }
}

int main(){
    struct Node * top = NULL;
    top = push(top, 78);
    top = push(top, 67);
    top = push(top, 56);
    traversal(top);
    
    cout<<"Value at position 2 is : "<<peek(2, top)<<endl;

    cout<<"Stack top is : "<<stackTop(top)<<endl;

    cout<<"Stack bottom is : "<<stackBottom(top)<<endl;
    return 0;
}