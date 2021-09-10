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


bool prefixMatch(string a,string b){
    if(a.length() < b.length()) return false;
    int i=0,j=0;
    while(i<a.length() && j<b.length()){
        if(a[i]!=b[j]) return false;
        i--;j--;
    }
    return true;
}

ll CountConstruct(string target, vs wordbank, unordered_map<string,ll>memo={}){
    if(memo.find(target) == memo.end()) return memo[target];
    if(target.empty()) return 1;

    ll tc;
    for(auto x:wordbank){
        if(prefixMatch(target,x)) {
            string suffix = target.substr(x.length(),target.length());
            tc += CountConstruct(suffix,wordbank,memo);
        }
    }
    memo[target]=tc;
    return tc ;
}


int main() {

    IOS;
    cout<<CountConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeff",{"e","ee","eee","eeee","eeeeeeeeee"})<<endl;
    cout<<CountConstruct("abcdef",{"a","bc","cd","def","abcd"})<<endl;
}