#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin>>str;
  stack<pair<char,int>> s;
  stack<pair<int,int>> temp;
  bool checkRight = true;
  for(int i=0;i<str.size();i++){
    if(str[i]=='('){
      s.push({'(', i});
    } else if (str[i]=='['){
      s.push({'[', i});
    } else if (str[i]==')'){
      if(!s.empty() && s.top().x=='('){
        if(temp.empty()){
          temp.push({2, s.top().y});
        } else {
          if(temp.top().y<s.top().y){
            temp.push({2, s.top().y});
          } else {
            int t = 2;
            while(!temp.empty() && temp.top().y>s.top().y){
              t*=temp.top().x;
              temp.pop();
            }
            temp.push({t, s.top().y});
          }
          s.pop(); 
        }
      } else {
        checkRight = false; 
        break;
      }
    } else if (str[i]==']'){
      if(!s.empty() && s.top().x == '['){
        if(temp.empty()){
          temp.push({3, s.top().y});
        } else {
          if(temp.top().y<s.top().y){
            temp.push({3, s.top().y});
          } else {
            int t = 0;
            while(!temp.empty()&& temp.top().y > s.top().y){
              t+=temp.top().x;
              temp.pop();
            }
            while(!temp.empty() && temp.top().y>s.top().y){
              t*=temp.top().x;
              cout<<t<<'\n';
              temp.pop();
            }
            temp.push({t, s.top().y});
          }
          s.pop();
        }
      } else {
        checkRight = false;
        break;
      }
    }
  } 
  if(checkRight){
    int ans = 1;
    while(!temp.empty()){
      ans+=temp.top().x;
      temp.pop();
    }
    cout<<ans;
  } else cout << 999;

  return 0;
}