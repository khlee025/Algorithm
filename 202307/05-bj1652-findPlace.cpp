//Silver 5. 문자열, 구현
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> arr;
	bool flag = 0;
	int ver = 0;
	int hor = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		arr.push_back(str);
	}

	int temp = 0;
	for (int y = 0; y < N; y++) {
		flag = false;
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == '.') {
				if (!flag) {
					flag = true;
					temp = 1;
				}
				else if (flag) {
					if (temp == 1) hor++;
					temp++;
				}
			}
			if (arr[y][x] == 'X') flag = false;
		}
	}

	for (int x = 0; x < N; x++) {
		flag = false;
		for (int y = 0; y < N; y++) {
			if (arr[y][x] == '.') {
				if (!flag) {
					flag = true;
					temp = 1;
				}
				else if (flag) {
					if (temp == 1) ver++;
					temp++;
				}
			}
			if (arr[y][x] == 'X') flag = false;
		}
	}

	cout << hor << ' ' << ver << '\n';
	return 0;
}