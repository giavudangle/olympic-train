#include <bits/stdc++.h>
using namespace std;

// kiem tra bit co dang 2^n hay k
// n& (n-1) ==0 -> 
void Nhan(int f[2][2],int m[2][2]){
    int a=f[0][0] * m[0][0] + f[0][1] * m[1][0];
    int b=f[0][0] * m[0][1] + f[0][1] * m[1][1];
    int c=f[1][0] * m[0][0] + f[1][1] * m[1][0];
    int d=f[1][0] * m[0][1] + f[1][1] * m[1][1];

    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}


void Power(int f[2][2],int n){      
    if(n==0 || n==1) return ;
    int m[2][2]={{1,1},{1,0}};

    Power(f,n/2);
    Nhan(f,f);

    if (n%2!=0) Nhan(f,m);
}

int fibo(int n){
    int f[2][2]={{1,1},{1,0}};
    if (n==0) return 0;
    Power(f,n-1);
    return f[0][0];
}

int main(){

    cout << fibo(8);


    return 0;
}





