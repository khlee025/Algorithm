//Gold 3. BFS
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct node {
	bool canGo;
	int x;
	int y;
	int step;
};

int N, M;
vector<string> Map;
vector<string> Tused;
vector<string> Fused;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
queue<node> Qu;

void goNext(node now) {
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
		if (now.canGo) {
			if (Map[ny][nx] == '1') {
				if (Fused[ny][nx] == '1') continue;
				Qu.push({ false, nx, ny, now.step + 1 });
			}
			else {
				if (Tused[ny][nx] == '1') continue;
				Qu.push({ true, nx, ny,now.step + 1 });
			}
		}
		else if (Map[ny][nx] == '0') {
			if (Fused[ny][nx] == '1') continue;
			Qu.push({ false, nx, ny,now.step + 1 });
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//init
	cin >> N >> M;
	string str = "";
	Map.resize(N, "");
	for (int i = 0; i < N; i++) cin >> Map[i];
	for (int i = 0; i < M; i++) str.push_back('0');
	Tused.resize(N, str);
	Fused.resize(N, str);

	//BFS
	int cnt = -1;
	Qu.push({ true,0,0,1 });
	while (!Qu.empty()) {
		node now = Qu.front();
		Qu.pop();
		if (now.canGo && Tused[now.y][now.x] == '1') continue;
		if (!now.canGo && Fused[now.y][now.x] == '1') continue;
		Fused[now.y][now.x] = '1';
		if(now.canGo) Tused[now.y][now.x] = '1';

		if (now.y == (N - 1) && now.x == (M - 1)) {
			cnt = now.step;
			break;
		}
		goNext(now);
	}
	//result
	cout << cnt << '\n';
	return 0;
}

// 반례
//9 9
//010001000
//010101010
//010101010
//010101010
//010101010
//010101010
//010101010
//010101011
//000100010