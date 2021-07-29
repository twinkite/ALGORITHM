#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int N, K;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>K;
  queue<int> q;
  q.push(N);
  fill(arr, arr+100001, -1);
  arr[N]=0;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(cur == K) {cout<< arr[cur]; return 0;}
    if(cur+1 <= 100000 && arr[cur+1]<0){
      q.push(cur+1);
      arr[cur+1] = arr[cur]+1;
    }
    if(cur-1 >= 0 && arr[cur-1]<0){
        q.push(cur-1);
        arr[cur-1] = arr[cur]+1;
    }
    if(cur*2 <= 100000 && arr[cur*2]<0){
        q.push(cur*2);
        arr[cur*2] = arr[cur]+1;
    }
  }
}