#include<bits/stdc++.h>
using namespace std;

int totalWaysToClimb(int n){

    if(n<0) return 0;
    if(n==0) return 1;

    return totalWaysToClimb(n-1) + totalWaysToClimb(n-2) + totalWaysToClimb(n-3);

}

int main() {
    int n = 5;
    cout<<totalWaysToClimb(n);
    return 0;
}