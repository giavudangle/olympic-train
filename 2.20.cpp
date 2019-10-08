#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>Left;
vector<int>Right;


string ConvertToTrinary(int n){
  string temp="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string ans="";
  while(n>0){
    int d=n%3;
    n/=3;
    ans+=temp[d];
  }
  return ans;
}


void Solve(string s){
  s=s+'0';
  for (int i=0;i<s.size();i++){
     if (s[i]=='1') Left.push_back(i);
     if (s[i]=='2'){
        Right.push_back(i);
        s[i+1]++;
     }
     if (s[i]=='3') s[i+1]++;
  }
}

string DivMod(string solon) {
  string thuong;
  string temp="";
    int du;

  thuong = "";
  du = 0;
  for (int i=0; i<solon.length(); i++) {
    int a = solon[i]-48;
    du = du*10 + a;
    thuong += char(du/3 + 48);

    du = du % 3;
  }
  while (thuong[0]=='0' && thuong.length()>1) thuong.erase(0, 1);
  return thuong;
}

int main(){

    cout << DivMod("11");


    return 0;
}



