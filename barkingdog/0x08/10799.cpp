#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  stack<char> bracket;
  int stick = 0, res=0;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='(' && s[i+1]==')'){
      res += stick;
      i++;
    } else if(s[i]=='('){
      bracket.push('(');
      res++;
      stick++;
    } else if(s[i]==')'){
      bracket.pop();
      stick--;
    }
  }
  cout<< res;
  return 0;
}