#include <bits/stdc++.h>

using namespace std;

#define el "\n"

void Solve()
{
    vector<int> ds;
    int n, tam, tongvtc = 0, tongvtl = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>tam;
        ds.push_back(tam);
        if(i % 2 == 0)
            tongvtc += tam;
        else
            tongvtl += tam;
    }
    //cout<<tongvtc<<" "<<tongvtl<<el;

    tam = 1;
    int i = 0, j = n - 1, ans = 0, vt;
    while(i < j)
    {
        if(i % 2 == j % 2)
        {
            if(ds[i] > ds[j])
            {
                vt = i;
                i++;
                cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" bi dong"<<el;
            }
            else
            {
                vt = j;
                j--;
                cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" bi dong"<<el;
            }
            if(vt % 2 == 0)
                tongvtc -= ds[vt];
            else
                tongvtl -= ds[vt];
            ans += tam * ds[vt];
            tam *= -1;
        }
        else
        {
            if(tongvtc > tongvtl)
            {
                if(i % 2 == 0)
                {
                    vt = i;
                    i++;
                    cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" chu dong"<<el;
                }
                else
                {
                    vt = j;
                    j--;
                    cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" chu dong"<<el;
                }
                tongvtc -= ds[vt];
                ans += tam * ds[vt];
                tam *= -1;
            }
            else
            {
                if(i % 2 == 1)
                {
                    vt = i;
                    i++;
                    cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" chu dong"<<el;
                }
                else
                {
                    vt = j;
                    j--;
                    cout<<"vt: "<<vt<<" tongchan: "<<tongvtc<<" tongle: "<<tongvtl<<" giatri: "<<tam * ds[vt]<<" chu dong"<<el;
                }
                tongvtl -= ds[vt];
                ans += tam * ds[vt];
                tam *= -1;
            }
        }
    }
    ans += tam * ds[i];
    cout<<ans<<el;
}

int main()
{
    Solve();
    return 0;
}
