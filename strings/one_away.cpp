#include<bits/stdc++.h>
using namespace std;

bool OneAway(string a, string b){
    int x = a.length()-b.length();
    if(a.length() == b.length()){
        int count = 0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) {
                count++;
                if(count>1) return false;
            }
        }
        if(count == 1)return true;
        else return false;
    } else if(abs(x)==1) return true;
    else return false;   
}


int main() {

    string a="pale",b="bae";
    cout<<OneAway(a,b);

    return 0;
}