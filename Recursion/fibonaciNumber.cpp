#include <iostream> 
using namespace std; 

int fibonaci(int n){
    if(n<=1)
        return n;
    return fibonaci(n-1) + fibonaci(n-2);
}
void printFibonaci(int n){
    for(int i = 0; i<n; i++){
        cout<<fibonaci(i)<<" "; 
    }
    cout<<endl;
}

int main(){
    printFibonaci(10);
    return 0; 
}


