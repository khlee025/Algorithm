//Silver 5. 큰 수 처리 - 문자열
#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string init;
	cin >> init;

	if (init.size() == 1) {
		cout << "0\n";
		if ((init[0] - '0') % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}

	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < init.size(); i++) sum += (init[i] - '0');

	while (sum >= 10) {
		int temp = 0;
		while (sum != 0) {
			temp += (sum % 10);
			sum /= 10;
		}
		sum = temp;
		cnt++;
	}

	cout << cnt << '\n';
	if (sum % 3 == 0) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}