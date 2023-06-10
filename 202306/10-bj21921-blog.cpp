//Silver 3. Accumulated Sum
#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, X, temp;
	int now = 0;
	int cnt = 0;
	int M = 0;

	queue<int> Qu;
	cin >> N >> X;
	for (int i = 0; i < X; i++) {
		cin >> temp;
		Qu.push(temp);
		now += temp;
	}
	M = now;
	cnt++;

	for (int i = 0; i < (N - X); i++) {
		temp = Qu.front();
		Qu.pop();
		now -= temp;
		cin >> temp;
		now += temp;
		Qu.push(temp);

		if (now == M) cnt++;
		else if (now > M) {
			M = now;
			cnt = 1;
		}
	}

	if (M == 0) cout << "SAD\n";
	else cout << M << '\n' << cnt << '\n';

	return 0;
}