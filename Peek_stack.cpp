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

// peek function to directly access a value out of the stack, here i represents the relative position in stack, and top - i + 1 represents the corresponding array index
int peek(struct stack * sp, int i){
    int arrInd = sp->top -i + 1;
    if(arrInd < 0){
        cout<<"Not a valid position in the stack"<<endl;
        return -1;
    }
    else{
        return sp->arr[arrInd];
    }
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 11;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    cout<<"Before pushing to the stack"<<endl;
    cout<<"Stack is empty : "<<isEmpty(s)<<endl;
    cout<<"Stack is full : "<<isFull(s)<<endl;

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
    push(s, 19); 

    cout<<"After pushing to the stack"<<endl;
    cout<<"Stack is empty : "<<isEmpty(s)<<endl;
    cout<<"Stack is full : "<<isFull(s)<<endl;

    // to get elements according to position in the stack, i.e. following LIFO/FILO property, we will use peek function

    for(int j=1; j<=s->top+1; j++){
        cout<<"Value at the position "<<j<<" is : "<<peek(s, j)<<endl;
    }
    return 0;
}