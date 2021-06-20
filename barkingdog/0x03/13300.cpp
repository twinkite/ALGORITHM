#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double arr[7][2];
    for(int i=0;i<7;i++){
        fill(arr[i], arr[i]+2,0);
    }
    int N, S, Y, res=0;
    double K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>S>>Y;
        arr[Y][S]+=1;
    }
    for(int i=1;i<7;i++){
        res+=ceil(arr[i][0]/K);
        res+=ceil(arr[i][1]/K);
    }
    cout<<res;
    return 0;
}