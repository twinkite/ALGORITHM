#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int dx[5]={ 1, 0, -1, 0 };
int dy[5]={ 0, 1, 0, -1 };
int n, m;
int arr[505][505];
bool visited[505][505];
queue<pii> q;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr[i][j];
    }
  }
  int max = 0, count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0 ;j < m; j++){
      int temp=0;
      if(arr[i][j] && !visited[i][j]){
        visited[i][j]=1;
        q.push({i,j});
        count++;
        while(!q.empty()){
          pii cur = q.front();
          q.pop();
          temp++;
          for(int k=0;k<4;k++){
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(visited[nx][ny] || !arr[nx][ny]) continue;
            visited[nx][ny]=1;
            q.push({nx,ny});
          }
        }
        max = (temp > max) ? temp : max ;
      }
    }
  }
  cout<< count << '\n' << max ;

}