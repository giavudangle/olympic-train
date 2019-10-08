#include <bits/stdc++.h>

using namespace std;

int main()
{
	string n;
	int k;

	cin >> n >> k;

	int b = n.size() - k - 1;
	int c = n.size() - b;
	int ind = 0;
	vector<char> res;
	char max = n.at(0);

	for (int i = 0; i < n.size() && res.size() < n.size() - k; i++) {
		max = n.at(i);
		ind = i;
		for (int j = i; j < i + c; j++) {
			if (n.at(j) > max) {
				max = n.at(j);
				ind = j;
			}
		}
		b--;
		c = n.size() - 1 - ind - b;
		res.push_back(max);
		i = ind;
	}

	for (int i = 0; i < res.size(); i++)
		cout << res.at(i);

	return 0;
}

