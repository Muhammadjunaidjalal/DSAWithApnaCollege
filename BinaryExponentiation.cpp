#include <iostream> 
using namespace std; 

//Function to Calculate Power Of Any Number Using Binary Exponentiation ....in O(logN)
double calculatePowerOfNumber(double number, int power) {
    //Corner Cases (Code will run without them as well)
        if(power==0 ) return 1.0; 
        if(number==0) return 0.0; 
        if(number == 1) return 1.0;
        if(number == -1 && power%2 == 0) return 1.0; 
        if(number == -1 && power%2 !=0) return -1.0;

        long binaryForm = power; 
        if(power<0){
            number=1/number;
            binaryForm = -binaryForm; 
        }
        double ans = 1; 

        while(binaryForm>0){
            if(binaryForm %2 ==1){
                ans *=number;
            }
            number*=number;
            binaryForm/=2;
        }
        return ans;
        
}

int main(){
    double number = 5.0;
    int power = 5; 

    double result =calculatePowerOfNumber(number,power);
    cout<<"Result of "<<number<<"^"<<power<<" is = "<<result<<endl; 
    
    return 0;
}