#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    map <string, int> m;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        if(m.find(s)!=m.end()){
            m[s]+=1;
        } else {
            m.insert({s, 1});
        }
    }
    int ans=0;
    string temp;
    for(auto iter = m.begin(); iter!=m.end();iter++){
        if(iter->second >ans){
            ans=iter->second;
            temp=iter->first;
        } else if(iter->second == ans){
            long long temp1 = stoll(temp);
            long long temp2 = stoll(iter->first);
            if(temp1>temp2){
                ans=iter->second;
                temp=iter->first;
            }
        }
    }
    cout<<temp;
}