//Silver 5. 브루트포스 구현
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string reverseStr(string A, string B, string C) {
	string res;
	for (int i = A.size() - 1; i >= 0; i--) res.push_back(A[i]);
	for (int i = B.size() - 1; i >= 0; i--) res.push_back(B[i]);
	for (int i = C.size() - 1; i >= 0; i--) res.push_back(C[i]);
	return res;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> ans;
	string input;
	cin >> input;

	for (int A = 1; A < input.size(); A++) {
		for (int B = A + 1; B < input.size(); B++) {
			ans.push_back(reverseStr(input.substr(0, A), input.substr(A, B - A), input.substr(B)));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << '\n';


	return 0;
}