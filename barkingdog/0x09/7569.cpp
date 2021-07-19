#include <bits/stdc++.h>
#define tiii tuple<int,int,int> 
using namespace std;

int m, n, h;
int dx[7]={0,0,0,0,1,-1};
int dy[7]={0,0,1,-1,0,0};
int dz[7]={1,-1,0,0,0,0};
int arr[105][105][105];
int dist[105][105][105];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  queue<tiii> q;

  cin>>m>>n>>h;
  for(int i=0; i<h; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<m; k++){
        cin>>arr[i][j][k];
        if(arr[i][j][k] == 1){
          q.push(make_tuple(i,j,k));
        }
        if(arr[i][j][k] == 0){
          dist[i][j][k] = -1 ;
        }
      }
    }
  }
  while(!q.empty()){
    int x, y, z;
    tiii cur = q.front();
    tie(z,x,y) = cur;
    q.pop();
    for(int i=0;i<6;i++){
      int nz = z+dz[i];
      int nx = x+dx[i];
      int ny = y+dy[i];
      if( nz<0 || nx<0 || ny<0 || nz>=h || nx>=n || ny>=m ) continue;
      if( dist[nz][nx][ny] >= 0 ) continue;
      dist[nz][nx][ny] = dist[z][x][y]+1;
      q.push(make_tuple(nz,nx,ny));
    }
  }
  int ans=0;
  for(int i=0; i<h; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<m; k++){
        if(dist[i][j][k] == -1)
        {
          cout<< -1;
          return 0;
        }
        ans = max( dist[i][j][k], ans);
      }
    }
  }
  cout<<ans;
  return 0;
}