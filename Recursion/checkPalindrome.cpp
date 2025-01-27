#include <iostream> 
using namespace std; 

bool checkPalindrome(string &str, int left, int right){
    if(left>right)
        return false; 
    if(str[left]==str[right]) 
        return true;
    return checkPalindrome(str,left+1,right-1);  
    
}

int main(){
    string str = "civic"; 

    if(checkPalindrome(str,0,str.length()-1))
        cout<<endl<<endl<<"Palindrome: "<<endl<<endl;
    else 
        cout<<endl<<endl<<"Not Palindrome: "<<endl<<endl;

    return 0;
}