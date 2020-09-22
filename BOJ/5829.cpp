#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N, M, F, S;
long long K;
pii visited[1004];
vector<vector<int>> river;  
vector<int> seq;

int sailing(int port){
    int i=0;
        while(i<K){
            for(int j=0;j<M;j++){
                port=river[port][seq[j]];
            }
            i++;
            if(visited[port].first==1){
                F=visited[port].second;
                S=i;
                break;
            }
            visited[port].first=1;  // 방문체크
            visited[port].second=i; // 몇번째 반복에 오게되는지 체크
        }
        if(i!=K){
            K=K-i;
            K=K%(S-F);  // S-F : 사이클의 길이. K가 최대 10^9이므로 %연산.
            while(K--){
                for(int j=0;j<M;j++){
                    port=river[port][seq[j]];
                }
            }
    }
    return port;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M>>K;
    river=vector<vector<int>>(N+2,vector<int> (2));
    int L,R;
    for(int i=1;i<=N;i++){
        cin>>L>>R;
        river[i][0]=L;
        river[i][1]=R; 
    }
    char temp;
    for(int i=0;i<M;i++){
        cin>>temp;
        if(temp=='L')seq.push_back(0);
        else seq.push_back(1);
    }  
    cout<<sailing(1);
}