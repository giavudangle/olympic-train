#include <bits/stdc++.h>
using namespace std;
long long a,n;
int k;


long long PowerRecursion(long long a,long long n){
    if (n==0) return 1;
    if (n%2==0) return PowerRecursion(a,n/2)*PowerRecursion(a,n/2);
    return PowerRecursion(a,(n-1)/2)*PowerRecursion(a,(n-1)/2)*a;


}


long long Mod(string s,long long b){
    long long r=0;

    for(int i=0;i<s.size();i++){
        int so=s[i]-48;
        r=(r*10+so)%b;
    }
    return r;
}



int main(){

    cin >> a >> n >> k ;
    long long test=PowerRecursion(a,n);
    string s=to_string(test);
    long long b=PowerRecursion(10,k);
    cout << Mod(s,b);

    return 0;
}
