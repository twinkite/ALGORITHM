#include <bits/stdc++.h>
using namespace std;

int ans;
int temp;
deque<int> dr;
deque<int> dl;

int rightTurn (int num){
  int ret = 0;
  while(dr.front()!=num){
    dr.push_front(dr.back());
    dr.pop_back();
    ret++;
  }
  dr.pop_front();
  return ret; 
}

int leftTurn(int num){
  int ret = 0;
  while(dl.front()!=num){
    dl.push_back(dl.front());
    dl.pop_front();
    ret++;
  }
  dl.pop_front();
  return ret;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M, temp;
  cin >> N >> M;
  for(int i=1;i <= N;i++){
    dr.push_back(i);
    dl.push_back(i);
  }
  for(int i=0; i<M; i++){
    cin >> temp;
    int right = rightTurn(temp);
    int left = leftTurn(temp);
    ans += (right<left) ? right : left;
  }
  cout<<ans;
  return 0;
}