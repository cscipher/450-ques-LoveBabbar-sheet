// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long l = 0, h = n - 1, mid = (0 + n - 1) / 2, count = 0;
        while (l <=h)
        {
            if (arr[mid] < arr[l])
            {
                swap(arr[mid], arr[l]);
                l++;
                count++;
            }
            else if (arr[mid] > arr[h])
            {
                swap(arr[mid], arr[h]);
                h--;
                count++;
            }
            else if (arr[l] > arr[h])
            {
                swap(arr[l], arr[h]);
                l++;
                h--;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    long long N = 5;
    // cin >> N;

    long long A[N] = {2, 4, 1, 3, 5};
    // for(long long i = 0;i<N;i++){
    //     cin >> A[i];
    // }
    Solution obj;
    cout << obj.inversionCount(A, N) << endl;
    return 0;
}
// } Driver Code Ends