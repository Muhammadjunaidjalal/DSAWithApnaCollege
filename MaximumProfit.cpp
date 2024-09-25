#include <iostream> 
#include <vector> 
using namespace std; 

int maximumProfit(vector<int> &prices){
    int maximumProfit = 0, bestBuy = prices[0];

    for(int i =0; i<prices.size(); i++){
        if(prices[i]>bestBuy){
            maximumProfit = max(maximumProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maximumProfit;
}

int main(){
    vector<int> prices={65,3,8,3,10,9};

    int result = maximumProfit(prices);

    cout<<"Maximum Profit Will Be : "<<result<<endl;


    return 0; 
}