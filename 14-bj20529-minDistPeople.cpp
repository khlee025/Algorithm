//Silver 1. 비둘기집의 원리 + 구현
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node {
	int t;
	int d;
};

unordered_map<string, int> um; // baseline ISTP=0000; ENFJ=1111;
vector<vector<node>> Dist(0);



bool operator<(node a, node b) {
	if (a.d == b.d) return a.t < b.t;
	return a.d < b.d;
}

int countOnes(int a) {
	int res = 0;
	while (a != 0) {
		res += (a % 2);
		a /= 2;
	}
	return res;
}

vector<int> cnt(0);

void sol() {
	int N;
	cin >> N;

	cnt.clear();
	cnt.resize(16, 0);
	
	//init.
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		cnt[um[str]]++;
	}

	//Pigeonhole Principle.
	if (N >= 48) {
		cout << "0\n";
		return;
	}

	//find Maximum;
	int midx = 0;
	for (int i = 1; i < 16; i++) {
		if (cnt[midx] == 0) midx = i;
		if (cnt[midx] < cnt[i]) midx = i;
	}

	//compute dist.
	int minDist = 0;

	if (cnt[midx] == 2) {
		minDist = 48;
		for (int i = 0; i < 16; i++) {
			if (cnt[i] != 2) continue;
			for (int k = 1; k < 16; k++) {
				if (cnt[Dist[i][k].t]) {
					int temp = 2*Dist[i][k].d;
					if (minDist > temp) {
						minDist = temp;
						break;
					}
				}
			}
		}
	}

	if(cnt[midx]<3){
		if(minDist==0) minDist = 48;
		for (int a = 0; a < 16; a++) {
			if (cnt[a] == 0) continue;
			for (int b = a + 1; b < 16; b++) {
				if (cnt[b] == 0) continue;
				for (int c = b + 1; c < 16; c++) {
					if (cnt[c] == 0) continue;
					int temp = 0;
					temp += countOnes(a ^ b);
					temp += countOnes(a ^ c);
					temp += countOnes(b ^ c);
					if (minDist > temp) minDist = temp;
				}
			}
		}
	}

	cout << minDist << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//init.
	for (int i = 0; i < 16; i++) {
		string str;
		int num = i;
		if (num / 8) str.push_back('E'); else str.push_back('I');
		num %= 8;
		if (num / 4) str.push_back('N'); else str.push_back('S');
		num %= 4;
		if (num / 2) str.push_back('F'); else str.push_back('T');
		num %= 2;
		if (num / 1) str.push_back('J'); else str.push_back('P');

		um[str] = i;
	}
	for (int i = 0; i < 16; i++) {
		Dist.push_back(vector<node>(0));
		for (int k = 0; k < 16; k++) {
			Dist[i].push_back({k,countOnes(i^k) });
		}
		sort(Dist[i].begin(), Dist[i].end());
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) sol();

	return 0;
}