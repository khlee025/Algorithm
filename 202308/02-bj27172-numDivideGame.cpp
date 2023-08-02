//Gold 5. Prime number
#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	unordered_map<int, int> um;
	set<int> ST;
	vector<int> nums(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		um[nums[i]] = 0;
		ST.insert(nums[i]);
	}

	for (auto it = ST.begin(); it != ST.end();it++){
		int temp = *it;
		while (temp <= 1000000) {
			auto iv = ST.find(temp);
			if (iv != ST.end()) {
				um[*it]++;
				um[*iv]--;
			}
			temp += (*it);
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << um[nums[i]] << ' ';
	}
	return 0;

}