//Gold 3. DFS
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int R, C;
vector<string> Map;
bool used[26];
int cnt = -1;

void rec(int y, int x, int num) {
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,1,-1 };

	int flag = false;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= R || ny < 0 || nx >= C || nx < 0) continue;
		if (used[Map[ny][nx] - 'A']) continue;
		flag = true;
		used[Map[ny][nx] - 'A'] = true;
		rec(ny, nx, num + 1);
		used[Map[ny][nx] - 'A'] = false;
	}
	
	if (!flag && cnt < num) cnt = num;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	

	//init.
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;
		Map.push_back(temp);
	}
	used[Map[0][0] - 'A'] = true;;
	rec(0, 0, 1);

	cout << cnt << '\n';

	return 0;
}