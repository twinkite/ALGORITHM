#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};
int N, r, c;

int T = 0;
void route(int row, int col, int n){
  if(n==2){
    for(int i=0;i<4;i++){
      if(r==row+dx[i] && c == col+dy[i]) {
        cout<<T; return;
      } else T++; 
    }
  } else {
    if(r<row+n/2 && c<col+n/2){
      route(row, col, n/2); return;
    } else { T += (n/2)*(n/2); }
    if(r<row+n/2 && c<col+n) {
      route(row, col+(n/2) , n/2); return ;
    } else { T += (n/2)*(n/2); }
    if(r<row+n && c<col+n/2) {
      route(row+(n/2), col, n/2); return ;
    } else { T += (n/2)*(n/2); }
    if(r<row+n && c<col+n) {
      route(row+(n/2), col+(n/2), n/2); return ;
    } else { T += (n/2)*(n/2); }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>r>>c;
  route(0,0,pow(2,N));
}