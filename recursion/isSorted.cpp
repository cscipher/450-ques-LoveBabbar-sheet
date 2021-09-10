#include<bits/stdc++.h>
using namespace std;

bool isArrSorted(vector<int> arr, int index, int n){
    if(index>=n) return true; // Base case

    if(arr[index]>=arr[index-1]) return isArrSorted(arr,index+1,n);
    return false; // if no case matches
}

int main() {

    vector<int> arr {1,2,3,4,5};
    cout<<isArrSorted(arr, 1,arr.size());

    return 0;
}