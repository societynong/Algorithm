#include<bits/stdc++.h>

using namespace std;

int getMid(vector<int> &arr) {
	priority_queue<int, vector<int>, greater<int>> mih;
	priority_queue<int, vector<int>, less<int>> mxh;
	for (int i = 0; i < arr.size(); i++) {
		if (mxh.empty())
			mxh.push(arr[i]);
		else {
			if (arr[i] > mxh.top()) {
				mih.push(arr[i]);
			}
			else {
				mxh.push(arr[i]);
			}
			if (mih.size() > mxh.size() + 1) {
				mxh.push(mih.top());
				mih.pop();
			}
			if (mxh.size() > mih.size() + 1) {
				mih.push(mxh.top());
				mxh.pop();
			}
		}
	}
	if (mxh.size() > mih.size())
		return mxh.top();
	else if (mxh.size() < mih.size())
		return mih.top();
	else
		return (mxh.top() + mih.top()) / 2;
	
}

void showArr(vector<int> &arr) {
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}
int main() {
	int n = 9;
	int N = 50;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = rand() % N;
	sort(arr.begin(), arr.end());
	showArr(arr);
	cout << getMid(arr) << endl;
	return 0;
}