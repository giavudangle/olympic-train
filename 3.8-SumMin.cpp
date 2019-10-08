#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<int>ele;
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.emplace_back(x);
    }

    sort(arr.begin(),arr.end());
    int s=0;
    if (n%2!=0){
      //cout << "X: " << arr[n/2] << endl;

      for (int i=0;i<n;i++){
        s+=abs(arr[i]-arr[n/2]);
      }
    }
    else {
        for (int i=n/2-1;i<=n/2;i++){
            ele.emplace_back(i);
        }
    }
    //cout << "S: " << s;
    for (auto x:ele){
        cout << x << " ";
    }
    return 0;
}
