#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("1.inp","r+",stdin);
	freopen("1.out", "w+", stdout);
    map<int, int> flag;
    int n, k;
    int mod = 0;
    int a[100000];
    int _begin = 0, _end = 0;

    cin >> n >> k;
    flag[0] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        mod = (mod + a[i]) % k;
        if((mod != 0 && flag[mod] != 0 && _end - _begin < i - flag[mod] - (mod  ? 1 : 0))
           || (mod == 0))
        {
            _begin = flag[mod] + (mod ? 1 : 0);
            _end = i;
        }
        else
            flag[mod] = i;
    }
    cout << _end - _begin + 1 << endl;

    for(int i = _begin; i <= _end; i++)
        cout << a[i] << " ";

    return 0;
}
