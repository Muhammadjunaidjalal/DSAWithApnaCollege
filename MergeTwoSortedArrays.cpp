#include <iostream> 
#include <vector>
using namespace std; 

//Merge Two Sorted Arrays in O(n)
void mergeTwoSortedArrays(vector<int>& A, int m, vector<int>& B, int n){
        int idx = m+n-1, i = m-1, j=n-1;
        while(i>=0 && j>=0){
            if(A[i]>=B[j]){
                A[idx--] = A[i--];
            }else{
                A[idx--] = B[j--];
            }
        }

        while(j>=0){
            A[idx--]=B[j--];
        }
}
void printArray(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int m = 3,n=3; 
   vector<int> nums1{1,2,3,0,0,0};
   vector<int> nums2 = {2,5,6};
   
    mergeTwoSortedArrays(nums1,m,nums2,n);
    printArray(nums1); //1 2 2 3 5 6

    return 0; 
}