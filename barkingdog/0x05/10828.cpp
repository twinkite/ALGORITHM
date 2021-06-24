#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        if(s=="push"){
            int X;
            cin>>X;
            dat[pos++]=X;
        } else if(s=="pop"){
            if(pos==0) cout<<-1<<'\n';
            else { cout<<dat[pos-1]<<'\n'; pos--;}
        } else if(s=="size"){
            cout<<pos<<'\n';
        } else if(s=="empty"){
            if(pos==0) cout<<1<<'\n';
            else cout<<0<<'\n';
        } else if(s=="top"){
            if(pos==0) cout<<-1<<'\n';
            else cout<<dat[pos-1]<<'\n';
        }
    }

    return 0;
}