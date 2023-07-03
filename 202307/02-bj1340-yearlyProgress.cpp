//Silver 5. 소수점 자리수 체크
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isLong(int a) {
	if (a % 4 == 0) {
		if (a % 100 == 0) {
			if (a % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> month{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	vector<int> monthDay{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	string y, m, d, t;

	long long Time=0;
	long long All = 365;
	cin >> m >> d >> y >> t;

	bool flag = isLong(stoi(y));
	for (int i = 0; i < 12; i++) {
		if (month[i] == m) break;
		else if (i == 1 && flag) Time += 1;
		Time += monthDay[i];
	}
	if (flag) All += 1;
	Time += (stoi(d.substr(0,2))-1);

	All = All * (60 * 24);
	Time = Time * (60 * 24);
	Time += (stoi(t.substr(0, 2)) * 60) + stoi(t.substr(3, 2));
	Time *= 100;
	cout << fixed;
	cout.precision(15);
	cout << (double)Time / All << '\n';
	return 0;
}

