//Gold 1. DP인척 하는 최적화 문제
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C;
int n;
vector<int> front_sum(0);
vector<int> back_sum(0);
vector<int> front(0);
vector<int> back(0);

void DFS(int idx, bool isFront) {
	if (isFront && idx == n) return;
	else if (!isFront && idx == (N-n)) return;

	if (isFront) {
		int len = front_sum.size();
		for (int i = 0; i < len; i++) {
			int temp = front_sum[i] + front[idx];
			if (temp <= C) front_sum.push_back(temp);
		}
	}
	else {
		int len = back_sum.size();
		for (int i = 0; i < len; i++) {
			int temp = back_sum[i] + back[idx];
			if (temp <= C) back_sum.push_back(temp);
		}
	}
	DFS(idx + 1, isFront);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	n = N / 2;

	front.resize(n,0);
	back.resize(N - n,0);

	for (int i = 0; i < n; i++) cin >> front[i];
	for (int i = 0; i < N - n; i++) cin >> back[i];

	front_sum.push_back(0);
	back_sum.push_back(0);

	DFS(0, true);
	DFS(0, false);
	sort(front_sum.begin(), front_sum.end());
	sort(back_sum.begin(), back_sum.end());

	int fidx = 0;
	int bidx = back_sum.size() - 1;

	int ans = 0;
	bool flag = true;
	while (flag) {
		if (fidx >= front_sum.size()) break;
		if (bidx < 0) break;

		if (front_sum[fidx] + back_sum[bidx] <= C) {
			ans += (bidx + 1);
			fidx++;

		}
		else bidx--;
	}
	cout << ans << '\n';

	return 0;
}