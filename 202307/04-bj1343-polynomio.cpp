//Silver 5. 단순 문자열 처리
#include<iostream>
#include<string>

using namespace std;

string input;

void Ans(int st, int ed, char T) {
	for (int i = st; i < ed; i++) input[i] = T;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	cin >> input;
	int st = 0;
	int ed;
	bool flag = false;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '.') {
			ed = i;
			if (flag) {
				flag = false;
				if ((ed - st) % 2 == 1) {
					cout << "-1\n";
					return 0;
				}
				int temp = st;
				while (temp <= ed) temp += 4;
				Ans(st, temp - 4, 'A');
				Ans(temp - 4, ed, 'B');
			}
		}
		if (input[i] == 'X') {
			if (!flag) {
				st = i;
				flag = true;
			}
		}
	}

	if (input[input.size() - 1] == 'X') {
		ed = input.size();
		if (flag) {
			flag = false;
			if ((ed - st) % 2 == 1) {
				cout << "-1\n";
				return 0;
			}
			int temp = st;
			while (temp <= ed) temp += 4;
			Ans(st, temp - 4, 'A');
			Ans(temp - 4, ed, 'B');
		}
	}

	cout << input << '\n';
	return 0;
}