#include<bits/stdc++.h>

using namespace std;

string minNum(string s, int k){
    string result = "";
    int d = 0;
    while(s[d] == '0') d++;
    k = k-d;
    for(int i=d;i<s.length();i++){
        while(k>0 &&  (!(s[i] == '0' && result.length()==1) && result.length()>0) && result[result.length()-1] > s[i])
        {
        	// if(s[i] == '0' && result.length()==1) break;
            k--, result.pop_back();
        }
        result.push_back(s[i]);
    }
    return result.erase(result.length()-k,k);
}

int main(){
    freopen("DEL_NUMBER.INP","r",stdin);
    freopen("DEL_NUMBER.OUT","w",stdout);
    string s;
    int k;
    cin >> s;
    cin >> k;
    cout<<minNum(s,k);
    return 0;
}
