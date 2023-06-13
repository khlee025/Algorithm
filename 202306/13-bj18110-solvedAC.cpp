//Silver 4. 수학을 이용한 단순 구현
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int cnt = round((double)N * (0.15));
	vector<int> arr;
	int sum = 0;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sum += temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < cnt; i++) {
		sum -= arr[i];
		sum -= arr[arr.size() - 1 - i];
	}
	if (N == 0) cout << 0 << '\n';
	else cout << round((double)sum / (N - 2 * cnt)) << '\n';

	return 0;
}