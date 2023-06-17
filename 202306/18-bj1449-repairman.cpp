//Silver 3. 구현
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;
	vector<int> pos;
	int cnt = 0;
	int maxL = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pos.push_back(temp);
	}
	sort(pos.begin(), pos.end());
	
	for (int i = 0; i < N; i++) {
		if (pos[i] > maxL) {
			cnt++;
			maxL=pos[i] + (L - 1);
		}
	}
	cout << cnt;

	return 0;
}