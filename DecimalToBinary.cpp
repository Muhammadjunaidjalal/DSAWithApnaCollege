#include <iostream> 
using namespace std; 

int binaryToDecimal(int decimalNumber){
    
    int answer =0, power =1; 
    while(decimalNumber>0){

        int remainder = decimalNumber % 2;
        decimalNumber /= 2;
        answer+=(remainder*power);
        power*=10;
    }
    return answer;
}

int main(){
    int number = 100; 
    int binaryForm = binaryToDecimal(number);
    cout<<"Binary Form of "<<number<<" is = "<<binaryForm<<endl;

}