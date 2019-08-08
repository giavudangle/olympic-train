// Sàn nguyên tố trên đoạn L-R
#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
vector<int>let;
bitset<1000000+10> is_prime;

bitset<1000000+10> is_prime_1;
bitset<1000000+10> is_prime_2;



void Sieves(int n){
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

void LeftRight(int l,int r){
    int can=(int)sqrt(r);
    int j=0;
    int k=0;
    //is_prime.set();
    is_prime_1.set();
    is_prime_2.set();
    for (int i=2;i<=can;i++){
        if (is_prime_1[i]) {
            for (int j=i*i;j<=can;j+=i){
                is_prime_1[j]=false;

            }

            if (l%i==0) j=l;
            else {
                k=l % i;
                j=(l-k) + i;
            }

            for(;j<=r;j+=i){
                is_prime_2[j-l]=false;
            }
        }
    }
    for (int i=l;i<=r;i++){
        if (is_prime_2[i-l]) let.push_back(i);
    }
}

int main(){
    int l,r;
    LeftRight(10,150);
    for (auto x:let) cout << x << " ";


    return 0;
}
