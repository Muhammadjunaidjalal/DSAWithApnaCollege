#include <iostream> 
using namespace std;

int binaryToDecimal(int number){
    int answer =0, power =1; 

    while(number>0){
        int remainder = number %10;
        number/=10; 
        answer+=(remainder*power);
        power*=2;

    }
    return answer;
}

int main(){

    int number = 1100100; //100
    int decimalForm = binaryToDecimal(number);

    cout<<"Decimal Form of "<<number<<" is = "<<decimalForm<<endl;

    return 0;
}