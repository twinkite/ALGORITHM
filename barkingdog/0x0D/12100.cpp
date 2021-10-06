#include <bits/stdc++.h>
using namespace std;

int N,ans ; 
int board[21][21];
int arr[21][21];
queue<int> q;

void turn(int dir){
  if(dir==1){ // <-
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(board[i][j])q.push(board[i][j]);
        board[i][j]=0;
      }
      int temp=0, j=0;      
      while(!q.empty()){
        if(temp==0) {
          temp=q.front();
          q.pop();
        } else if (temp!=0 && temp==q.front()){
          board[i][j++]=temp*2;
          temp=0;
          q.pop();
        } else {
          board[i][j++]=temp;
          temp=q.front();
          q.pop();  
        }
      }
      if(temp!=0) board[i][j]=temp;
    }
  } else if(dir==2){ // 아래
    for(int i=0;i<N;i++){
      for(int j=N-1;j>=0;j--){
        if(board[j][i])q.push(board[j][i]);
        board[j][i]=0;
      }
      int temp=0, j=N-1;      
      while(!q.empty()){
        if(temp==0) {
          temp=q.front();
          q.pop();
        } else if (temp!=0 && temp==q.front()){
          board[j--][i]=temp*2;
          temp=0;
          q.pop();
        } else {
          board[j--][i]=temp;
          temp=q.front();
          q.pop();  
        }
      }
      if(temp!=0) board[j][i]=temp;
    }
  } else if(dir==3){ // ->
    for(int i=0;i<N;i++){
      for(int j=N-1;j>=0;j--){
        if(board[i][j])q.push(board[i][j]);
        board[i][j]=0;
      }
      int temp=0, j=N-1;      
      while(!q.empty()){
        if(temp==0) {
          temp=q.front();
          q.pop();
        } else if (temp!=0 && temp==q.front()){
          board[i][j--]=temp*2;
          temp=0;
          q.pop();
        } else {
          board[i][j--]=temp;
          temp=q.front();
          q.pop();  
        }
      }
      if(temp!=0) board[i][j]=temp;
      temp=0;
    }
  } else if(dir==0){ // 위
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(board[j][i]) {
          q.push(board[j][i]);
          board[j][i]=0;
          }
      }
      int temp=0, j=0;      
      while(!q.empty()){
        if(temp==0) {
          temp=q.front();
          q.pop();
        } else if (temp!=0 && temp==q.front()){
          board[j++][i]=temp*2;
          temp=0;
          q.pop();
        } else {
          board[j++][i]=temp;
          temp=q.front();
          q.pop();  
        }
      }
      if(temp!=0) board[j][i]=temp;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
    }
  }
  for(int tmp=0; tmp<1024; tmp++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        board[i][j]=arr[i][j];
      }
    }
    int brute = tmp;
    for(int i=0;i<5;i++){
      int dir = brute%4;
      brute /=4;
      turn(dir);
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        ans=board[i][j]>ans?board[i][j]:ans;
      }
    }
  }
  cout<<ans;
  return 0;
}