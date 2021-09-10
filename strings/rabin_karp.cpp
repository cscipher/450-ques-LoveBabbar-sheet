#include<bits/stdc++.h>
#define ll long long int
#define prime 119
using namespace std;

ll RollingHash(string s, int n){  // O(s.length())
    ll result = 0;
    for(int i=0;i<n;i++){
        result += (ll)(s[i]*(ll)(pow(prime,i)));
    }
    return result;
}

ll recalculateHash(string s, int oldIndex, int newIndex, ll oldHash, int patLen){   // O(1)
    ll newHash = oldHash - s[oldIndex];
    newHash /= prime;
    newHash += (ll)(s[newIndex]*(ll)(pow(prime,patLen-1)));
    return newHash;
}

bool checkIfEqual(string s1, string s2, int start1, int start2, int end1, int end2){  // O(pat.length())
    if(end1-start1 == end2-start2) return false;
    while(start1<=end1 and start2<= end2){
        if(s1[start1]!=s2[start2]) return false;
        start1++;start2++;
    }
    return true;
}

int RabinKarpSearch(string text, string pat){
    int pl = pat.length();
    int tl = text.length();
    ll patHash = RollingHash(pat, pl);
    ll txtHash = RollingHash(text,pl);

    for(int i=0;i<=(tl-pl);i++){
        if(patHash == txtHash and checkIfEqual(text, pat, i,0,i+pl-1,pl-1)) return i;
        if(i < tl-pl) 
            txtHash = recalculateHash(text,i,i+pl,txtHash,pl);
    }
    return -1;

}

int main() {

    string text = "ababcabdab";//"ababcabcabababd";
    string pattern = "abd";//"ababd";
    cout<<RabinKarpSearch(text,pattern);
    // int ans = RabinKarpSearch(text,pattern);
    // ans==-1 ? cout<<"Not match"<<endl : cout<<"Search success at index : "<<ans<<endl;

    return 0;
}