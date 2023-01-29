#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        cout<<"Stack Overflow"<<endl;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    // arrow (->) represents dereferencing and then point operator 

    // if(isEmpty(s)){
    //     cout<<"The stack is empty"<<endl;
    // }
    // else{
    //     cout<<"The stack is not empty"<<endl;
    // }

    cout<<"Before pushing to the stack"<<endl;
    cout<<"Stack Underflow : "<<isEmpty(s)<<endl;
    cout<<"Stack Overflow : "<<isFull(s)<<endl;

    push(s, 45);
    push(s, 5);
    push(s, 4);
    push(s, 25);
    push(s, 15);
    push(s, 14);
    push(s, 34);
    push(s, 65);
    push(s, 27);
    push(s, 82);
    push(s, 19); // Overflow

    cout<<"After pushing to the stack"<<endl;
    cout<<"Stack Underflow : "<<isEmpty(s)<<endl;
    cout<<"Stack Overflow : "<<isFull(s)<<endl;

    cout<<"Popped from the stack : "<<pop(s)<<endl; // LIFO
    cout<<"Popped from the stack : "<<pop(s)<<endl;
    cout<<"Popped from the stack : "<<pop(s)<<endl;
    return 0;
}