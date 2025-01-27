#include <iostream> 
using namespace std; 

void bubbleSort(int *arr, int size){
    
    if(size == 0 || size == 1)
        return; 
    
    for(int i = 0; i<size-1; i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubbleSort(arr, size-1);
}
void print(int *arr, int size){
    if(size == 0)
        return;

    cout<<arr[0]<<" ";
    
    print(arr+1, size-1);

    
}

int main(){

    int const SIZE = 5; 
    int arr[SIZE] = {3,4,2,1,5}; 
    cout<<endl<<endl<<"BEFORE SORTING: ";
    print(arr, SIZE);

    bubbleSort(arr,SIZE);

    cout<<endl<<endl<<"AFTER SORTING: ";
    print(arr, SIZE);

    return 0; 
}