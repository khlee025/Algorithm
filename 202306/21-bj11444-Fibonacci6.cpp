//Gold 2. 피보나치 수열에 대한 도가뉴 항등식
#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<long long, long long> um;
int K = 1000000007;
long long Fibo(long long n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;

	if (um[n] == 0) {
		if (n % 2 == 1) {
			long long A = Fibo(n / 2);
			long long B = Fibo((n / 2) + 1);
			um[n] = (((A * A) % K) + ((B * B) % K)) % K;
		}
		else {
			long long A = Fibo(n / 2);
			long long B = Fibo((n / 2) + 1);
			long long C = Fibo((n / 2) - 1);
			long long temp = (B + C) % K;
			um[n] = (A * temp) % K;
		}
	}
	return um[n];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long N;
	cin >> N;
	cout << Fibo(N) << '\n';
	return 0;
}