#include <iostream> 
using namespace std; 

int sumOfArray(int arr[], int size){

    if(size == 0)
        return 0; 
    
    return arr[size-1]+sumOfArray(arr, size-1);
}

int main(){
    int const size = 4; 

    int arr[size] = {3,4,5,6};

    cout<<endl<<"Sum of Array : "<<sumOfArray(arr,size)<<endl<<endl;
    return 0; 
}