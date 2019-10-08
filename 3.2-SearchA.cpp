#include <bits/stdc++.h>
using namespace std;
int a[1000];
int n;

void QuickSort(int a[], int left, int right) {
	int i, j, x;
	i = left;
	j = right;
	x = a[(left + right) / 2];
	while (i < j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j) QuickSort(a, left, j);
	if (right > i) QuickSort(a, i, right);

}


int BinarySearch(int arr[], int left, int right, int key) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key) {
			//cout << mid ;
			return mid;
		}

		if (arr[mid] > key)
			return BinarySearch(arr, left, mid - 1, key);
		return BinarySearch(arr, mid + 1, right, key);
	}
	return -1;
}
// a
int A(int a[], int n)
{
	QuickSort(a, 0, n - 1);
	for (int i = 0;i < n;i++) {
		if (a[i] >= 0) return -1;
		int finds = BinarySearch(a, i, n , -a[i]);
		if (finds != -1) {
			cout << "i: " << i << endl;
			cout << "j: " << finds << endl;

		}


	}
	return -1;
}


// B
int B(int a[], int n) {
	QuickSort(a, 0, n - 1);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int s = a[i] + a[j];
			int finds = BinarySearch(a, j, n, -s);
			if (finds != -1) {
				cout << "i: " << i << endl;
				cout << "j: " << j << endl;
				cout << "k: " << finds << endl;
				return 0;
			}

		}
	}
	return -1;
}
// C 
// Em dùng two pointer 2 đầu, return i,j khi a[i]=-a[j],và chặn một số đk

// D 
// Em chạy tuyến tính 2 vị trí kề nhau rồi dùng two pointer như C


int main() {
	//-2 0 1 2
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	//for (int i=0;i<n;i++) cout << a[i] << " ";
	A(a, n);
	B(a, n);
	system("pause");
	return 0;
}

//-102 100 102 63 -199 22 88
