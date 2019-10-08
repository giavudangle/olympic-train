#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("ChiaKeo.INP","r",stdin);
    //freopen("ChiaKeo.OUT","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int candy[n];
    int dau[200000];

    set <int> candyBagX;
    set <int> candyBagY;
    set <int> :: iterator it;

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        candy[i] = tmp;
        sum += tmp;
    }

    int findd = sum/2;

    candyBagX.insert(candy[0]);
    for(int i = 1; i < n; i++)
    {
        for(it = candyBagX.begin(); it != candyBagX.end(); it++)
        {
            int kq = candy[i] + *it;
            if(dau[kq] != 1)
            {
                candyBagY.insert(kq);
                dau[kq] = 1;
            }
        }
        candyBagX.insert(candyBagY.begin(),candyBagY.end());
        if(dau[candy[i]] != 1)
        {
            candyBagX.insert(candy[i]);
            dau[candy[i]] = 1;
        }
    }

    int minn = 9999999;
    int luu = 0;


    for(it = candyBagX.begin(); it != candyBagX.end(); it++)
    {
        if(minn >= abs(findd - *it))
        {
            minn = abs(findd - *it);
            luu = *it;
        }
    }
    cout<<abs(sum - 2*luu);
    return 0;
}
