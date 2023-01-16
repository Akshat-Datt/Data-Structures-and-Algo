#include <iostream>
using namespace std;

struct myArray{
    int total_size; // memory to be reserved for array
    int used_size;  // memory to be used
    int *ptr; // will point to the first element of the array 
};

//function to create the ADT myArray
void createArr(struct myArray *a, int toSize, int useSize) {
    (*a).total_size = toSize;
    (*a).used_size = useSize;
    (*a).ptr = (int*)malloc(toSize * sizeof(int));
    // malloc will help in assigning dynamic memory in thr heap

}
void showArr(struct myArray *a){
    for (int i=0; i< a->used_size; i++){
        cout<<(a->ptr)[i]<<endl;
    }
}
void setVal(struct myArray *a){
    int n;
    for(int i=0; i< a->used_size; i++){
        cout<<"Enter element number "<<i<<" :"<<endl;
        (a->ptr)[i] = n;
        cin>>(a->ptr)[i];
    }
}

int main(){
    struct myArray marks;
    createArr(&marks, 10, 4);
    cout<<"We are running setVal"<<endl;
    setVal(&marks);
    cout<<"We are running showArr"<<endl;
    showArr(&marks);
    return 0;
}