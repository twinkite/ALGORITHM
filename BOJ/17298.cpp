#include <iostream>
#include <stack>
#define pii pair<int, int>
using namespace std;

stack<pii> s;
int ans[1111111];
int N;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    int temp;
    for(int i=1;i<=N;i++){
        cin>>temp;
        while(!s.empty()&&s.top().first<temp){
            ans[s.top().second]=temp;
            s.pop();
        }
        s.push({temp,i});
    }
    while(!s.empty()){
        ans[s.top().second]=-1;
        s.pop();
    }
    for(int i=1;i<=N;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}