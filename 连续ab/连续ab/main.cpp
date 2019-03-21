#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	vector<int> lA;
	vector<int> lB;
	for (int i = 0; i < str.size();i++) 
		if (str[i] == 'a')
			lA.push_back(i);
		else if (str[i] == 'b')
			lB.push_back(i);
	
	int ret = 0;
	if (lA.size() <= m || lB.size() <= m)
		ret = str.size();
	else {
		ret = lA[m];
		for (int i = m + 1; i < lA.size(); i++) {
			ret = max(ret, lA[i] - lA[i - m - 1] - 1);
		}
		ret = max(ret, lB[m]);
		for (int i = m + 1; i < lB.size(); i++) {
			ret = max(ret, lB[i] - lB[i - m - 1] - 1);
		}
	}
	cout << ret << endl;

}
