//Silver 3. 문자열 비교
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool strComp(string I, string T) {
	for (int i = 0; i < 3; i++) {
		if (T[i] == '#' && I[i] == '.') return false;
	}
	return true;
}

vector<vector<string>> Map(0);

int strNum(vector<string> a) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 5; k++) {
			if (!strComp(Map[i][k], a[k])) break;
			if (k == 4) {
				return i;
			}
		}
	}
	return -1;

}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Map.push_back({ "###","#.#","#.#","#.#","###" }); //0
	Map.push_back({ "..#","..#","..#","..#","..#" }); //1
	Map.push_back({ "###","..#","###","#..","###" }); //2
	Map.push_back({ "###","..#","###","..#","###" }); //3
	Map.push_back({ "#.#","#.#","###","..#","..#" }); //4
	Map.push_back({ "###","#..","###","..#","###" }); //5
	Map.push_back({ "###","#..","###","#.#","###" }); //6
	Map.push_back({ "###","..#","..#","..#","..#" }); //7
	Map.push_back({ "###","#.#","###","#.#","###" }); //8
	Map.push_back({ "###","#.#","###","..#","###" }); //9

	vector<vector<string>> Target(4,vector<string>(0));
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 4; i++) {
			string str;
			cin >> str;
			Target[i].push_back(str);
		}
	}

	string ans;
	ans.push_back('0' + strNum(Target[0]));
	ans.push_back('0' + strNum(Target[1]));
	ans.push_back(':');
	ans.push_back('0' + strNum(Target[2]));
	ans.push_back('0' + strNum(Target[3]));

	cout << ans << '\n';

	return 0;
}