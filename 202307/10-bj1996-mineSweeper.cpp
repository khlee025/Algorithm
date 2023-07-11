//Silver 5. 구현
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int N;
vector<string> input;
vector<string> output;

char countNum(int x, int y) {
	int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
	int dx[8] = { 1,0,-1,1,-1,1,0,-1 };
	int num = 0;

	for (int i = 0; i < 8; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
		if (input[ny][nx] != '.') num += (input[ny][nx] - '0');
	}

	if (num >= 10) return 'M';
	else return '0' + num;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		input.push_back(temp);
		output.push_back(temp);
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (output[y][x] != '.') output[y][x] = '*';
			else output[y][x] = countNum(x, y);
		}
		cout << output[y] << '\n';
	}

	return 0;
}