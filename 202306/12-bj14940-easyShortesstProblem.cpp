//Silver 1. BFS 구현
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int x;
	int y;
	int dist;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M, 0));
	vector<vector<bool>> used(N, vector<bool>(M, false));
	queue<node> Qu;
	node st;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 1) arr[y][x] = -1;
			else if (arr[y][x] == 2) st = { x,y,0 };
		}
	}
	Qu.push(st);

	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };

	while (!Qu.empty()) {
		node now = Qu.front();
		Qu.pop();
		if (used[now.y][now.x]) continue;
		used[now.y][now.x] = true;
		arr[now.y][now.x] = now.dist;
		
		for (int i = 0; i < 4; i++) {
			node next = { now.x + dx[i], now.y + dy[i], now.dist + 1 };
			if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
			if (arr[next.y][next.x] == 0) continue;
			if (used[next.y][next.x]) continue;
			Qu.push(next);
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << arr[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}