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


bool canSum(ll t, vll nums, unordered_map<int,bool> hash){

    if(t==0) return true;
    if(t<0) return false;
    if(hash[t]==true) return hash[t];

    for(auto n : nums){
        ll rem = t - n;
        if(canSum(rem,nums,hash)) {
            hash[t]=true;
            return true;
        }
    }

    return false;
}

int main() {

    IOS;
    cout<<canSum(300,{7,14},{});
}