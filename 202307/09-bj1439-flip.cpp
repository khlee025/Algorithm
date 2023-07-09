//Silver 5. 뒤집기
#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    int zero=0;
    int one=0;
    cin>>str;
    
    if(str[0]=='0') zero++;
    else one++;
    
    for(int i=1; i<str.size(); i++){
        if(str[i]!=str[i-1]){
            if(str[i]=='0') zero++;
            else one++;
        }
    }

    if(zero<one) cout<<zero;
    else cout<<one;
    
    return 0;
}