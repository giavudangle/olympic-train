#include <bits/stdc++.h>
using namespace std;



// Mod BigNum
long long Mod(string a,long long b){
    long long r=0;

    for (int i=0;i<a.size();i++){
        int so=a[i] - 48;
        r=(r*10+so)%b;
    }
    return r;
}

// Bitwise Mu
long long Power(long long a,long long n){
    // n&(1<<i) dich n sang trai bich thu i
    long long ans=1;
    while(n>0){
        if(n&1==1) ans=ans*a;
        a=a*a;
        n=n>>1;
    }
    return ans;
}

long long PowerRecursion(long long a,long long n){
    if (n==0) return 1;
    if (n%2==0) return PowerRecursion(a,n/2)*PowerRecursion(a,n/2);
    return a*PowerRecursion(a,(n-1)/2)*PowerRecursion(a,(n-1)/2);
}




int main(){
    //cout << Power(2,50);
    //cout << Mod("11",3);
    //cout << PowerRecursion(2,10);
    return 0;
}
