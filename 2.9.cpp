#include <bits/stdc++.h>
using namespace std;
int n;

long long GCD(long long a,long long b){
    if (a%b==0) return b;
    return GCD(b,a%b);
}

long long  GCD_List(int a[],int n){
    int temp=a[0];
    for (int i=1;i<n;i++)
        temp=GCD(temp,a[i]);
    return temp;

}

long long LCM(long long a,long long b){
    return (a/GCD(a,b))*b;
}

long long LCM_List(int a[],int n){
    int temp=a[0];
    for (int i=1;i<n;i++)
        temp=LCM(temp,a[i]);
    return temp;

}


int main(){
    int a[]={100,25,15,10};
    cout << LCM_List(a,4);


    return 0;
}
