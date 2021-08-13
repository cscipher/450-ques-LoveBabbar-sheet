#include<bits/stdc++.h>
using namespace std;

// solved by head recursion ( o/p will be reversed if tail recursion used )
void spellPrint(int n){
    static vector<string> str {"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n==0) return ;        
    spellPrint(n/10);
    cout<<str[n%10]<<" ";
}

int main() {

    spellPrint(2130);
    return 0;
}   