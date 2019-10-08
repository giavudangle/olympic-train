    #include <bits/stdc++.h>
    using namespace std;
    // Parse A -> Decimal = *
    // Parse (*) -> B
    int ParseToDecimal(string d,int b){
        int n=0;
        int temp=1;

        for (int i=d.length()-1;i>=0;i--){
            n+=(d[i]-'0')*temp;
            temp*=b;
        }
        return n;
    }


    string ParseToB(int n,int b){
        string temp="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans="";
        while(n>0){
            int d=n%b;
            n/=b;
            ans+=temp[d];
        }
        string con=ans;
        reverse(con.begin(),con.end());
        if (b==2) return con;
        return ans;
    }




    int main(){
        int decimal=ParseToDecimal("1010",2);
        cout << ParseToB(decimal,2);

        return 0;
    }
