#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

int N, ans;
vector<pii> v;  // {내구도, 무게}

void egg(int idx, int cnt){  
  if(idx==N||cnt>=N-1){
    if(ans<cnt){
      ans=cnt;
    }
    return;
  } 
  if(v[idx].x<=0) {
    egg(idx+1, cnt);
  } else {
    for(int i=0;i<N;i++){
      if(i==idx) continue;
      if(v[i].x<=0) continue;
      v[i].x-=v[idx].y;
      v[idx].x-=v[i].y;
      if(v[i].x<=0&&v[idx].x<=0) egg(idx+1, cnt+2);
      else if(v[i].x<=0||v[idx].x<=0) egg(idx+1, cnt+1);
      else egg(idx+1, cnt);
      v[i].x+=v[idx].y;
      v[idx].x+=v[i].y;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;
  v.resize(N);
  for(int i=0;i<N;i++){
    cin>>v[i].x>>v[i].y;
  }
  egg(0,0);
  cout<<ans;

  return 0;
}