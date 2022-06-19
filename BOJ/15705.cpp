#include <iostream>
#include <string>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,-1,1,-1,1};

string s;
int N, M;

string arr[100];

bool dfs(int curx, int cury, int cnt, int dir){
    if(cnt == s.size()) return true;
    int nx = curx+dx[dir];
    int ny = cury+dy[dir];
    if(nx<0||ny<0||nx>=N||ny>=M) return false;
    bool chk = false;
    if(arr[nx][ny]==s[cnt]){
        chk = dfs(nx,ny, cnt+1, dir);
    }
    return chk;
}

bool search(int curx, int cury){
    for(int i=0;i<8;i++){
        if(dfs(curx, cury, 1, i)) return true;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==s[0]){
                if(search(i,j)){
                    cout<<1;
                    return 0;
                }
            }
        }
    }
    cout<<0;
    return 0;
}