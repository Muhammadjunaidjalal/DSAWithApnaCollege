#include <iostream> 
using namespace std; 

int partition(int *arr, int start, int end){

    int pivot = arr[start]; 

    int cnt =0; 

    for(int i =start+1; i<=end; i++){

        if(arr[i]<=pivot)
            cnt++;
    }

    int pivotIndex = start+cnt; 
    swap(arr[pivotIndex], arr[start]);

    int i = start; 
    int j = end;

    while(i < pivotIndex && j> pivotIndex){
        while (arr[i] <= pivot)
        {
            i++;
        }

         while (arr[j] > pivot)
        {
            j--;
        }

        if(i < pivotIndex && j> pivotIndex)
            swap(arr[i++], arr[j--]);
        
    }

    return pivotIndex;
}


void quickSort(int *arr, int start, int end){
    
    if(start>=end)
        return;
    
    int position = partition(arr, start, end); 

    quickSort(arr, start, position-1); 

    quickSort(arr, position+1, end);
}

void print(int *arr, int size){
    if(size == 0)
        return;

    cout<<arr[0]<<" ";
    
    print(arr+1, size-1);

    
}

int main(){

    int const SIZE = 5; 
    int arr[SIZE] = {2,3,1,6,5};

    cout<<endl<<endl<<"BEFORE SORTING: ";
    print(arr, SIZE);

    quickSort(arr, 0, SIZE-1);

    cout<<endl<<"AFTER SORTING: ";
    print(arr, SIZE);
    cout<<endl<<endl;


    return 0;
}