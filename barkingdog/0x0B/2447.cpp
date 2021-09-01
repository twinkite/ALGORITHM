#include <bits/stdc++.h>
using namespace std;

int N;
char arr[7000][7000];

void star( int x, int y, int n){
  if(n==0) return;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      arr[x+n+i][y+n+j] = ' ';
    }
  }
  star(x,y,n/3);
  star(x,y+n,n/3);
  star(x,y+2*n,n/3);
  star(x+n,y,n/3);
  star(x+n,y+2*n,n/3);
  star(x+2*n,y,n/3);
  star(x+2*n,y+n,n/3);
  star(x+2*n,y+2*n,n/3);

}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;
  
  for(int i=0;i<N;i++){
    memset(arr[i], '*', N*sizeof(char));
  }
  star(0, 0, N/3);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<arr[i][j];
    }
    cout<<'\n';
  }
  return 0;
}