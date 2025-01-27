#include <iostream> 
using namespace std; 

int factorial(int number){
    
    if(number == 1 || number == 0)
        return 1;
    
    return number * factorial(number-1);
}

int main(){

    int number = 5; 

    cout<<endl<<endl<<"Factorial of "<<number<<" = "<<factorial(number)<<endl<<endl;
    return 0; 
}