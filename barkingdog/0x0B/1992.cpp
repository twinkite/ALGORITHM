#include <bits/stdc++.h>
using namespace std;

int N;
string arr[100];

void quad(int x, int y, int n){
  if(n==1) cout<<arr[x][y];
  else {
    char first=arr[x][y];
    bool chk=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(first!=arr[x+i][y+j]){
            chk=false;
            break;
        }
      }
      if(!chk) break;
    }
    if(chk) cout<<first;
    else {
      cout<<"(";
      quad(x, y,n/2);
      quad(x, y+n/2, n/2);
      quad(x+n/2, y, n/2);
      quad(x+n/2, y+n/2, n/2);
      cout<<')';
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  quad(0,0,N);
}