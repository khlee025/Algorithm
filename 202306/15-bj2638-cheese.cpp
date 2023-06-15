//Gold 3. BFS를 이용한 구현.
//빈 공간을 미리 구분하여 활용 > 2회 BFS 중복이기 때문에 1회만 사용해도 될 것 같음
//차후 수정해보기
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

struct node {
	int x;
	int y;
};

int N, M;

queue<node> Qu;
vector<string> map(0);
vector<string> dim(0); //-1 : Not decided
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void startBFS(int a) {
	while (!Qu.empty()) {
		node now = Qu.front();
		Qu.pop();
		if (dim[now.y][now.x] != 'n') continue;
		dim[now.y][now.x] = a;

		for (int i = 0; i < 4; i++) {
			node next = { now.x + dx[i],now.y + dy[i] };
			if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
			if (map[next.y][next.x] != '0') continue;
			if (dim[next.y][next.x] != 'n') continue;
			Qu.push(next);
		}
	}
};

void startBFS2(int a) {
	while (!Qu.empty()) {
		node now = Qu.front();
		Qu.pop();
		if (dim[now.y][now.x] != 'z') continue;
		dim[now.y][now.x] = a;

		for (int i = 0; i < 4; i++) {
			node next = { now.x + dx[i],now.y + dy[i] };
			if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
			if (map[next.y][next.x] != '0') continue;
			if (dim[next.y][next.x] != 'z') continue;
			Qu.push(next);
		}
	}
};
bool isValid(int x, int y, int num) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		node next = { x + dx[i], y + dy[i] };
		if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
		if (dim[next.y][next.x] < num) cnt++;
	}

	if (cnt >= 2) return true;
	else return false;

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//init.
	cin >> N >> M;
	map.resize(N, "");
	string str;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int a;
			cin >> a;
			if (a) map[y].push_back('1');
			else map[y].push_back('0');
			if (y == 0) str.push_back('n');
		}
	}
	dim.resize(N, str);

	//find BFS
	Qu.push({ 0,0 });
	startBFS(0);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == '0' && dim[y][x] == 'n') {
				Qu.push({ x,y });
				startBFS('z');
			}
		}
	}

	bool flag = true;
	int num = 0;
	while (flag) {
		flag = false;
		num++;
		//find removed cheese.
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (dim[y][x] == 'n' && map[y][x] == '1') {
					flag = true;
					if (isValid(x, y, num)) {
						dim[y][x] = num;
						for (int i = 0; i < 4; i++) {
							node next = { x + dx[i], y + dy[i] };
							if (next.y >= N || next.y < 0 || next.x >= M || next.x < 0) continue;
							if (dim[next.y][next.x] == 'z') {
								Qu.push(next);
								startBFS2(num);
							}
						}
					}
				}
			}
		}
		if (flag == false) cout << num-1;
	}
	return 0;
}
