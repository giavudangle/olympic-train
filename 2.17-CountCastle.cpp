#include <bits/stdc++.h>
using namespace std;
int n,k;



int Factor(int n){
    if (n==0) return 1;
    return n*Factor(n-1);
}

int Castle(int n,int k){
    if (n<k) return 0;
    if (n==k) return Factor(n)/Factor(n-k);
    return (Factor(n)/Factor(n-k))*Factor(k);

}



int main(){

    //int a[100+10][100+10];

    cin >> n >> k;

    cout << Castle(n,k);



    return 0;
}
