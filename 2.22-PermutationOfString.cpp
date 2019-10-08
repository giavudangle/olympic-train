#include <bits/stdc++.h>
using namespace std;
set<string>check;

void Permutation(string s,int l,int r){
//    if (l==r) cout << s << endl;
    if (l==r) check.insert(s);
    else {
        for (int i=l;i<=r;i++){
                swap(s[l],s[i]);
                Permutation(s,l+1,r);
                swap(s[l],s[i]);
        }
    }
}

int main(){
    string s="aba";
    int n=s.length();
    Permutation(s,0,n-1);

    for (auto itr=check.begin();itr!=check.end();++itr){
        cout << *itr << endl;
    }
    return 0;
}
