#include <iostream>
using namespace std;

int n;
int a[100000];
int trc1[100000], trc2[100000];
int d1[100000];
int d2[100000];
int m, l, k;


void Process() {
	int i, j, m;
	for (i = 1;i <= n;i++) {
		cin >> a[i];
		d1[i] = 1;
		m = 0;
		for (j = i - 1;j >= 1;j--) {
			if ((d1[i] < d1[j] + 1) && (a[i] <= a[j])) {
				d1[i] = d1[j] + 1;
				m = j;
			}
			trc1[i] = m;
		}
	}
}

void Dynamic() {
	int i, j, max, m;
	for (i = n;i >= 1;i--) {
		d2[i] = 1;
		m = 0;
		for (j = i + 1;j <= n;j++) {
			if ((d2[i] < d2[j] + 1) && (a[i] <= a[j])){
				d2[i] = d2[j] + 1;
				m = j;
			 }
		}
		trc2[i] = m;

		if (d1[i] + d2[i] > k) {
			k = d1[i] + d2[i];
			l = i;
		}
	}
}

void Previous(int i) {
	if (trc1[i] != 0) {
		Previous(trc1[i]);
	}
	cout << a[i] << " ";
}

void Out() {
	cout << k - 1 << endl;
	Previous(l);
	while (trc2[l] != 0) {
		l = trc2[l];
		cout << a[l] << " ";
	}
}


int main() {


	cin >> n;
	Process();
	Dynamic();
	Out();
	




	for (;;);
	return 0;
}
