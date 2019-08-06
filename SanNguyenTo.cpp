#include <bits/stdc++.h>
using namespace std;
int n;
bitset<1000000+10>is_prime;
vector<int>primes;

void Sieves(int n){
    is_prime.set();
    is_prime[0]=is_prime[1]=false;

    for ( int i=2;i*i<=n;i++){
        if (is_prime[i]){
            for (int j=i*i;j<=n;j+=i){
                if (is_prime[j]) is_prime[j]=false;
            }
        }
    }

    for (int i=2;i<=n;i++){
        if (is_prime[i]) primes.push_back(i);
    }

}

int main(){

    Sieves(1000000);

    for (int x : primes) cout << x << " ";



    return 0;
}
