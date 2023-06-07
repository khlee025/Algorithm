//Lv.1 정렬, 구현, 실수 처리
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    int stage;
    float percent;
};

bool operator<(node a, node b){
    if(a.percent==b.percent) return a.stage<b.stage;
    return a.percent>b.percent;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(),stages.end());
    
    vector<node> res;
    int all=stages.size();
    int Clear=0;
    
    for(int i=1;i<stages[0];i++) res.push_back({i,0});
    
    int now=stages[0];
    for(int i=0;i<stages.size();i++){
        if(now==stages[i]) Clear++;
        else{
            res.push_back({now, (float)Clear/all});
            all-=Clear;
            Clear=0;
            now++;
            i--;
        }
    }
    if(stages[stages.size()-1]<=N) res.push_back({stages[stages.size()-1],1});
    for(int i=stages[stages.size()-1]+1;i<=N;i++) res.push_back({i,0});
    
    sort(res.begin(),res.end());
    vector<int> answer;
    for(int i=0;i<res.size();i++){
        answer.push_back(res[i].stage);
    }
    
    
    return answer;
}