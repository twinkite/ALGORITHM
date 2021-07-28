#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first 
#define y second
using namespace std;

int R, C;
char arr[1006][1010];
int dist[1002][1002];
int burn[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>R>>C;
  string s;
  queue<pii> jihoon;
  queue<pii> fire;

  for(int i=0; i<R; i++){
    cin>>s;
    for(int j=0; j<C; j++){
      arr[i][j] = s[j];
      if(arr[i][j]=='.'){
        dist[i][j]=-1;
        burn[i][j]=-1;
      }if(arr[i][j]=='J'){
        burn[i][j]=-1;
        jihoon.push({i,j});
      }if(arr[i][j]=='F'){
        fire.push({i,j});
      }
    }
  }

  while(!fire.empty()){
    pii cur = fire.front();
    fire.pop();

    for(int i=0;i<4; i++){    
      int nx = cur.x+dx[i];
      int ny = cur.y+dy[i];
      if(nx<0||ny<0||nx>=R||ny>=C) continue;
      if(burn[nx][ny] >=0) continue;
      burn[nx][ny] = burn[cur.x][cur.y] + 1;
      fire.push({nx,ny});
    }
  }
  
  while(!jihoon.empty()){
    pii cur = jihoon.front();
    jihoon.pop();
    
    for(int i=0; i<4; i++){
      int nx = cur.x+dx[i];
      int ny = cur.y+dy[i];
      if(nx<0||ny<0||nx>=R||ny>=C){ 
        cout<<dist[cur.x][cur.y]+1;
        return 0;
      }
      if(dist[nx][ny] >=0 || burn[nx][ny]!=-1 && burn[nx][ny] <= dist[cur.x][cur.y]+1 ) continue;
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
      jihoon.push({nx,ny});
    }
  }
  cout<<"IMPOSSIBLE";
  return 0;
}