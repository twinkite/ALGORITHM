#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  queue<int> q;
  int N;
  cin>>N;
  for(int i=1;i<=N;i++){
    q.push(i);
  }
  int i=0;
  while(q.size()!=1){
    if(i%2 == 0) q.pop();
    else {
      q.push(q.front());
      q.pop();
    }
    i++;
  }
  cout<<q.front();
  return 0;
}