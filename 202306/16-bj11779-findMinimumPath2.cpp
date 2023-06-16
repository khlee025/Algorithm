//Gold 3. dijkstra + 길찾기 구현
#include<iostream>
#include<vector>
#include<queue>

using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//init
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> bus(0);
	vector<bool> used(0);
	bus.resize(N, vector<pair<int,int>>(0));
	used.resize(N, false);
	for (int i = 0; i < M; i++) {
		int st, ed, sc;
		cin >> st >> ed >> sc;
		bus[st - 1].push_back({ ed - 1,sc });
	}

	int St, Ed;
	cin >> St >> Ed;
	St -= 1;
	Ed -= 1;

	//dijkstra. [mlogm+m] : 정렬+최단거리 검색
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // sc, ed;
	vector<pair<int, int>> path;
	path.resize(N, {-1, -1});
	path[St] = { 0,St };
	pq.push({ 0,St });

	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (used[now.second]) continue;
		used[now.second] = true;
		if (now.second == Ed) {
			cout << now.first << '\n';
			break;
		}
		for (int i = 0; i < bus[now.second].size(); i++) {
			if (used[bus[now.second][i].first]) continue;
			int tempdist = now.first + bus[now.second][i].second;
			int temped = bus[now.second][i].first;
			pq.push({ tempdist, temped });
			if (path[temped].first == -1) {
				path[temped] = { tempdist, now.second };
			}
			else if (path[temped].first > tempdist) {
				path[temped] = { tempdist, now.second };
			}
		}
	}

	//findPath (역으로 추적하기) 
	vector<int> rePath;
	int nowpos = Ed;
	while (path[nowpos].second != nowpos) {
		rePath.push_back(nowpos);
		nowpos = path[nowpos].second;
	}
	rePath.push_back(St);

	//정답 출력
	cout << rePath.size() << '\n';
	for (int i = rePath.size() - 1; i >= 0; i--) cout << rePath[i]+1 << ' ';

	return 0;
}
///반례////
//2
//2
//1 2 5
//1 2 10
//1 2
