#include <iostream> 
using namespace std; 

//Dutch National Flag Sorting Algorithm in... O(N^2)
void DNFSorting(int arr[], int size){
    int low=0,mid=0, high = size-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++; low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
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

    int const size = 5; 
    int arr[size]={2,0,1,2,1};

    DNFSorting(arr,size);
    printArray(arr,size); // 0,1,1,2,2
    return 0; 
}