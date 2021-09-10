#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, int> mci;

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define Rloop(i,a,n) for(ll i=n-1;i>=a;i--)
#define pb push_back
#define first F
#define mp make_pair
#define second S
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define PI 3.1415926535897932384626433832795
#define MOD 1e5+7
#define pn(a) cout<<a<<endl
#define pc(a) cout<<a<<" "

vll getGreaterElement(vll arr,int n){
    vll res;
    stack<ll> st;
    st.push(arr[0]);
    loop(i,1,n){
        if(st.empty()) st.push(arr[i]);

        while (!st.empty()&& st.top() < arr[i]) {
            res.pb(arr[i]);
            st.pop();
        }
        st.push(arr[i]);
    }
    while (!st.empty()) {
        res.pb(-1);
        st.pop();
    }
    return res;
}

int main() {

    IOS;
    vll given = {6,8,0,1,3}, ans;
    ans = getGreaterElement(given, given.size());
    for(auto it:ans) pc(it);
}