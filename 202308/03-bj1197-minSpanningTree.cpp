//Gold 4. Union-find

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int st;
	int ed;
	int val;
};

bool operator<(node a, node b) {
	if (a.val == b.val) {
		if (a.st == b.st) {
			return a.ed < b.ed;
		}
		return a.st < b.st;
	}
	return a.val < b.val;
}

vector<int> Group(0);
vector<node> Edge(0);

long long sum;

int find(int A) {
	if (A != Group[A]) Group[A] = find(Group[A]);
	return Group[A];
}

bool Union(int A, int B) {
	int GA = find(A);
	int GB = find(B);
	if (GA != GB) {
		Group[GA] = GB;
		return true;
	}
	return false;

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;
	
	//init
	for (int i = 0; i <= V; i++) Group.push_back(i);

	Edge.resize(E, { 0,0,0 });
	for (int i = 0; i < E; i++) {
		cin >> Edge[i].st >> Edge[i].ed >> Edge[i].val;
	}
	sort(Edge.begin(), Edge.end());

	for(int i=0;i<E;i++){
		if (Union(Edge[i].st, Edge[i].ed)) sum += Edge[i].val;
	}
	
	cout << sum << '\n';
	return 0;

}