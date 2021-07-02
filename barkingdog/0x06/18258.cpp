#include <bits/stdc++.h>
using namespace std;

int arr[2000020];
int front, back;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    string s; cin>>s;
    if(s == "push"){
      int X; cin>>X;
      arr[back++]=X;
    } else if (s=="pop"){
      if(front==back) cout<<-1<<'\n';
      else cout<<arr[front++]<<'\n';
    } else if (s=="size"){
      cout << back-front <<'\n';
    } else if (s=="front"){
      if(front==back) cout<<-1<<'\n';
      else cout<<arr[front]<<'\n';
    } else if (s=="back"){
      if(front==back) cout<<-1<<'\n';
      else cout<<arr[back-1]<<'\n';
    } else if (s=="empty"){
      if(front==back) cout<<1<<'\n';
      else cout<<0<<'\n';
    }
  }
}