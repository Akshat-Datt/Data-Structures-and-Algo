#include <iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int indDelete(int arr[], int size, int index, int capacity)
{
    if(index > capacity-1){
        return -1;
    }
    for (int i = index; i < size; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

int main(){
    int arr[100] = {1,2,3,4,5,6};
    int size = 6, index = 3;
    display(arr,size);
    indDelete(arr, size, index, 100);
    size--;
    display(arr,size);
    return 0;
}