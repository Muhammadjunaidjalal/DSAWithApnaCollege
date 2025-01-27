#include <iostream> 
using namespace std; 

int calculatePower(int base, int exponent){
    
    if(exponent == 0)
        return 0; 
    if(exponent == 1)
        return base; 
    
    int answer = calculatePower(base, exponent/2); 

    if(exponent%2 == 0)
        return answer*answer; 
    else
        return base*answer*answer;
}

int main(){

    int base = 2; 
    int exponent = 10; 

    cout<<endl<<base<<"^"<<exponent<<" = "<<calculatePower(base,exponent)<<endl<<endl; //1024

    return 0;
}