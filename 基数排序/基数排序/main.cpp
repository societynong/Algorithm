#include<bits/stdc++.h>

using namespace std;

void bucketSort(vector<int> &arr) {
	// only for 0 - 200 value
	int mxV = INT_MIN;
	for (auto item : arr)
		mxV = max(item, mxV);
	int *bucket = new int[mxV + 1]();

	for (auto item : arr)
		bucket[item]++;
	int j = 0;
	for (int i = 0; i <= mxV; i++) {
		while (bucket[i] != 0) {
			arr[j++] = i;
			bucket[i]--;
		}
	}
}

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}

int getBucket(double mx, double mi, double x,int n) {
	return (int)((x - mi) / (mx - mi) * n);
}

int maxGap(vector<int> &arr) {

	int n = arr.size();

	int vMx = INT_MIN;
	int vMi = INT_MAX;
	
	for (auto item : arr) {
		vMx = max(vMx, item);
		vMi = min(vMi, item);
	}

	vector<bool> visited(n + 1);
	vector<int> lMx(n + 1);
	vector<int> lMi(n + 1);

	for (auto item : arr) {
		int bi = getBucket(vMx, vMi, item, n);
		if (!visited[bi]) {
			lMx[bi] = item;
			lMi[bi] = item;
		}
		else {
			lMx[bi] = max(item, lMx[bi]);
			lMi[bi] = min(item, lMi[bi]);
		}

		visited[bi] = true;
	}
	int ret = 0;
	int pre = 0;
	for (int i = 1; i <= n;i++) {
		if (visited[i]) {
			ret = max(ret, lMi[i] - lMx[pre]);
			pre = i;
		}
	}
	return ret;
	
}

int main() {
	srand(time(0));
	int n = 10;
	int N = 30;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = rand() % N;
	showArr(arr);
	bucketSort(arr);
	showArr(arr);

	cout << maxGap(arr) <<endl;
	return 0;


}