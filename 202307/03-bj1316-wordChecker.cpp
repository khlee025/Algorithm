//Silver 5. 단순 문자열 처리
#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num = 0;
	int T;
	cin >> T;
	vector<bool> Test;
	string temp;
	for (int t = 0; t < T; t++) {
		Test.clear();
		Test.resize(26, false);
		cin >> temp;
		Test[temp[0] - 'a'] = true;

		bool flag = false;
		for (int i = 1; i < temp.size(); i++) {
			if (temp[i] != temp[i - 1] && Test[temp[i] - 'a']) {
				flag = true;
				break;
			}
			Test[temp[i] - 'a'] = true;
		}
		if (!flag) num++;
	}
	cout << num << '\n';
	return 0;
}