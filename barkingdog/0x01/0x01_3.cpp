#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, res=0;
    cin>>N;
    for(int i=1;i*i<=N;i++){
        if(i*i == N) res=1; 
    }
    cout<<res;

}