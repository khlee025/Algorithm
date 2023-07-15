//Silver 5. 구현
#include<iostream>

using namespace std;

int N, M;
int now;
int num;

void isValid(int t) {
	if (now > t) {
		num += (now - t);
		now = t;
	}
	else if ((now + M - 1) < t) {
		num += (t - now - M + 1);
		now = (t - M + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int T, temp;
	cin >> T;
	now = 1;
	for (int t = 0; t < T; t++) {
		cin >> temp;
		isValid(temp);
	}
	cout << num << '\n';
}


