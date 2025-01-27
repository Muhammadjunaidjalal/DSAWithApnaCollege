#include <iostream> 
using namespace std; 

void reverseString(string &str, int left, int right){

    if(left>right)
        return; 
    
    swap(str[left], str[right]);

    reverseString(str, left+1, right-1);
}

int main(){
    string str = "Junaid"; 
    cout<<endl<<endl<<"BEFORE REVERSING: "<<str<<endl;

    reverseString(str, 0,str.length()-1); 

    cout<<endl<<"AFTER REVERSING: "<<str<<endl<<endl;
    
    return 0;
}