//Gold 5. Geometry and Vector
#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long ox, oy;
	long long x1, y1, x2, y2;
	cin >> ox >> oy >> x1 >> y1;
	x1 -= ox;
	y1 -= oy;
	long long sum = 0;
	for (int i = 0; i < N - 2; i++) {
		cin >> x2 >> y2;
		x2 -= ox;
		y2 -= oy;
		sum += (x1 * y2 - x2 * y1);
		x1 = x2;
		y1 = y2;
	}
	cout << abs(sum/2);
	if (sum % 2) cout << ".5" << '\n';
	else cout << ".0" << '\n';

	return 0;
}