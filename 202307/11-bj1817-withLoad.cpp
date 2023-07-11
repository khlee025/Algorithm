///Silver 5. 구현
#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> St;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		St.push_back(temp);
	}

	int cnt = 0;
	int num = 0;
	for (int i = St.size() - 1; i >= 0; i--) {
		num += St[i];
		if (num > M) {
			cnt++;
			num = St[i];
		}
	}
	
	if (num != 0) cnt++;
	cout << cnt << '\n';

	return 0;
}