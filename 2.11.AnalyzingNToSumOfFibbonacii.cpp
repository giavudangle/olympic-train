#include <bits/stdc++.h>
using namespace std;
const long long _size=1e9;
vector<string>fibo;


string AddBigNum(string s1,string s2){
    if (s1.length()>s2.length()) swap(s1,s2);

    string res="";
    int len1=s1.length();
    int len2=s2.length();

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int carry=0;

    for (int i=0;i<len1;i++){
        int sum=((s1[i]-'0') + (s2[i]-'0')+ carry);
        res.push_back(sum%10+'0');
        carry=sum/10;
    }

    for (int i=len1;i<len2;i++){
        int sum=((s2[i]+'0') + carry);
        res.push_back(sum%10+ '0');
        carry=sum/10;
    }

    if (carry) res.push_back(carry+'0');

    reverse(res.begin(),res.end());

    return res;
}

int Compare(string a,string b){
    int temp=a.length()-b.length();
    int ans=abs(temp);

    if (a.length()>b.length())
        b.insert(0,ans,'0');
    else if (b.length()>a.length())
        a.insert(0,ans,'0');

    if (a==b) return 0;
    if (a<b) return 1;
    if (a>b) return -1;

}


int Fibonacci(string n){
    if (n=="0") return 0;
    vector<long long>gener;
    gener[0]=0;
    gener[1]=1;

    long long sum=gener[0]+gener[1];
    string c=to_string(sum);
    int i=2;
    while(Compare(c,n)==1 || Compare(c,n)==0){
        gener[i]=AddBigNum(gener[i-2],gener[i-1]);
        fibo.push_back(gener[i]);
    }
}

int main(){
    string n;

    return 0;
}
