#include <iostream> 

using namespace std; 

//Maximum SubArrays
void printSubArrays(int arr[], int size){

    for (int start = 0; start <size ; start++){
        for(int end = start; end <size; end++){
            for(int i = start; i<=end; i++){
                cout<<arr[i];
            }
            cout<<" "; 
        }
        cout<<endl;
    }
}
//Maximum SubArray Sum (Brute Force)
int MaximumSubArraySumBruteForce(int arr[], int size){
    int maximumSum = 0;
    for(int start =0; start<size; start++){
        int currentSum = 0; 
        for(int end = start; end<size; end++){
            currentSum += arr[end];
            maximumSum = max(currentSum, maximumSum);
        }
    }
    return maximumSum;
}

//Maximum SubArray Sum (Kadane's Algorithem)
int MaximumSubArrayKandaneAlgorithem(int arr[], int size){
    int currentSum =0, maxSum = 0; 
    for(int i =0; i<size; i++){
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum<0){
            currentSum = 0; 
        }
    }
    return maxSum;
}

int main(){
    const int SIZE = 5;
    int arr[SIZE] = {1,2,3,4,5};

    //printSubArrays(arr,SIZE);
    cout<<MaximumSubArrayKandaneAlgorithem(arr,SIZE);
   
   return 0; 
}