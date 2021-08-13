#include<bits/stdc++.h>
using namespace std;

void printPowerSets(vector<int> arr, vector<int>& curr, int i){
    if(i>=arr.size()) {
        for(auto it:curr) cout<<it<<" ";
        cout<<endl;
        return;
    }

    // not choosen
    printPowerSets(arr,curr,i+1);
    
    // choosen
    curr.push_back(arr[i]);
    printPowerSets(arr,curr,i+1);
}

int main() {

    vector<int> arr {1,2,3};
    vector<int> curr {};
    printPowerSets(arr, curr, 0);

    return 0;
}