//Silver 5. 이분탐색
#include<iostream>

using namespace std;

int main() {
	long long input;
	cin >> input;
	input *= 2;
	int L = 1;
	int R = 92683;//max N 92683
	int m = 0;
	while ((R - L) != 1) {
		m = (L + R) / 2;
		long long temp = m * (long long)(m + 1);
		if (input >= temp) L = m;
		else R = m;
	}
	cout << L << '\n';
	return 0;
}