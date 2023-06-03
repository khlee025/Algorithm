//Bronz 4. 문자열 처리
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str;
    cin>>str;
    vector<int> Num(26,0);
    for(int i=0;i<str.size();i++){
        Num[str[i]-'a']++;
    }
    for(int i=0;i<26;i++) cout<<Num[i]<<' ';
    
    return 0;
}