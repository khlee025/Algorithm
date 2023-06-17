//열쇠와 자물쇠
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int key_cnt = 0;
int lock_cnt = 0;
int N, M;

vector<vector<vector<int>>> keys(0);
vector<vector<int>> locks(0);

bool isValid(int i, int dX, int dY) {
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            int rx=x-dX;
            int ry=y-dY;
            if (ry >= M || ry < 0 || rx >= M || rx < 0) {
                if (locks[y][x] == 0) return false;
            }
            else if (locks[y][x] == 1 && keys[i][ry][rx] == 1) return false;
            else if (locks[y][x] == 0 && keys[i][ry][rx] == 0) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();

    //init
    keys.resize(4, vector<vector<int>>(M,vector<int>(M,0)));
    locks.resize(N, vector<int>(N, 0));

    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < M; y++) {
            for (int x = 0; x < M; x++) {
                if (i == 0) keys[i][y][x] = key[y][x];
                else keys[i][y][x] = keys[i - 1][M - 1 - x][y];
                if (i == 1 && keys[i][y][x] == 1) key_cnt++;
            }
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (lock[y][x] == 1) lock_cnt++;
            locks[y][x] = lock[y][x];
        }
    }

    if ((lock_cnt + key_cnt) < (N * N)) return false;
    if (lock_cnt == (N * N)) return true;

    for(int i=0;i<4;i++){
        for(int y=-(M-1);y<N;y++){
            for(int x=-(M-1);x<N;x++){
                if(isValid(i,x,y)) return true;
            }
        }
    }

    return false;
}
