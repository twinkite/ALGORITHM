#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    queue<char> op; 
    int N;
    int arr[100001];
    bool ck=true;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int i=1; int j=0;
    while(j<N){
        if(!s.empty()&&s.top()==arr[j]){
            j++;
            s.pop();
            op.push('-');
        } else {
            s.push(i++);
            op.push('+');
        } 
        if(i>N+1) break;
    }
    if(i>N+1){
        cout<<"NO";
    } else {
        while(!op.empty()){
            cout<<op.front()<<'\n';
            op.pop();   
        }
    }
    return 0;
}