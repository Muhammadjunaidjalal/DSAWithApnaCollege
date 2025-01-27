#include <iostream> 
using namespace std; 

bool isSorted(int *arr, int size){

    //base Case
    if(size == 0 || size == 1)
        return true; 
    
    if(arr[0] > arr[1])
        return false; 
    //Recursive Relation
    return isSorted(arr+1, size-1);
}

//Driver Function 
int main(){

    int const size =6;
    int arr[size]={2,3,4,67,87,90};

    if(isSorted(arr,size))
        cout<<endl<<"Array is Sorted: "<<endl<<endl; 
    else
        cout<<endl<<"Array is Not Sorted: "<<endl<<endl;


    return 0; 
}