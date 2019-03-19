#include<bits/stdc++.h>

using namespace std;

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}

int partition(vector<int> &arr) {
	// [0,i-1]ะกำฺว๘
	int base = arr.back();
	int j = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= base)
			swap(arr[i], arr[++j]);
	}
	return j;
}


vector<int> partition3(vector<int> &arr,int l, int r) {
	int less = l-1;
	int more = r;
	int i = l;
	while (i < more) {
		if (arr[i] < arr[r])
			swap(arr[i++], arr[++less]);
		else if (arr[i] > arr[r])
			swap(arr[i], arr[--more]);
		else
			i++;
	}
	swap(arr[more], arr[r]);
	return {less + 1,more};
}

void quickSort(vector<int> &arr, int l, int r) {
	if (l < r) {
		swap(arr[rand() % (r - l + 1) + l], arr.back());
		vector<int> eq = partition3(arr, l, r);
		quickSort(arr, l, eq[0] - 1);
		quickSort(arr, eq[1] + 1, r);
	}
}

int main() {
	int n = 10;
	int N = 20;
	vector<int> arr(n);
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % N;
	showArr(arr);
	quickSort(arr, 0, arr.size() - 1);
	showArr(arr);
	return 0;

}