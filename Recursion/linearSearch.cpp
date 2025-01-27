#include <iostream> 
using namespace std; 
bool linearSearch(int *arr, int size, int key){
    if(size==0) return false; 

    if(arr[0] == key) return true; 

    return linearSearch(arr+1, size-1, key); 
}

int main(){


    int const size = 5; 
    int arr[5] = {2,3,4,5,6}; 

    if(linearSearch(arr,size, 10))
        cout<<endl<<endl<<"Present: "<<endl<<endl;
    else
        cout<<endl<<endl<<"Absent: "<<endl<<endl;
    

    return 0; 

}