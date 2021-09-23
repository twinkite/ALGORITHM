#include <bits/stdc++.h>
using namespace std;

int N, max;
int arr[11][11];

void bishop(int x, int y, int m){
  if(x==N-1&&y==N-1) {max=(max>m)?max:m; return;}
  if(arr[x][y]==0){
    (y!=N-1)? bishop(x, y+1, m):bishop(x+1,0,m);
  } else {
    bool chk=true;
    for(int i=-N+1;i<N;i++){
      for(int j=-N+1;j<N;j++){
        if(x+i>=N||x+i<0||y+j>=N||y+j<0) continue;
        if(arr[x+i][y+j]==-1) {
          chk=false;
          break; 
        }
        if(x-i>=N||x-i<0) continue;
        if(arr[x-i][y+j]==-1) {
          chk=false;
          break; 
        }
      }
      if(!chk) break;
    }
    if(chk){
      arr[x][y]=-1;
      (y!=N-1)? bishop(x, y+1, m+1):bishop(x+1,0,m+1);
      arr[x][y]=1;
      (y!=N-1)? bishop(x, y+1, m):bishop(x+1,0,m);
    } else {
      (y!=N-1)? bishop(x, y+1, m):bishop(x+1,0,m);  
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][i];
    }
  }
  bishop(0,0,0);
  cout<<max;


}