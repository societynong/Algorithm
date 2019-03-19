#include<bits/stdc++.h>

using namespace std;

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}

void merge(vector<int> &arr, int  l, int mid, int r) {
	
	vector<int> arrHelper(r - l + 1);
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r)
		arrHelper[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	while (i <= mid)
		arrHelper[k++] = arr[i++];
	while (j <= r)
		arrHelper[k++] = arr[j++];
	for (int k = 0; k < r - l + 1; k++)
		arr[k + l] = arrHelper[k];
}

void sortProcession(vector<int> &arr, int l, int r) {
	if (r <= l)
		return;
	int mid = l + ((r - l) >> 1); // 括号不能省去 */ > +- > >>
	sortProcession(arr, l, mid);
	sortProcession(arr, mid + 1, r);
	merge(arr, l, mid, r);
	
}

void mergeSort(vector<int> &arr) {
	sortProcession(arr, 0, arr.size() - 1);
}

int main() {
	int n = 10;
	int N = 30;
	vector<int> arr(n);
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % N;
	showArr(arr);
	mergeSort(arr);
	showArr(arr);
	return 0;

}