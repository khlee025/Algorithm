//Lv.3 HTML Parsing.

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct node{
    int WordCount;
    int LinkCount;
    double linkscore;
    double Score;
    vector<int> idxList;
};

unordered_map<string, int> um;

string nowPage(string s){
    int st=s.find("<meta property=\"og:url\" content=\"");
    st+=33;
    s=s.substr(st);
    int ed=s.find("\"");
    return s.substr(0,ed);
}
string bodyContents(string s){
    int st=s.find("<body>");
    st+=7;
    s=s.substr(st);
    int ed=s.find("</body>");
    ed-=1;
    return s.substr(0,ed);
}
vector<int> includePage(string s){
    vector<int> res;
    vector<string> P;
    int st=s.find("<a href=");
    while(st!=string::npos){
        st+=9;
        s=s.substr(st);
        int ed=s.find("\"");
        P.push_back(s.substr(0,ed));
        st=s.find("<a href=");
    }
    
    for(int i=0;i<P.size();i++) {
        res.push_back(um[P[i]]);
    }
    
    return res;
}
int countWord(string s, string word){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
    }
    
    for(int i=0;i<word.size();i++){
        if(word[i]>='A' && word[i]<='Z') word[i]=word[i]-'A'+'a';
    }
    
    
    int cnt=0;
    int st=s.find(word);
    int len=word.size();

    while(st!=string::npos){
        if(st>0){
            if(s[st-1]<'a' || s[st-1]>'z') s=s.substr(st);
        }
        
        if(s[len]<'a' || s[st-1]>'z') cnt++;
        s=s.substr(len);
        
        if(s[0]>='a' && s[0]<='z'){
            for(int i=0;i<s.size();i++){
                if(s[i]<'a' || s[i]>'z'){
                    s=s.substr(i);
                    break;
                }
            }
        }
        st=s.find(word);
    }
    //cout<<cnt;
    return cnt;
}

int solution(string word, vector<string> pages) {
    for(int i=0;i<pages.size();i++){
        string now=nowPage(pages[i]);
        um[now]=i+1;
    }
    vector<node> Ps;
    for(int i=0;i<pages.size();i++){
        string body=bodyContents(pages[i]);
        vector<int> idxList=includePage(body);
        int wordcount=countWord(body, word);
        int num=idxList.size();
        Ps.push_back({wordcount, num, 0, 0, idxList});
    }
    
    for(int i=0;i<Ps.size();i++){
        if(Ps[i].WordCount==0) continue;
        Ps[i].linkscore=(double)Ps[i].WordCount/Ps[i].LinkCount;
    }
    for(int i=0;i<Ps.size();i++){
        Ps[i].Score+=Ps[i].WordCount;
        for(int k=0;k<Ps[i].idxList.size();k++){
            if(Ps[i].idxList[k]==0) continue;
            Ps[Ps[i].idxList[k]-1].Score+=Ps[i].linkscore;
        }
        
    }
    int ans=0;
    for(int i=1;i<Ps.size();i++){
        if(Ps[ans].Score<Ps[i].Score) ans=i;
    }
    
    return ans;
}