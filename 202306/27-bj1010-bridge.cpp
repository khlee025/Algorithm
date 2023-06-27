//Silver 5. 조합 문제
#include<iostream>

using namespace std;

int main() {
	int T;

	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b;
		long long num = 2;
		long long ans = 1;
		cin >> a >> b;

		if (a < (b - a)) a = b - a;
		
		for (int i = b; i > a; i--) {
			ans *= i;
			if (num <= (b - a)) {
				while (ans % num == 0) {
					ans /= num;
					num++;
					if (num > (b - a)) break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;

}