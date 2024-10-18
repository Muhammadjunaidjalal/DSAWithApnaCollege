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

void printArray(int arr[], int size){
    for(int i =0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main(){

    int size = 5; 
    int arr[size]={5,7,3,9,2};

    bubbleSort(arr,size);
    printArray(arr,size); // 2,3,5,7,9
    return 0; 
}