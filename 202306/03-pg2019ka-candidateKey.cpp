//2019 카카오 코테 Lv.2
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int used;
    int cnt;
};

bool operator>(node a, node b){
    if(a.cnt==b.cnt) return a.used>b.used;
    return a.cnt>b.cnt;
}

int countOnes(int num){
    int cnt=0;
    while(num!=0){
        cnt+=(num%2);
        num/=2;
    }
    return cnt;
}

int solution(vector<vector<string>> relation) {
    //initialize;
    int cnt=0;
    int cLim=relation.size();
    int rLim=relation[0].size();
    set<string> St;
    vector<int> test;
    vector<bool> used;
    
    for(int r=0;r<rLim;r++){
        St.clear();
        for(int c=0;c<cLim;c++){
            St.insert(relation[c][r]);
        }
        if(St.size()!=cLim) test.push_back(r);
        else cnt++;
    }
    
    priority_queue<node, vector<node>, greater<node>> pq;
    queue<node> Qu;
    
    for(int i=1;i<(1<<test.size());i++) pq.push({i,countOnes(i)});
    while(!pq.empty()){
        node now=pq.top();
        pq.pop();
        Qu.push(now);
    }
    
    while(!Qu.empty()){
        node now=Qu.front();
        Qu.pop();
        
        //isValid
        St.clear();
        used.clear();
        
        int num=now.used;
        for(int i=0;i<test.size();i++){
            if((num%2)==1) used.push_back(true);
            else used.push_back(false);
            num/=2;
        }
        
        for(int c=0;c<cLim;c++){
            string temp="";
            for(int i=0;i<used.size();i++){
                if(!used[i]) continue;
                temp.append(relation[c][test[i]]);
                temp.push_back('|');    
            }
            St.insert(temp);
        }
        
        if(St.size()==cLim) {
            cnt++;
            num=Qu.size();
            for(int i=0;i<num;i++){
                node next=Qu.front();
                Qu.pop();
                cout<<next.used<<' ';
                if((now.used | next.used) != next.used){
                    Qu.push(next);
                }
            }
        }
        
    }
    
    
    return cnt;
}