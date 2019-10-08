 // Cong hai so lon
 // So sanh 2 so A va so lom

 #include <bits/stdc++.h>
 using namespace std;

 string AddingBigBum(string s1,string s2){
    if (s1.length()>s2.length()) swap(s1,s2);

    string temp="";

    int len1=s1.length();
    int len2=s2.length();

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());


    int carry=0;
    for (int i=0;i<len1;i++){
        int sum=( (s1[i]-'0') + (s2[i]-'0') + carry );
        temp.push_back(sum%10+'0');
        carry=sum/10;
    }

    for (int i=len1;i<len2;i++){
        int sum=((s2[i] - '0') + carry);
        temp.push_back(sum%10 + '0');
        carry=sum/10;
    }

    if (carry) temp.push_back(carry+'0');
    reverse(temp.begin(),temp.end());

    return temp;
 }

int CountFibonacci(string a ,string b){
    string f1="0",f2="0",f3="1";
    int res=0;

    while(f1<b){
        if (f1>=a) res++;
        f1=f2;
        f2=f3;
        f3=AddingBigBum(f1,f2);
    }
    return res;
}



 int main(){
    cout << CountFibonacci("1","10");

    return 0;
 }
