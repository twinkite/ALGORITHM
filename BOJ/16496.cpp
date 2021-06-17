#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp (string s1, string s2){
    return s1>s2;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, max = 0;
    string str;
    string s[1001];
    cin>>N>>str;
    for(int i=0;i<N;i++){
      s[i] = strtok(NULL," ");  
    }
    
    if(N==1 && v[0]=="0") cout<<0;
    else{
        sort(v, s+N, cmp);
    }
    
}