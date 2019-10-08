#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int>factorial;
vector<int>::const_iterator it;
long n;
int fac(){
    for (long i=2;i*i<=n;i++){
        while (n%i==0){
            factorial.push_back(i);
            n/=i;
        }
    }
    if (n!=1) factorial.push_back(n);
    return 0;
}

int main(){
    freopen("TIMSO.INP","r",stdin);
    freopen("TIMSO.OUT","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fac();
    it=max_element(factorial.begin(),factorial.end());
    cout << *it;
    return 0;
}

