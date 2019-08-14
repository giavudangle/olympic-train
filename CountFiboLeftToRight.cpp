
 // Cong hai so lon
 // So sanh 2 so A va so lom

 #include <bits/stdc++.h>
#include <stdlib.h>
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

int Compare(string x,string y){
  int ans=x.length()-y.length();

  int temp=abs(ans);
    //cout << "TEMSSSS: " << temp << endl;
   if (x.length()<y.length())
     x.insert(0,temp,'0');
   else if (x.length()>y.length())
     y.insert(0,temp,'0');

    // ~~
    //cout << x << endl << y;
    if (x==y) return 0;
    if (x>y) return 1;
    if (x<y) return -1;

}


int CountFibonacci(string a ,string b){
    string f1="0",f2="0",f3="1";
    int res=0;

    while(Compare(f1,b)<0 || Compare(f1,b)==0){
        if (Compare(f1,a)==0 || Compare(f1,a)==1) res++;
        f1=f2;
        f2=f3;
        f3=AddingBigBum(f1,f3);
    }
    return res;
}



 int main(){
    //cout << CountFibonacci("1","10");
    //cout << Compare("12","2");
    //cout << abs(-3) << endl;

    //Compare("12","14041");

    cout << CountFibonacci("1","1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    return 0;
 }
