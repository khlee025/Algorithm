//Gold 5. two pointer
#include<iostream> 
#include<vector>

using namespace std;

int A = 0; //for the small one
int B = 0; //for the large one
int sum = 2000000000; //limitation

vector<int> nums(0);

void Test(int st, int ed) {
	int temp = nums[st] + nums[ed];
	if (sum > abs(temp)) {
		A = nums[st];
		B = nums[ed];
		sum = abs(temp);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// init
	int N;
	cin >> N;
	nums.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];

	int st = 0;
	int ed = N - 1;

	while (st != ed) {
		if (nums[st] < 0 && nums[ed] < 0) {
			Test(ed - 1, ed);
			break;
		}
		else if (nums[st] > 0 && nums[ed] > 0) {
			Test(st,st + 1);
			break;
		}
		
		int temp = nums[st] + nums[ed];
		if (temp == 0) {
			A = nums[st];
			B = nums[ed];
			break;
		}
		else {
			Test(st, ed);
			if (temp < 0) st++;
			else ed--;
		}

	}
	cout << A << ' ' << B << '\n';
	return 0;
}