// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int cs=0;
        vector<int> ps(n);
        int k=0;
        ps[k++] = arr[0];
        if(arr[0]==0) return true;
        for(int i=1;i<n;i++){
            if(arr[i]==0) return true;
            cs += arr[i];
            ps[k] = arr[i-1]+arr[i];
            k++;
            if(cs==0) return true;
        }
        if(cs!=0){
            for(int i=0;i<ps.size()-1;i++){
                cout<<ps[i]<<" ";
                if(ps[i]+ps[i+1] == 0) return true;
            }
            cout<<ps[ps.size()-1];
        }
        return false;
    }
};

// { Driver Code Starts.11
// Driver code
int main()
{
	int t = 1;
	// cin>>t;
	while(t--)
	{
	    int n = 5;
	    // cin>>n;
	    int arr[n] = {-2,1,1,5,6};
	    // for(int i=0;i<n;i++)
	    // cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends