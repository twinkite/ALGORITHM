#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pii> tower;
    int N, temp; 
    cin>>N;
    tower.push({100000001,0});
    for(int i=1;i<=N;i++){
        cin>>temp;
        if(tower.top().x>temp){
            cout<<tower.top().y<<" ";
            tower.push({temp,i});
        } else {
            while(tower.top().x<temp){
                tower.pop();
            }
            cout<<tower.top().y<<" ";
            tower.push({temp,i});
        }
    }
    return 0;
}