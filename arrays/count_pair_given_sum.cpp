// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int maxVal(int a[], int n){
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,a[i]);
        }
        return mx;
    }
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int sum=0,count=0;
        vector<int>T(maxVal(arr, n), 0);
        for(int i=0;i<n;i++){
            if(T[arr[i]]!=0){
                T[arr[i]]+=1;
                if(T[k-arr[i]]!=0){
                    count+=T[arr[i]];
                }
            }else {
                T[arr[i]] = 1;
                sum+=arr[i];
                if(sum==k){
                    count++;
                    sum=0;
                } else if(sum>k) sum=0;
                else continue;
            }

        }
        return count;
    }
};

// { Driver Code Starts.

int main() {

    int n=4, k=2;
    int arr[n] = {1,1,1,1};
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
    
    return 0;
}  // } Driver Code Ends