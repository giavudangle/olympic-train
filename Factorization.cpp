#include <bits/stdc++.h>
using namespace std;
bitset<1000000+10>is_prime;
bitset<1000000+10>is_prime_1;
bitset<1000000+10>is_prime_2;

vector<int>primes;
vector<int>factors;
vector<long long>let;
int n;


void Sieves(int n){
    is_prime.set();
    is_prime[0]=is_prime[1]=false;

    for (int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for (int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    for (int i=2;i<=n;i++){
        if(is_prime[i]) primes.emplace_back(i);
    }
}


void Factorization(int n){
    int can=(int)sqrt(n);
    Sieves(can);

    int p=primes[0];
    int k=0;

    while(p*p<=n){
        while(n%p==0){
            factors.push_back(p);
            n/=p;
        }

        if (k>primes.size()) break;
        p=primes[k++];
    }

    if (n>1) factors.push_back(n);
}

void SievesLeftToRight(long long l,long long r){
    long long can=(long long)sqrt(r);
    int j=0;
    int k=0;

    is_prime_1.set();
    is_prime_2.set();

    for (int i=2;i<=can;i++){
        if(is_prime_1[i]){
            for (int j=i;j<=can;j+=i){
                is_prime_1[j]=false;
            }
            if (l%i==0) j=l;
            else {
                k=l%i;
                j= (l-k) + i;
            }

            for (;j<=r;j+=i){
                is_prime_2[j]=false;
            }
        }
    }

    for (int i=l;i<=r;i++){
        if (is_prime_2[i]) let.push_back(i);
    }



}


int main(){



}
