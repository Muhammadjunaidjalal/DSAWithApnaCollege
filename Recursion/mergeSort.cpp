#include <iostream> 
using namespace std; 

void merge(int *arr, int start ,int end){

    int mid = start + (end - start)/2; 

    int length1 = mid - start + 1;
    int length2 = end - mid; 

    int *first = new int[length1];
    int *second = new int[length2];

    int mainArrayIndex = start; 

    for(int i =0; i<length1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i =0; i<length2; i++){
        second[i] = arr[mainArrayIndex++];
    }


    int index1 =0;
    int  index2 = 0;
    mainArrayIndex = start; 

    while (index1 <length1 && index2 < length2)
    {
        if(first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];
    }

    while (index1 < length1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    
    while (index2 < length2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete[] first; 
    delete[] second;
}

void mergeSort(int *arr, int start, int end){

    if(start>=end)
        return;
    
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);

    mergeSort(arr, mid+1, end); 

    merge(arr, start, end);
}
//recursive print function 
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

    mergeSort(arr, 0, 4);

    cout<<endl<<"AFTER SORTING: ";
    print(arr, SIZE);
    cout<<endl<<endl;


    return 0;
}