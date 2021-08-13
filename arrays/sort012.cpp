/**
 * Time   - O(n)
 * Space  - O(1)
 * Author - 24Cipher
*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    void swap(int &x, int &y){
        int a = x;
        x = y;
        y = a;
    }
    void sort012(int arr[], int n)
    {
        // coode here
        int z=0,o=0,t=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) z++;
            else if(arr[i]==1) o++;
            else t++;
        }
        int j=0;
        while(z--){
            arr[j]=0;
            j++;
        }
        while(o--){
            arr[j]=1;
            j++;
        }
        while(t--){
            arr[j]=2;
            j++;
        }
        
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends