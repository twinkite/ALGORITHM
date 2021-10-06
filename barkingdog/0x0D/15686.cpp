#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int N, M, h, k,ans =0x7f7f7f7f;
int city[51][51];
vector<pii> chicken;
vector<pii> home;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>city[i][j];
      if(city[i][j]==2){
        chicken.push_back({i,j});
      } else if(city[i][j]==1){
        home.push_back({i,j});
      }
    }
  }

  vector<int> brute(chicken.size(), 1);
  fill(brute.begin(), brute.begin()+chicken.size()-M, 0);
  do{
    int dist=0;
    for(auto h: home){
      int tmp = 0x7f7f7f;
      for(int i=0;i<chicken.size();i++){
        if(brute[i]==0) continue;
        tmp = min(tmp,abs(chicken[i].x-h.x)+abs(chicken[i].y-h.y));
      }
      dist+=tmp;
    }
    ans = min(dist, ans);
  }while(next_permutation(brute.begin(), brute.end()));
  cout<<ans;

  return 0;
}