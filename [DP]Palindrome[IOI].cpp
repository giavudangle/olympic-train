#include <bits/stdc++.h>
using namespace std;
string s1;

int Dynamic(string s1,string s2){
    int len1=s1.length();
    int len2=s2.length();
    int i,j;

    int f[len1+1][len2+1];

    for (i=0;i<=len1;i++)
        f[i][0]=0;
    for (j=0;j<=len2;j++)
        f[0][j]=0;

    for (i=1;i<=len1;i++){
        for (j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1])
                f[i][j]=1+f[i-1][j-1];
            else
                f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    return f[len1][len2];
}



int main(){
    //freopen("Palindrome.INP","r",stdin);
    //freopen("Palindrome.OUT","w",stdout);

    cin >> s1;

    string s2=s1;
    reverse(s2.begin(),s2.end());
    cout << s1.length()-Dynamic(s1,s2);


    return 0;
}
