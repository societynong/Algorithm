#include<bits/stdc++.h>

using namespace std;

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " " ;
	cout << endl;
}

void insertSort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		// 每次确定前i项，第一次不用管
		for (int j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--) {
			// 从后往前比，比到第1位为止
				swap(arr[j], arr[j+1]);
		}
	}

}

int main() {
	int n = 10;
	int N = 30;
	vector<int> arr(n);
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % N;
	showArr(arr);
	insertSort(arr);
	showArr(arr);
	return 0;

}