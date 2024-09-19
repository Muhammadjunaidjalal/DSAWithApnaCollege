#include <iostream> 
#include <algorithm>
using namespace std; 

//Find Majority Element (Which Exists More Than N/2) (Brute Force Approach) O(n^2)
int majorityElementBruteForce(int arr[], int size){

    for (int i =0; i<size; i++){
        int frequency = 0; 
        for(int j =0; j<size; j++){
            if(arr[i]==arr[j]){
                frequency ++; 
            }
        }
        if(frequency > size/2){
            return frequency;
        }
    }
}
//Find Majority Element (Which Exists More Than N/2) (Optimized Approach Using Sorting) O(nlogn)
int majorityElementUsingSorting(int arr[], int size){
    
    sort(arr, arr+size);
    int frequency =1, ans = arr[0];
    for(int i = 1; i<size; i++){
        if(arr[i]==arr[i-1]){
            frequency++;
        }else {
            frequency = 1; 
            ans = arr[i]; 
        }
        if(frequency > size/2){
            return ans; 
        }
    } 
    return ans; 
}
//Find Majority Element (Which Exists More Than N/2) (Moore's Voting Algorithem)
int majorityElementMooreVotingAlgo(int arr[], int size){
        int frequency =0, ans = 0; 
        for(int i =0; i<size; i++){
            if(frequency == 0){
                ans = arr[i]; 
            }
            if(ans == arr[i]){
                frequency++;    
            }else{
                frequency--;
            }
        }
        return ans; 
}


int main(){
    int const SIZE = 5; 
    int arr[SIZE]= {1,2,2,2,1}; 

   /* int majorityElement = majorityElementBruteForce(arr, SIZE);
    cout<<majorityElement<<endl;

    int majorityElement = majorityElementUsingSorting(arr, SIZE);
    cout<<majorityElement<<endl;*/

    int majorityElement = majorityElementMooreVotingAlgo(arr, SIZE);
    cout<<majorityElement<<endl;

    return 0; 
}