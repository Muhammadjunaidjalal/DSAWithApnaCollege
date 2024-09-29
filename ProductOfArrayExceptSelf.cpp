#include <iostream> 
#include <vector> 
using namespace std; 

// Calculating Product of Array Except Selected Index's value ... in O(N^2)
vector<int> productExceptSelfBruteApproach(vector<int> & numbers){
    int num = numbers.size();

    vector<int> answer(num,1); 

    for(int i =0; i<num; i++){
        for(int j=0; j<num; j++){
            if(i!=j){
                answer[i] *= numbers[j];
            }
        }
    }
        return answer;
}
// Calculating Product of Array Except Selected Index's value ... in O(N)..using constant space 
vector<int> productExceptSelfOptimalApproach(vector<int> & numbers){

    int n = numbers.size(); 
        vector<int> answer(n,1);

        for(int i =1; i<n; i++){
            answer[i] = answer[i-1]*numbers[i-1];
        }
        int suffix =1; 
        for(int i =n-2; i>=0; i--){
            suffix *= numbers[i+1];
            answer[i] *= suffix;
        }
        return answer;
}
 
void printResult(vector<int> & result){
    for(int i =0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
int main(){
    vector<int> numbers={1,2,3,4};

    //vector<int> result = productExceptSelfBruteApproach(numbers);

    //printResult(result);

    vector<int> result = productExceptSelfOptimalApproach(numbers);

    printResult(result);


    return 0; 
}