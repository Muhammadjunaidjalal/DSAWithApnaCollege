#include <iostream> 
#include <vector> 
using namespace std; 

int search(vector<int> &array, int target){
    int start = 0, end = array.size()-1;

    while(start<=end){
        int mid = start+(end-start)/2;

        if(array[mid]==target){
            return mid;
        }

        if(array[start]<=array[mid]){
            if(array[start]<=target && target<=array[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }else{
            if(array[mid]<=target && target<=array[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
    }
    return -1;
}
int main(){

     vector<int> arr = {1,45,65,87,99};
     cout<<search(arr,65); // 2
    return 0;
}