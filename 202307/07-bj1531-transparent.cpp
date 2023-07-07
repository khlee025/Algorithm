//Silver 5. 구현
#include<iostream>
#include<vector>

using namespace std;

struct node {
	int sx;
	int sy;
	int ex;
	int ey;
};

int N, M;
int cnt;

vector<node> arr(0);

void countNum() {
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			int tempcnt = 0;
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i].sx <= x && arr[i].ex >= x && arr[i].sy <= y && arr[i].ey >= y) tempcnt++;
			}
			if (tempcnt > M) cnt++;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	if (N < M) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		node temp;
		cin >> temp.sx >> temp.sy >> temp.ex >> temp.ey;
		temp.sx -= 1;
		temp.sy -= 1;
		temp.ex -= 1;
		temp.ey -= 1;
		arr.push_back(temp);
	}

	countNum();

	cout << cnt << '\n';



	return 0;
}