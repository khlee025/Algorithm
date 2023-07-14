//Silver 5. 구현
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int sx;
	int ex;
	int sy;
	int ey;
};

vector<node> vec(0);

bool isValid(int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (vec[i].sx <= x && vec[i].ex > x) {
			if (vec[i].sy <= y && vec[i].ey > y) return true;
		}
	}
	return false;
}

int main() {
	int a, b, c, d;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b >> c >> d;
		vec.push_back({ a,c,b,d });
	}

	int cnt = 0;
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (isValid(x, y)) cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;

	
}