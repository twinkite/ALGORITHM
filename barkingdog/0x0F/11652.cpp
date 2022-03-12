#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    map <long long, int> m;
    cin>>N;
    while(N--){
        long long s;
        cin>>s;
        if(m.find(s)!=m.end()){
            m[s]+=1;
        } else {
            m.insert({s, 1});
        }
    }
    int ans=0;
    long long temp;
    for(auto iter = m.begin(); iter!=m.end();iter++){
        if(iter->second >ans){
            ans=iter->second;
            temp=iter->first;
        } else if(iter->second == ans){
            if(temp>iter->first){
                ans=iter->second;
                temp=iter->first;
            }
        }
    }
    cout<<temp;
}