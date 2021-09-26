#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

int office[8][8];
int arr[8][8];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pii cctv[10];
int N, M, cnt, ans=64;
void count(){
  int temp=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(arr[i][j]==0){
        temp++;
      }
    }
  }
  if(temp<ans){
    ans=temp;
  }
}

void one(int a, int b, int n,bool tf){
  int nx=a+dx[n];
  int ny=b+dy[n];
  if(tf){
    while(nx>=0&&nx<N&&ny>=0&&ny<M){
      if(arr[nx][ny]==6) break;
      if(arr[nx][ny]<1) arr[nx][ny]-=1;
      nx+=dx[n]; 
      ny+=dy[n];
    }
  } else {
    while(nx>=0&&nx<N&&ny>=0&&ny<M){
      if(arr[nx][ny]==6) break;
      if(arr[nx][ny]<0) arr[nx][ny]+=1;
      nx+=dx[n]; 
      ny+=dy[n];
    }
  }
}

void two(int a, int b, int n, bool tf){
  one(a, b, n, tf);
  one(a,b, (n+1)%4, tf);
}

void three(int a, int b, int n, bool tf){
  if(n==0){
    one(a,b,0, tf);
    one(a,b,2, tf);
  }else if(n==1){
    one(a,b,0, tf);
    one(a,b,3, tf);
  } else if(n==2){
    one(a,b,1, tf);
    one(a,b,2, tf);
  } else if(n==3){
    one(a,b,1, tf);
    one(a,b,3, tf);
  }
}

void four(int a, int b, int n, bool tf){
  one(a,b,n, tf);
  one(a,b,(n+1)%4, tf);
  one(a,b,(n+2)%4, tf);
}

void five(int a, int b, bool tf){
  one(a,b,0, tf);
  one(a,b,1, tf);
  one(a,b,2, tf);
  one(a,b,3, tf);
}

void dir(int n){
  if(n==cnt){
    count();
    return ;
  }
  int nx=cctv[n].x;
  int ny=cctv[n].y;
  if(arr[nx][ny]==1){
    for(int i=0;i<4;i++){
      one(nx,ny,i,1);
      dir(n+1);
      one(nx,ny,i,0);
    }
  } else if (arr[nx][ny]==2){
    for(int i=0;i<2;i++){
      two(nx,ny,2*i,1);
      dir(n+1);
      two(nx,ny,2*i,0);
    }
  } else if (arr[nx][ny]==3){
    for(int i=0;i<4;i++){
      three(nx,ny,i,1);
      dir(n+1);
      three(nx,ny,i,0);
    }
  } else if (arr[nx][ny]==4){
    for(int i=0;i<4;i++){
      four(nx,ny,i,1);
      dir(n+1);
      four(nx,ny,i,0);
    }
  } else if (arr[nx][ny]==5){
      five(nx,ny,1);
      dir(n+1);
      five(nx,ny,0);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>arr[i][j];
      if(arr[i][j]>0&&arr[i][j]<6){
        cctv[cnt]={i,j};
        cnt++;
      }
    }
  }

  dir(0);
  cout<<ans;
  return 0;
}