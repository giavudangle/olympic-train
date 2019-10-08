#include <bits/stdc++.h>
using namespace std;

int n,range = 9999999,save = 0;
int check[200000];

set <int> bagOne,bagTwo;
set <int> :: iterator it;

int main()
{
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int candy[n];

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        candy[i] = tmp;
        sum += tmp;
    }
    int found = sum/2;

    bagOne.insert(candy[0]);
    for(int i = 1; i < n; i++)
    {
        for(it = bagOne.begin(); it != bagOne.end(); it++)
        {
            int kq = candy[i] + *it;
            if(check[kq] != 1)
            {
                bagTwo.insert(kq);
                check[kq] = 1;
            }
        }
        bagOne.insert(bagTwo.begin(),bagTwo.end());
        if(check[candy[i]] != 1)
        {
            bagOne.insert(candy[i]);
            check[candy[i]] = 1;
        }
    }

    for(it = bagOne.begin(); it != bagOne.end(); it++)
    {
        if(range >= abs(found - *it))
        {
            range = abs(found - *it);
            save = *it;
        }
    }
    cout<<abs(sum - 2*save);
    return 0;
}
