//Gold 3. 플로이드-워셜
//다른 풀이(1/30) 있음. 확인하기
#include<iostream>
#include<vector>

using namespace std;

void sol() {
	int N, M, W;
	cin >> N >> M >> W;
	vector<vector<int>> Map;
	Map.resize(N, vector<int>(N,250000000));
	
	//init
	for (int i = 0; i < N; i++) Map[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int st, ed, w;
		cin >> st >> ed >> w;
		Map[st - 1][ed - 1] = min(Map[st-1][ed-1], w);
		Map[ed - 1][st - 1] = min(Map[st - 1][ed - 1], w);
	}
	for (int i = 0; i < W; i++) {
		int st, ed, w;
		cin >> st >> ed >> w;
		Map[st - 1][ed - 1] = min(Map[st - 1][ed - 1], -w);
	}
	//Floyd Warshall : any point start & end;
	for (int k = 0; k < N; k++) {
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				Map[a][b] = min(Map[a][b], Map[a][k] + Map[k][b]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (Map[i][i] < 0) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO" << '\n';

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//start
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		sol();
	}

	return 0;
}