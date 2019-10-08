#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long>born={0,1};
long func(){
    long count=1,temp=1,tempSize=1;
    while (temp % n !=0){
        count*=10;
        tempSize=born.size();
        for (long i=0;i<tempSize;i++){
            born.emplace_back(count+born[i]);
            temp=born[tempSize+i];
            if (temp%n==0) return temp;
        }
    }
    return temp;
}

int main(){
    //freopen("SO01.INP","r",stdin);
    //freopen("SO01.OUT","w",stdout);
    cin >> n;
    cout << func();

    return 0;
}

