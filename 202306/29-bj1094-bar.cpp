//Silver 5. 구현
#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int cnt = 0;
	cin >> N;
	while (N != 0) {
		if (N % 2 == 1) cnt++;
		N /= 2;
	}

	cout << cnt << '\n';

	return 0;
}