#include <iostream> 
using namespace std; 

//Bubble Sorting Using in... O(N^2)
void selectionSort(int arr[], int size){
    for(int i =0; i<size-1; i++){
        int minIdx =i; 
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIdx]){
                minIdx =j;
            }
        }
        if(minIdx!=i){
            swap(arr[i],arr[minIdx]);
        }
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

    selectionSort(arr,size);
    printArray(arr,size); // 2,3,5,7,9
    return 0; 
}