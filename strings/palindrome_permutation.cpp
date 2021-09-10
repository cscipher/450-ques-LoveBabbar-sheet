#include<bits/stdc++.h>
using namespace std;

bool PalindromePerm(string s){
    unordered_map<char,int> count;
    for(auto e : s){
        if(e == ' ') continue;
        count[e]++;
    }
    bool center = false;
    int ans=0;
    for(auto entry : count){
        if(entry.second %2 != 0) {
            ans ++;
            if (ans > 1) return false;
        }
    }
    return true;
}

int main() {

    string s = "geeksrorgeeks";
    cout<<PalindromePerm(s);

    return 0;
}