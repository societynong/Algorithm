#include<bits/stdc++.h>
using namespace std;

void heapInsert(vector<int> &arr,int i) {
	while (arr[i] > arr[(i - 1) / 2]) {
		swap(arr[i], arr[(i - 1) / 2]);
		i = (i - 1) / 2; // (0 - 1) / 2 = 0
	}

}

void heapify(vector<int> &arr,int heapsize) {
	int i = 0;
	while (i * 2 + 1 < heapsize) {
		int j = i * 2 + 1;
		if (j + 1 < heapsize)
			j = arr[j] > arr[j + 1] ? j : j + 1;
		if (arr[j] > arr[i]) {
			swap(arr[j], arr[i]);
			i = j;
		}
		else
			break;
	}
}


void heapSort(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++)
		heapInsert(arr, i);
	int heapsize = arr.size();
	while(heapsize > 0) {
		swap(arr[--heapsize], arr[0]);
		heapify(arr, heapsize);
	}
}

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}
int main() {
	int n = 10;
	int N = 30;
	srand(time(0));
	vector<int> arr;
	for (int i = 0; i < n; i++)
		arr.push_back(rand() % N);
	showArr(arr);
	
	heapSort(arr);
	showArr(arr);
}