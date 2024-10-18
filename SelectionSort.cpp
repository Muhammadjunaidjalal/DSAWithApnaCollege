#include <iostream> 
using namespace std; 

//Insertion Sorting Using in... O(N^2)
void insertionSort(int arr[], int size){
    for(int i =0; i<size; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

void printArray(int arr[], int size){
    for(int i =0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main(){

    int size = 5; 
    int arr[size]={5,7,3,9,2};

    insertionSort(arr,size);
    printArray(arr,size); // 2,3,5,7,9
    return 0; 
}