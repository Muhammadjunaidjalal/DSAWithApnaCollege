#include <iostream> 
#include <vector>
using namespace std; 

//Binary Search Using Iterators ... in O(logN)
int binarySearch(vector<int> &array, int target){
    int start =0, end = array.size()-1;

    while (start<=end){
        int mid = start+end/2;
        
        if(target >array[mid])
            start = mid+1; 
        else if(target<array[mid])
            end = mid-1;
        else 
             return mid;
    }
    return -1;
}

//Binary Search Using Recursion 
int recursiveBinarySearch(vector<int>&array, int target, int start, int end){
    if(start<=end){
        int mid = start+(end-start)/2;
        if(target>array[mid])
            return recursiveBinarySearch(array,target,mid+1,end);
        else if(target<array[mid])
            return recursiveBinarySearch(array,target,start,mid-1);
        else 
            return mid;
    }
    return -1;
}

int main(){
    
    vector<int> arr = {1,45,65,87,99};

    cout<<binarySearch(arr,65)<<endl;

    cout<<recursiveBinarySearch(arr,87,0,4);

    return 0;
}