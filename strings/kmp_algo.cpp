// implementation of kmp algorithm

#include<bits/stdc++.h>
using namespace std;

void computePiTable(string pat, vector<int>&piT) {

    piT.push_back(0);
    int i = 1;
    int M = pat.length(),len=0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            piT[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = piT[len - 1];
            }
            else {
                piT[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string text,string pat) {
    vector<int> piT;
    computePiTable(pat,piT);
    int i=0,j=0;
    int n = text.length();
    int m = pat.length();
    while(i<n) {
        if(pat[j] == text[i]){
            i++;j++;
        }
        if(j == m) cout<<"Search success at index : "<<i-j<<endl;

        else if(i<n && pat[j] != text[i]) {
            if(j!=0) j = piT[j-1];
            else i++;
        }
    }
}

int main() {

    string text = "ababcabcabababd";
    string pattern = "ababd";

    kmpSearch(text,pattern);

    return 0;
}