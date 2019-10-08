#include <bits/stdc++.h>
using namespace std;

vector<int>Left;
vector<int>Right;



string Trans(int n){
    string temp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans = "";

    while(n>0){
        int d=n%3;
        n/=3;
        ans+=temp[d];
    }
  return ans;
}

string Quiz(string s){
    for (int i=0;i<s.size();i++){
        if (s[i]==1) Left.push_back(s[i]);
        if (s[i]==2){
            Right.push_back(s[i]);
        }
        if (s[i]==3) s[i+1]++;
    }
}


int main(){

    string test=Trans(11);
    cout <<test;
    Quiz(test);
    //cout<< test << endl;

    for (auto x:Left) cout << x << " ";


    return 0;
}
