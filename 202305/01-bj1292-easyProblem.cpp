//Bronz 1. 단순 구현
#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int st, ed;
	cin >> st >> ed;
	
	int all_num = 0;
	int sum = 0;
	int part_num = 1;

	int A, B;

	while (all_num <= 1000) {
		for (int i = 0; i < part_num; i++) {
			sum += part_num;
			all_num++;
			if (all_num == st) {
				A = sum-part_num;
			}
			if (all_num == ed) {
				B = sum;
				break;
			}
		}
		if (all_num == ed) break;
		part_num++;
	}

	cout << B - A << '\n';

	return 0;
}