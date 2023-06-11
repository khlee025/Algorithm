//Silver 2. BFS 기반 완전 탐색, 2차원 이동
#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct node {
	int x;
	int y;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> Map;
	int N, M;
	cin >> N >> M;
	node now;
	for (int y = 0; y < N; y++) {
		string str;
		cin >> str;
		for (int x = 0; x < M; x++) {
			if (str[x] == 'I') {
				now.y = y;
				now.x = x;
				str[x] = 'O';
			}
		}
		Map.push_back(str);
	}

	queue<node> Qu;
	Qu.push(now);
	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	int cnt = 0;

	while (!Qu.empty()) {
		now = Qu.front();
		Qu.pop();
		if (Map[now.y][now.x] == '-') continue;
		if (Map[now.y][now.x] == 'P') cnt++;
		Map[now.y][now.x] = '-'; //visited

		node next;
		for (int i = 0; i < 4; i++) {
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
			if (Map[next.y][next.x] == 'X') continue;
			if (Map[next.y][next.x] == '-') continue;
			Qu.push(next);
		}
		
	}

	if (cnt == 0) cout << "TT\n";
	else cout << cnt << '\n';

	return 0;
}