#include <bits/stdc++.h>
using namespace std;

int N;
int arr[3000][3000];
int sum[3];

void paper(int x, int y, int n){
  int idx = arr[x][y]+1;
  if(n==1) {
    sum[idx]+=1;
    return ;
  } else {
    bool chk=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(arr[x][y]==arr[x+i][y+j]) continue;
        chk=false;
        break;
        
      }
      if(!chk) break;
    }
    if(chk) sum[idx]+=1;
    else{
      paper(x, y, n/3);
      paper(x, y+n/3,n/3);
      paper(x, y+2*n/3, n/3);
      
      paper(x+n/3, y, n/3);
      paper(x+n/3, y+n/3,n/3);
      paper(x+n/3, y+2*n/3, n/3);
    
      paper(x+2*n/3, y, n/3);
      paper(x+2*n/3, y+n/3,n/3);
      paper(x+2*n/3, y+2*n/3, n/3);
    }


  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
    }
  }
  paper(0,0,N);
  cout<<sum[0]<<'\n'<<sum[1]<<'\n'<<sum[2];
}