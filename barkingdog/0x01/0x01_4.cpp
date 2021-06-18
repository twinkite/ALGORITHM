#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, res=1;
    cin>>N;
    while(res*2<=N){
        res*=2;
    }
    cout<<res;
    return 0;
}