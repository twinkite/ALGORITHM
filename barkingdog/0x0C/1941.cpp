#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string arr[5];
bool visited[25];
bool checked[5][5];
int ans=0;

bool moreThanFour(){
  int cnt=0;
  for(int i=0;i<25;i++){
    if(visited[i]&&arr[i/5][i%5]=='S'){
      cnt++;
    }
  }
  if(cnt>=4) return true;
  else return false;
}

bool nearBy(){
  queue<pair<int,int>> q;
  memset(checked, false, sizeof(checked));
  for(int i=0;i<25;i++){
    if(visited[i]){
      q.push({i/5,i%5});
      break;
    }
  }

  int cnt=1;
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    checked[x][y]=true;
    q.pop();

    if(cnt==7) return true;
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<0||ny<0||nx>=5||ny>=5) continue;
      if(checked[nx][ny]||!visited[nx*5+ny]) continue;
      q.push({nx,ny});
      checked[nx][ny]=true;
      cnt++;
    }
  }
  return false;
}

void dfs(int idx, int cnt){
  if(cnt==7){
    if(moreThanFour() && nearBy()) ans++;
    return ;
  } else {
    for(int i = idx; i<25;i++){
      if(!visited[i]){
        visited[i]=true;
        dfs(i, cnt+1);
        visited[i]=false;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0;i<5;i++){
    cin>>arr[i];
  }
  dfs(0,0);
  cout<<ans;
}