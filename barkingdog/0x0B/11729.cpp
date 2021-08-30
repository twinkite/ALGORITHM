#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int K = 0;
vector<pii> v;
void hanoi(int n, int from, int temp, int to){
  K++;
  if(n==1) v.push_back({from, to});
  else {
    hanoi(n-1,from,to,temp);
    v.push_back({from, to});
    hanoi(n-1,temp,from,to);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N; 
  cin>>N;
  hanoi(N, 1,2,3);
  cout<<K<<'\n';
  for(int i=0;i<v.size(); i++){
    cout<<v[i].x<<' '<<v[i].y<<'\n';
  }
}