#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin>>T;
  while(T--){
    string s, dq;
    deque<int> d;
    int n;
    cin >> s >> n >> dq;
    string temp="";
    for(int i=1; i< dq.size(); i++){
      if(dq[i] == ','|| dq[i]==']'){
        if(temp!="") {d.push_back(stoi(temp));}
        temp="";
      }else if(dq[i] >= '0' || dq[i] <= '9'){
        temp+=dq[i];
      }
    }
    bool front = true;
    bool err = false;
    for(int i=0;i<s.size(); i++){
      if(s[i] == 'R'){
        if(front) { front=false; }
        else { front=true; }
      } else if(s[i] == 'D'){
          if(d.empty()){
            err = true;
            break;
          } else if(front) { d.pop_front(); 
          } else { d.pop_back();}
      }
    }
    if(err) cout<<"error"<<'\n';
    else{
      if(front){
        cout<<'['; 
        if(!d.empty()){
          cout<<d.front();
          d.pop_front();
        } 
        while(!d.empty()){
          cout<<','<<d.front();
          d.pop_front();
        }
        cout<<']'<<'\n';
      } else {
        cout<<'[';
        if(!d.empty()) {
          cout<<d.back();
          d.pop_back();
        }while(!d.empty()){
          cout<<','<<d.back();
          d.pop_back();
        }
        cout<<']'<<'\n';
      }
    }
  }
  return 0;
}