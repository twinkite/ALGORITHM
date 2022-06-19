#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, M;
vector<int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>K>>M;
    int t;
    v = vector<int> (N);
    for(int i=0;i<N;i++){
        cin>>t;
        v[i]=i+1;
    }

    for(int j=0;j<M;j++){
        cin>>t;
        if(t>0){
            reverse(v.begin(), v.begin()+t);
        } else {
            t= -t;
            reverse(v.end()-t, v.end());
        }
    }

    for(int i=0;i<N;i++){
        if(v[i]==K){
            cout<<i+1; break;
        }
    }
    return 0;
}