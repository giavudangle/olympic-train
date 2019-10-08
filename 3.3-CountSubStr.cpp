
#include<bits/stdc++.h>
using namespace std;
set<string>res;

void subString(string s, int n)
{

	for (int i = 0; i < n; i++)
		for (int len = 1; len <= n - i; len++)
			res.insert(s.substr(i, len));
}

int main()
{
	string s ;
	cin >> s;
	subString(s,s.length());
	for (auto x : res ) cout << x << " ";
	return 0;
}
