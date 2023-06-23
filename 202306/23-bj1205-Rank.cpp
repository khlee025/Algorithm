//Silver 4. 구현, 다수의 반례
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, P, now;
	cin >> N >> now >> P;

	vector<int> rank(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> rank[i];
	}
	sort(rank.begin(), rank.end());
	if (N == 0) {
		cout << 1;
		return 0;
	}

	int myRank = 1;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (rank[i] > now) {
			flag = true;
			myRank = N - i + 1;
			if (myRank > P) myRank = -1;
			else if (N==P && now <= rank[0]) myRank = -1;
			break;
		}
	}

	if (!flag) {
		if (N==P && now <= rank[0]) myRank = -1;
	}

	cout << myRank << '\n';

	return 0;
}