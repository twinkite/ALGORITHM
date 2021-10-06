#include <bits/stdc++.h>
using namespace std;

int N, M, K, r, c, ans, cnt;
bool laptop[41][41];
bool sticker[11][11];
bool temp[11][11];

void rotate(){
  memset(temp, 0, sizeof(temp));
  for(int i=0;i<c; i++){
    for(int j=0;j<r;j++){
      temp[i][j]=sticker[r-1-j][i];
    }
  }
  memset(sticker, 0, sizeof(sticker));
   for(int i=0;i<c; i++){
    for(int j=0;j<r;j++){
      sticker[i][j]=temp[i][j];
    }
  }
  int temp =r;
  r=c;
  c=temp;
}

bool stick(int x, int y){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(laptop[x+i][y+j]==1&&sticker[i][j]==1) return false;
    }
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(!laptop[x+i][y+j]&&sticker[i][j]) {
        laptop[x+i][y+j]=1;
        ans++;
      }
    }
  }
  return true;
}

void start(){
  int i=0,j=0,k=0;
  bool chk = false;
  while(!chk&&k<4){
    i=0;j=0;
    while(!chk&&(i<=N-r&&j<=M-c)){
      chk = stick(i,j);
      if(j==M-c){
        i+=1; j=0;
      } else {
        j++;
      }
    }
    if(!chk) rotate();
    k++;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>M>>K;
  for(int i=0;i<K;i++){
    cin>>r>>c;
    cnt=0;
    memset(sticker, 0, sizeof(sticker));
    for(int j=0;j<r;j++){
      for(int k=0;k<c;k++){
        cin>>sticker[j][k];
        if(sticker[j][k]) cnt++;
      }
    }
    start();
  }
 

  cout<<ans;
  return 0;
}