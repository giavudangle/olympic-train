#include <bits/stdc++.h>
using namespace std;

int Compare(string x,string y){
    int temp=x.length()-y.length();
    int ans=abs(temp);

    if (x.length()>y.length())
        y.insert(0,ans,'0');
    else
        x.insert(0,ans,'0');

    if (x==y) return 0;
    if (x>y) return 1;
    if (x<y) return -1;
}


string AddBigNum(string s1,string s2){
    if (s1.length()>s2.length()) swap(s1,s2);

    string temp="";
    int len1=s1.length();
    int len2=s2.length();
    int carry=0;

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    for (int i=0;i<len1;i++){
        int sum=( (s1[i]-'0')+ (s2[i]-'0') + carry );
        temp.push_back(sum%10+'0');
        carry=sum/10;
    }

    for (int i=len1;i<len2;i++){
        int sum=( (s2[i]-'0') + carry );
        temp.push_back(sum%10+'0');
        carry=sum/10;
    }

    if (carry) temp.push_back(carry+'0');
    reverse(temp.begin(),temp.end());

    return temp;
}

string DivisionBigNum(string number,int divisor){
    string ans;
    int idx=0;
    int temp=number[idx] - '0';

    while(temp<divisor)
        temp=temp*10 + (number[++idx] - '0');

    while (number.size()>idx){
        ans+=(char)(temp/divisor+'0');
        temp=(temp%divisor)*10 + number[++idx] - '0';
    }

    if (ans.length()==0) return 0;

    return ans;
}

string MultipliesBigNum(string num1,string num2){
    int len1=num1.size();
    int len2=num2.size();

    if (len1 == 0 || len2 == 0 )
        return "0";

    vector<int>result(len1+len2,0);

    int i_n1=0;
    int i_n2=0;

    for (int i=len1-1;i>=0;i--){
        int carry=0;
        int n1=num1[i] -'0';

        i_n2=0;

        for (int j=len2-1;j>=0;j--){
            int n2=num2[j] - '0';
            int sum=n1*n2 + result[i_n1+i_n2] + carry;

            carry=sum/10;

            result[i_n1+i_n2]=sum%10;
            i_n2++;
        }

        if (carry>0)
            result[i_n1+i_n2]+=carry;

        i_n1++;
    }

    int i=result.size() - 1;
    while(i>=0 && result[i]==0) i--;

    if (i==-1) return "0";

    string s="";

    while (i>=0) s+=to_string(result[i--]);
    return s;
}

bool isSmaller(string s1,string s2){
    int n1=s1.length(),n2=s2.length();

    if (n1<n2)
        return true;
    if (n2>n1)
        return false;

    for (int i=0;i<n1;i++){
        if (s1[i]<s2[i])
            return true;
        else if (s1[i]>s2[i])
            return false;
    }
    return false;
}

string MinusBigNum(string s1,string s2){
    if (Compare(s1,s2)==-1)
        swap(s1,s2);

    string str="";

    int n1=s1.length(),n2=s2.length();
    int diff=n1-n2;

    int carry=0;

    for (int i=n2-1;i>=0;i--){
        int sub=( (s1[i+diff]-'0') - (s2[i]-'0') - carry );
        if (sub<0){
            sub+=10;
            carry=1;
        }
        else
            carry=0;
        str.push_back(sub+'0');
    }

    for (int i=n1-n2-1;i>=0;i--){
        if (s1[i]=='0'&& carry){
            str.push_back('9');
            continue;
        }

        int sub=((s1[i]-'0') - carry);
        if (i>0 || sub>0)
            str.push_back(sub+'0');
        carry=0;
    }
    reverse(str.begin(),str.end());
    return str;

}



 // 1 8
bool BinaryCheckIsSquare(string n)
{
        string l="1";
        string r=n;

        while (Compare(l,r)== -1 || Compare(l,r)==0)
        {

            string sum=AddBigNum(l,r);
            string chia=DivisionBigNum(sum,2);
            string pivot="";
            pivot=MultipliesBigNum(chia,chia);
            if (pivot==n)
                return true;
            else if (Compare(pivot,n)==-1){
                l=AddBigNum(chia,"1");
            }

            else{
                     r=MinusBigNum(chia,"1");

            }

        }

    return false;
}



int main(){
   // cout << AddBigNum("144","88888888") << endl;
//    cout << MinusBigNum("999999999","111111") << endl;
    //cout << MultipliesBigNum("144","144");
    //cout << DivisionBigNum("145",2);

//
    bool flag=BinaryCheckIsSquare("144");
        if (flag) cout << "OK" ;
        else cout << "NO";

    return 0;
}
