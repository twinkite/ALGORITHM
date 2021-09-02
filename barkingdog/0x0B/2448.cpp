#include <bits/stdc++.h>
using namespace std;

int N;
char arr[4000][8000];

void star(int x,int y,int n){
  if(n==3){
    for(int i=0;i<3;i++){
      for(int j=-i;j<=i;j++){
        if(i==1&&j==0) continue; 
        arr[x+i][y+j]='*';
      }
    }
  } else {
    star(x, y, n/2);
    star(x+n/2, y-n/2, n/2);
    star(x+n/2,y+n/2, n/2);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0; i<N; i++)
  memset(arr[i], ' ', 2*N*sizeof(char));
  star(0,N-1,N);
  for(int i=0;i<N;i++){
    for(int j=0;j<2*N;j++){
      cout<<arr[i][j];
    }
    cout<<'\n';
  }
}