#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>arr;

vector<int>Solution(vector<int>&arr,int n){
    unordered_map<int,int>my_map;
    int sum=0;
    int _start=-1,_end=-1,_len=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        if (sum==0){ưaý
            _start=-1;
            _end=i;
            _len=_end-_start;
        }
        else if (my_map.find(sum)!=my_map.end()){
            if ((i-my_map[sum])>_len){
                _start=my_map[sum];
                _end=i;
                _len=_end-_start;
            }
        }
        else my_map[sum]=i;
    }
    vector<int>save;
    _start+=1;
    for (;_start<=_end;_start++) save.push_back(arr[_start]);
    return save;


}

int main(){
    cin >> n;
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        arr.emplace_back(x);
    }

    vector<int>result=Solution(arr,n);
    for (auto x:result) cout << x << " ";



    return 0;
}
