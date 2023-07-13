//Silver 5. 단순 수학
#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int input;
	cin >> input;
	
	int N = floor(sqrt(input));
	int temp = N * N;
	int output = 4;

	if (input == temp) {
		if (output < 4 * (N - 1)) output = 4 * (N - 1);
	}
	else if (input < (temp + N)) {
		if (output < (4 * N - 2)) output = (4 * N - 2);
	}
	else {
		if (output < (4 * N)) output = 4 * N;
	}
	cout << output << '\n';

	return 0;
}