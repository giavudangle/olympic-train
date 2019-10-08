#include <bits/stdc++.h>
using namespace std;
set<char>filter;
int cnt[10000];
int f[1000];


int main() {
	 string s;
	 cin >> s;

	 int change;

     for (int i=0;i<10000;i++)
        cnt[i]=0;

	 for (int i=0;i<s.size();i++) {
        change=(int)s[i];
        cnt[change]++;
        filter.insert(s[i]);
	 }
	 int maxx=0;
	 for (int i=0;i<10000;i++){
        if (cnt[i]>cnt[maxx])
            maxx=i;
	 }

     cout <<"Number of Type: " <<filter.size() << endl;
     cout <<"Char: "<< (char)maxx << endl;
     cout <<"Frequency: " << cnt[maxx] << endl;

    return 0;
}
