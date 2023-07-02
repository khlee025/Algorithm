//Silver 5. 구현
#include<iostream>

using namespace std;

bool isLong(int year) {
	int flag = false;
	if (year % 4 == 0) {
		flag = true;
		if (year % 100 == 0) {
			flag = false;
			if (year % 400 == 0) flag = true;
		}
	}
	return flag;
}
int numDay(int num, int flag) {
	if (num == 1) return 31;
	if (num == 2) {
		if (flag) return 29;
		else return 28;
	}
	if (num == 3) return 31;
	if (num == 4) return 30;
	if (num == 5) return 31;
	if (num == 6) return 30;
	if (num == 7) return 31;
	if (num == 8) return 31;
	if (num == 9) return 30;
	if (num == 10)return 31;
	if (num == 11) return 30;
	return 31;
}

long long countDay(int year, int month, int day) {
	long long res = 0;
	for (int i = 0; i < year; i++) {
		if (isLong(i)) res += 1;
	}
	res += (year * 365);
	for (int i = 1; i < month; i++) res += numDay(i, isLong(year));
	res += day;
	return res;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int Syear, Smonth, Sday;
	int Eyear, Emonth, Eday;
	bool SEflag=false;
	cin >> Syear >> Smonth >> Sday;
	cin >> Eyear >> Emonth >> Eday;
	if (Syear + 1000 < Eyear) SEflag = true;
	else if (Syear + 1000 == Eyear) {
		if (Smonth < Emonth) SEflag = true;
		else if (Smonth == Emonth && Sday <= Eday) SEflag = true;
	}

	if (!SEflag) {
		long long SS = countDay(Syear, Smonth, Sday);
		long long EE = countDay(Eyear, Emonth, Eday);
		cout << "D-" << EE-SS << '\n';
	}
	else cout << "gg\n";

	return 0;
}