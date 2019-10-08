#include <bits/stdc++.h>
using namespace std;


int n;
int arr[100000+10];
int minSum(int arr[], int n)
{

	sort(arr, arr + n);

	int x = arr[n / 2];

	int sum = 0;


	for (int i = 0; i < n; i++){
        sum += abs(arr[i] - x);
	}

	return sum;
}

int Result(int sum,int arr[],int n){
    int test=sum;
    int s;
    for (int i=0;i<n;i++){
        s=0;
        for (int j=0;j<n;j++){
            s+=abs(arr[j]-i);
        }
        if (s==test) cout << i << " ";
    }
    cout << endl;
    return 0;
}


int main()
{

	//int arr[] = { 3,1,5,4,5};

	cin >> n ;
	for (int i=0;i<n;i++) cin >> arr[i];

	int test=minSum(arr, n);

	Result(test,arr,n) ;

	cout << minSum(arr, n) << endl;


	return 0;
}

