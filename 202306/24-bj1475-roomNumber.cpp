//Silver 5. 구현
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> nums;
	nums.resize(10, 0);
	int str;
	cin >> str;
	
	while (str != 0) {
		nums[str % 10]++;
		str /= 10;
	}

	int ans = -1;
	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			int temp = nums[6] + nums[9];
			int res = 0;
			while (temp > 0) {
				temp -= 2;
				res += 1;
			}
			if (res > ans) ans = res;
		}
		else if (nums[i] > ans) ans = nums[i];
	}

	cout << ans << '\n';

	return 0;
}