#include <iostream> 
#include <vector> 
using namespace std; 

//Displaying Pair of Sum (Brute Force Approach) O(n^2)
vector <int> PairSumBruteForce(int arr[], int size, int targetSum){
    vector <int> ans; 
    for(int i =0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(arr[i]+arr[j]==targetSum){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
}
//Displaying Pair of Sum (Optimized Approach) O(n)
vector <int> PairSumOptimized(int arr[], int size, int targetSum){
    vector <int> ans; 
    int i =0, j = size-1; 
    while(i<j){
        int pairSum = arr[i]+arr[j]; 
        if(pairSum<targetSum){
            i++;
        }else if(pairSum>targetSum){
            j--;
        }else{
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            return ans;
        }
    }
}

int main(){
    const int SIZE = 4;
    int arr[SIZE]={2,7,11,15};
    int targetSum = 9; 

   // vector <int> ans = PairSumBruteForce(arr,SIZE,targetSum);

    vector <int> ans = PairSumOptimized(arr,SIZE,targetSum);

    cout<<ans[0]<<" , "<<ans[1]<<endl; 
    return 0; 
}