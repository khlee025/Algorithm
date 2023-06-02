//Bronz 4. 수학
#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int L, A, B, a, b;
    cin>>L>>A>>B>>a>>b;
    int Aa, Bb;
    
    Aa=A/a;
    if(A%a!=0) Aa+=1;
    Bb=B/b;
    if(B%b!=0) Bb+=1;
    
    if(Aa>Bb) cout<<L-Aa<<'\n';
    else cout<<L-Bb<<'\n';
    return 0;
}