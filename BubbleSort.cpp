#include <iostream> 
using namespace std; 

//Bubble Sorting Using in... O(N^2)
void bubbleSort(int arr[], int size){
    bool swaped;
    for(int i =0; i<size-1; i++){
        swaped = false;
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }
            if(!swaped){
                break;
            }
    }
}