#include <bits/stdc++.h>
using namespace std;

int findNumberOfZeros(int n){
    int temp=0;
    for(int i=5;n/i>=1;i*=5)
        temp+=n/i;
    return temp;
}

int main(){

    cout << findNumberOfZeros(10000000000);
}
