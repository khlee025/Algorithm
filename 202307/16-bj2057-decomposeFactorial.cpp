//Silver 5. 그리디, 팩토리얼

#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<long long> fact;
	long long temp = 1;
	fact.push_back(temp);
	for (int i = 1; i < 21; i++) {
		temp *= i;
		fact.push_back(temp);
	}
	long long N;
	bool flag = false;
	cin >> N;
	if (N != 0) {
		for (int i = 20; i >= 0; i--) {
			if (N >= fact[i]) N -= fact[i];
			if (N == 0) {
				flag = true;
				break;
			}
		}
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
