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

ll LCS(string a,string b, int i, int j, vector<vi>memo){
    if(i>=a.length() or j>=b.length()) return 0;

    if(memo[i][j]!=0) return memo[i][j];

    if(a[i] == b[j]) return 1+LCS(a,b,i+1,j+1,memo);
    else {
        ll left = LCS(a,b,i+1,j,memo);
        ll right = LCS(a,b,i,j+1,memo);
        memo[i][j] = max(left,right);
        return memo[i][j];
    }
}

int main() {

    IOS;
    // string s1="abcdefghi",s2="ecfgi";
    string s1,s2;
    cin>>s1>>s2;
    vector<vi> memo(s1.length(), vi (s2.length(),0));
    pn(LCS(s1,s2,0,0,memo));
}