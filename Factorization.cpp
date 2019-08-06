#include <bits/stdc++.h>
using namespace std;
bitset<1000000+10> is_prime;
vector<int> primes;
vector<int> factors;
int n;


int Sieves(int n){
    is_prime.set();
    is_prime[0]=is_prime[1]=false;

    for (int i=2;i*i<=n;i++){
        if (is_prime[i])
            for (int j=i*i;j<=n;j+=i)
                is_prime[j]=false;

    }

    for (int i=2;i<=n;i++){
        if (is_prime[i]) primes.push_back(i);
    }
}






void Factorization(int n){
    int sqrt_n=(int)sqrt(n);
    Sieves(sqrt_n);

    int p=primes[0];
    int k=0;

    while(p*p<=n){
        while(n%p==0){
            factors.push_back(p);
            n/=p;
        }
        if (k>=primes.size()) break;
        p=primes[++k];
    }

    if (n>1) factors.push_back(n);
}




int main(){



    Sieves(10000);
    Factorization(123);


    sort(factors.begin(),factors.end());

    // Đếm số ước của N & tính tổng
    int c=0;
    int sum=0;
    for (int i=0;i<factors.size();i++){
        if (factors[i]!=factors[i+1]) c++;
        sum+=factors[i];
    }

    // Xuất

    for (auto x : factors) cout << x << " ";


    return 0;
}
