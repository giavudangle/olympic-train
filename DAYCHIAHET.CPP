#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("DAYCHIAHET.INP","r",stdin);
    freopen("DAYCHIAHET.OUT","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int division[n];
    int axios[n];
    for (int i=0;i<n;i++) cin >> division[i];
    for (int i=0;i<n;i++) cin >> axios[i];

    for (int i=0;i<n;i++){
        set<int>save;
        int tracking[100000+10];
        memset(tracking,0,sizeof(tracking));

        int positive=axios[0]%division[i];
        int negative=(-axios[0]%division[i])+division[i];

        save.insert(positive);
        save.insert(negative);

        tracking[positive]=1;
        tracking[negative]=1;

        for (int j=1;j<n;j++){
            memset(tracking,0,sizeof(tracking));
            set<int>previous;
            for (set<int>::iterator it=save.begin();it!=save.end();++it){
                positive=(*it + axios[j])%division[i];
                negative=(*it-axios[j])%division[i];

                if (negative < 0) negative+=division[i];

                previous.insert(positive);
                previous.insert(negative);

                tracking[positive]=1;
                tracking[negative]=1;
            }
            save.clear();
            save.insert(previous.begin(),previous.end());
        }
        cout << (tracking[0]==1) ? "1" : "0";  cout << " ";
    }
return 0;

}
