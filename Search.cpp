#include <iostream>
using namespace std;

// Linear Search
int LinearSearch(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}
// Binary Search - array must be sorted
int BinarySearch(int arr[], int size, int element){
    int mid, low, high;
    low = 0;
    high = size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,21,52,13,94,58,62};
    int size = sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int element;
    cout<<"Enter the element to be found"<<endl;
    cin>>element;
    // int res = LinearSearch(arr, size, element);
    int res = BinarySearch(arr, size, element);
    cout<<element<<" Element is found at "<<res<<" index"<<endl;
    return 0;
}