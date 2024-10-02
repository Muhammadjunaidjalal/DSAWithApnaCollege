#include <iostream> 
#include <vector> 
using namespace std;

 int peakIndexInMountainArray(vector<int>& array) {
        int start =1, end = array.size()-2;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(array[mid-1]<array[mid]&&array[mid]>array[mid+1]){
                return mid;
            }else if(array[mid-1]<array[mid]){
                start= mid+1;
            }else {
                end = mid-1;
            }
        }
        return -1;
    }


    int main(){

        vector<int> input = {1,2,3,4,5,4,3,2};

        cout<<"Index: "<<peakIndexInMountainArray(input);

        return 0;
    }