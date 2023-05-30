//Gold 3. 이중 다익스트라
//현재 코드에서 dist 구현 방식 조정시 memory save 가능

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int ed;
	int dist;
};

bool operator>(node a, node b) {
	if (a.dist == b.dist) return a.ed > b.ed;
	return a.dist > b.dist;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//initialize
	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<int>> dist(N, vector<int>(N,-1));
	for (int i = 0; i < M; i++) {
		int st, ed, cost;
		cin >> st >> ed >> cost;
		dist[st - 1][ed - 1] = cost;
	}

	// X > node : dijkstra
	vector<int> come(N, -1);
	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push({ X - 1,0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (come[now.ed] != -1) continue;
		come[now.ed] = now.dist;
		for (int i = 0; i < N; i++) {
			if (dist[now.ed][i] == -1) continue;
			else pq.push({ i,now.dist + dist[now.ed][i] });
		}
	}

	// node > X : dijkstra
	vector<int> go(N, -1);
	pq.push({ X - 1,0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (go[now.ed] != -1) continue;
		go[now.ed] = now.dist;
		for (int i = 0; i < N; i++) {
			if (dist[i][now.ed] == -1) continue;
			else pq.push({ i,now.dist + dist[i][now.ed] });
		}
	}
	
	//find maximum time
	int ans = -1;
	for (int i = 0; i < N; i++) {
		int temp = go[i] + come[i];
		if (temp > ans) ans = temp;
	}
	cout << ans << '\n';
	return 0;
}