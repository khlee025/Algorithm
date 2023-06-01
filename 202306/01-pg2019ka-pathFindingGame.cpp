#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct pt{
    int x;
    int y;
    int idx;
};

bool operator>(pt a, pt b){
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}

struct node{
    int x;
    int Lidx;
    int Ridx;
    int idx;
};

vector<node> graph;
vector<int> ans;

void rec_front(int idx){
    ans.push_back(graph[idx].idx);
    
    if(graph[idx].Lidx!=-1) rec_front(graph[idx].Lidx);
    if(graph[idx].Ridx!=-1) rec_front(graph[idx].Ridx);
}

void rec_back(int idx){
    if(graph[idx].Lidx!=-1) rec_back(graph[idx].Lidx);
    if(graph[idx].Ridx!=-1) rec_back(graph[idx].Ridx);
    
    ans.push_back(graph[idx].idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    //order
    priority_queue<pt, vector<pt>, greater<pt>> pq;
    for(int i=0;i<nodeinfo.size();i++){
        pq.push({nodeinfo[i][0],nodeinfo[i][1],i+1});
    }
    
    
    for(int i=0;i<nodeinfo.size();i++){
        pt now=pq.top();
        pq.pop();
        graph.push_back({now.x,-1,-1,now.idx});
        
        bool flag=false;
        int pos=0;
        if(i==0) flag=true;
        while(!flag){
            if(graph[pos].x>now.x){
                if(graph[pos].Lidx==-1){
                    graph[pos].Lidx=i;
                    flag=true;
                }
                else pos=graph[pos].Lidx;
            }
            else{
                if(graph[pos].Ridx==-1){
                    graph[pos].Ridx=i;
                    flag=true;
                }
                else pos=graph[pos].Ridx;
            }
        }
    }
    vector<vector<int>> answer;
    rec_front(0);
    answer.push_back(ans);
    ans.clear();
    
    rec_back(0);
    answer.push_back(ans);
    ans.clear();
    
    
    return answer;
}