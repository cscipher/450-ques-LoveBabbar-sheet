#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        pair<int,int> buy(0,INT_MAX), sell(0,INT_MIN);

        for(int i=0;i<prices.size();i++){
            if(i==0){
                buy.first=0;sell.first=0;
            }
            if(prices[i] < buy.second) {
                buy.first = i;
                buy.second = prices[i];
            }
            if(prices[i] > sell.second){
                sell.second = prices[i];
                sell.first = i;
            } else if(prices[i] < sell.second && buy.first > sell.first){
                sell.first = i;
                sell.second = prices[i];
            }
            p = max(p,sell.second-buy.second);
        }
        return max(p,0);
    }
};

int main() {
    Solution s = Solution();
    vector<int>k {7,6,4,3,1};
    cout<<s.maxProfit(k)<<endl;
}


/**
 * wa
 * int maxProfit(vector<int>& prices) {
        int p = 0,n=prices.size();
        int buy=INT_MAX,sell=INT_MIN;
        int i=0,j=n-1;
        
        while(i<=j){
            if(prices[i]<buy) buy=prices[i];
            if(prices[j]>sell) sell = prices[j];
            p = max(p,sell-buy);
            i++;j--;
        }
        return max(0,p);
    }
*/