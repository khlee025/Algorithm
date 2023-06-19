#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	string T;
};

int cntNum(string a) {
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') res += (a[i] - '0');
	}
	return res;
}

bool operator<(node a, node b) {
	if (a.T.size() == b.T.size()) {
		int A = cntNum(a.T);
		int B = cntNum(b.T);
		if (A == B) {
			return a.T < b.T;
		}
		return A < B;
	}
	return a.T.size() < b.T.size();
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<node> res;
	for (int i = 0; i < N; i++) {
		node temp;
		cin >> temp.T;
		res.push_back(temp);
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < N; i++) {
		cout << res[i].T << '\n';
	}
	return 0;
}