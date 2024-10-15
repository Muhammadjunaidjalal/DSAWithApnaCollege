#include <iostream> 
#include <vector> 
using namespace std; 

//Finding Single Element in Sorted Array ... in O(log n) Time and O(1) Space Complexity 
int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if(n==1) return A[0];
        int st = 0, end = n-1;
        while(st<=end){
            int mid = st+(end-st)/2; 
            if(mid == 0 && A[mid]!=A[mid+1]) return A[0];
            if(mid == n-1 && A[mid]!=A[mid-1]) return A[n-1];

            if(A[mid-1]!=A[mid] && A[mid]!=A[mid+1]) return A[mid];

            if(mid %2 ==0){
                if(A[mid-1]== A[mid]){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            }else{
                if(A[mid-1]==A[mid]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
}

int main(){

    vector<int> nums{1,1,2,3,3,4,4,8,8};
    cout<<"Single Element in the Array nums: "<<singleNonDuplicate(nums)<<endl;


    vector<int> nums2{3,3,7,7,10,11,11};
    cout<<"Single Element in the Array nums2: "<<singleNonDuplicate(nums2)<<endl;

    return 0; 
}