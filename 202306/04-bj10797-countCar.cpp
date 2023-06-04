//Bronz 4. 갯수 세기

#include<iostream>
using namespace std;

int main(){
    int N;
    int cnt=0;
    int car;
    cin>>N;
    for(int i=0;i<5;i++){
        cin>>car;
        if(N==car) cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}