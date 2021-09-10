#include<bits/stdc++.h>
using namespace std;

bool checkPerm(string a, string b){
    unordered_map<char,int> mp;
    for(auto e:a) mp[e]++;
    for(auto e:b) if(mp.find(e) == mp.end()) return false;
    if(a.length()!=b.length()) return false;
    return true;
}

int main() {

    string s1="aabc",s2="bac";
    cout<<checkPerm(s1,s2);

    return 0;
}