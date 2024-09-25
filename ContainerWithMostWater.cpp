#include <iostream> 
#include <vector> 
using namespace std; 

//To Find Containter With Most Water (Brute Approach).... in O(N^2)
int mostWaterBruteApproach(vector<int> & heights){
    int maxWater = 0; //ans

    for(int i =0; i<heights.size(); i++){
        for(int j = i+1; j<heights.size(); j++){
            int currentWidth = j-i; 
            int currentHeight = min(heights[i], heights[j]);

            int currentWater = currentWidth*currentHeight;
            maxWater= max(currentWater,maxWater);
        }
    }
    return maxWater;
}
//To Find Containter With Most Water (Optimal Approach .. 2 Pointer Approach).... in O(N)
int mostWaterOptimalApproach(vector<int> & heights){
    int maxWater = 0; //ans
    int leftPointer = 0, rightPointer = heights.size()-1;
    while(leftPointer<rightPointer){
        int width = rightPointer - leftPointer;
        int height = min(heights[leftPointer], heights[rightPointer]);
        int currWater = width*height;
        maxWater = max(maxWater , currWater);

        heights[leftPointer] < heights[rightPointer] ? leftPointer++ : rightPointer--;
    }
    return maxWater;
}

int main(){
    
    vector<int> heights={1,8,6,2,5,4,8,3,7};

   // int result = mostWaterBruteApproach(heights); 

    //cout<<"Result : "<<result<<endl;

    
    int result = mostWaterOptimalApproach(heights); 
    cout<<"Result : "<<result<<endl;

    return 0; 
}