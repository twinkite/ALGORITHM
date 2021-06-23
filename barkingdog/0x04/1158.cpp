#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin>>N>>K;
    list<int> circle;
    auto cursor = circle.begin();
    for(int i=1; i<=N; i++){
        circle.push_back(i);
    }
    cout<<"<";
    while(!circle.empty()){
        int temp = K;
        while(temp--){
            if(cursor==--(circle.end())) cursor=circle.begin();
            else cursor++;
        }
        cout<<*cursor;
        cursor=circle.erase(cursor);
        cursor--;
        if(!circle.empty()){
            cout<<", ";
        }
    }
    cout<<">";
    return 0;
}