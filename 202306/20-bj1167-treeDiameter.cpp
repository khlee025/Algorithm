//Gold 2. 2단 Dijkstra

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
	int ed;
	int dist;
};

bool operator<(node a, node b) {
	if (a.dist == b.dist) return a.ed < b.ed;
	return a.dist < b.dist;
}
bool operator>(node a, node b) {
	if (a.dist == b.dist) return a.ed > b.ed;
	return a.dist > b.dist;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int V;
	cin >> V;
	vector<vector<node>> Map(V, (vector<node>(0)));
	for (int i = 0; i < V; i++) {
		int st, ed, sc;
		cin >> st;
		cin >> ed;
		while (ed != -1) {
			cin >> sc;
			Map[st - 1].push_back({ ed-1,sc });
			cin >> ed;
		}
	}

	//find first point
	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push({ 0, 0 });
	vector<int> used(V, -1);
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (used[now.ed]!=-1) continue;
		used[now.ed] = now.dist;
		for (int i = 0; i < Map[now.ed].size(); i++) {
			if (used[Map[now.ed][i].ed]!=-1) continue;
			pq.push({ Map[now.ed][i].ed, now.dist + Map[now.ed][i].dist });
		}
	}
	int fidx = 0;
	for(int i=1;i<V;i++){
		if (used[fidx] < used[i]) fidx = i;
	}

	//find second point
	pq.push({ fidx,0 });
	used.clear();
	used.resize(V, -1);
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (used[now.ed] != -1) continue;
		used[now.ed] = now.dist;
		for (int i = 0; i < Map[now.ed].size(); i++) {
			if (used[Map[now.ed][i].ed] != -1) continue;
			pq.push({ Map[now.ed][i].ed, now.dist + Map[now.ed][i].dist });
		}
	}
	int sidx = 0;
	for (int i = 1; i < V; i++) {
		if (used[sidx] < used[i]) sidx = i;
	}

	cout << used[sidx] << '\n';


	return 0;
}