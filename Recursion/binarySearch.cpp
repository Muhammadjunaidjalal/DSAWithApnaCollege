#include <iostream> 
using namespace std; 

bool binarySearch(int *arr, int start, int end, int key){
    
    if(start>end) return false; 

    int mid = start +(end -start)/2; 

    if(arr[mid] == key) return true; 

    if(arr[mid] < key) 
        return binarySearch(arr,mid+1,end,key);
    else 
        return binarySearch(arr, start,mid-1, key); 
}

int main(){
    int const size = 5; 
    int arr[size] = {3,4,5,6,7}; 

    if(binarySearch(arr,0,4,9))
        cout<<endl<<endl<<"Present: "<<endl<<endl;
    else
        cout<<endl<<endl<<"Absent: "<<endl<<endl;
    return 0; 
}