#include <bits/stdc++.h>
using namespace std;
int n;
set<int> before;
set<int> after;
int main()
{
    freopen("CONGVAN.INP","r",stdin);
    freopen("CONGVAN.OUT","w",stdout);
    cin>>n;
    int a[n+10];
    for(int i = 1 ; i <= n; i++) cin>>a[i];

    int start[n+10];
    memset(start,0,sizeof(start));

    for(int i = 1 ; i <= n ; i++)
    {
        if(start[i] == 1) continue;
        else
        {
            before.insert(i);
            int go = i;
            int ads = a[i];
            bool flag=false;

            while(ads != go)
            {
                if(start[ads] == 1)
                {
                    flag = true;
                    break;
                }
                else
                {
                    start[ads] = 1;
                    before.insert(ads);
                    ads = a[ads];
                }
            }

            if(flag == false) after.insert(before.begin(),before.end());
            else if(flag == true)
            {
                for (set<int>::iterator it=before.begin(); it!=before.end(); ++it)
                    start[*it] = 0;
                before.clear();
            }
        }
    }
    for (set<int>::iterator it=after.begin(); it!=after.end(); ++it) cout<< *it<<" ";
    return 0;
}


