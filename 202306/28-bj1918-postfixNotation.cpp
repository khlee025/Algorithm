//Gold 2. 스택 기반 구현. 공부 후 풀이
#include<iostream>
#include<string>
#include<vector>

using namespace std;

char setType(char A) {
	if (A == '+' || A == '-') return 'A';
	if (A == '*' || A == '/') return 'B';
	if (A == '(' || A == ')') return A;
	return 'C';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;
	vector<char> st(input.size(), 0);
	int id = 0;
	for (int i = 0; i < input.size(); i++) {
		char tp = setType(input[i]);
		if (tp == 'C') cout << input[i];
		else if (tp == 'A') {
			if (id >= 1) {
				while (setType(st[id - 1]) == 'B') {
					if (id - 1 < 0) break;
					cout << st[id - 1];
					id--;
				}
				if (setType(st[id - 1]) == 'A') cout << st[id - 1];
				else id++;
			}
			else id++;
			st[id - 1] = input[i];
		}
		else if (tp == 'B') {
			if (id >= 1) {
				if (setType(st[id - 1]) == 'B') cout << st[id - 1];
				else id++;
			}
			else id++;
			st[id - 1] = input[i];
		}
		else if (tp == '(') {
			id++;
			st[id - 1] = input[i];
		}
		else if (tp == ')') {
			while (setType(st[id - 1]) != '(') {
				if (id - 1 < 0) break;
				cout << st[id - 1];
				id--;
			}
			id--;
		}
	}
	for (int i = id - 1; i >= 0; i--) cout << st[i];
	return 0;
}