//Silver 5. 구현
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int score;
	int idx;
};

bool operator<(node a, node b) {
	return a.score > b.score;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<node> First;
	for (int i = 0; i < 8; i++) {
		node temp;
		cin >> temp.score;
		temp.idx = i + 1;
		First.push_back(temp);
	}

	sort(First.begin(), First.end());
	vector<int> second;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		second.push_back(First[i].idx);
		sum += First[i].score;
	}
	sort(second.begin(), second.end());
	cout << sum << '\n';
	for (int i = 0; i < 5; i++) {
		cout << second[i] << ' ';
	}

	return 0;
}