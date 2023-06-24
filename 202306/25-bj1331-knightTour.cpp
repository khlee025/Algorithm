//Silver 5. 구현
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<bool>> map(6, vector<bool>(6, false));

bool isValid(string a, string b) {
	int T = a[1] - b[1];
	if (T < 0) T = (-T);
	int TT = a[0] - b[0];
	if (TT < 0) TT = (-TT);

	if (T == 1 && TT == 2) return true;
	if (T == 2 && TT == 1) return true;
	return false;
}

int main() {
	string start;
	string before;
	string now;
	bool flag = false;
	cin >> start;
	before=start;
	map[before[0] - 'A'][before[1] - '1'] = true;
	for (int i = 0; i < 35; i++) {
		if (flag) break;
		cin >> now;

		if (!isValid(before, now)) flag=true;
		if (map[now[0] - 'A'][now[1] - '1']) flag = true;

		before = now;
		map[now[0] - 'A'][now[1] - '1'] = true;
	}

	if (!isValid(now, start)) flag = true;

	if (flag) cout << "Invalid\n";
	else cout << "Valid\n";
	return 0;
}