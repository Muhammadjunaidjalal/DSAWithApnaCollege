#include <iostream> 
using namespace std; 
void sayDigit(int number, string arr[]){
    if(number==0){
        return; 
    }

    int digit = number%10; 
    number /= 10; 
    sayDigit(number, arr); 
    cout<<arr[digit]<<" ";
}


int main(){
    string arr[] = {"zero", "one", "two","three", "four", "five", "six", "seven", "eight", "nine"};
    int number; 

    cout<<endl<<endl; 
    cin>>number; 

    cout<<endl;
    sayDigit(number, arr);
    cout<<endl;

    return 0; 
}