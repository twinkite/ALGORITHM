#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string init;
    cin>>init;
    list<char> lt;
    for( auto c : init ) lt.push_back(c);
    auto cursor = lt.end();
    int N;
    cin>>N;
    while(N--){
        char op;
        cin>>op;
        if(op == 'L') {
            if(cursor!=lt.begin()) cursor--;
        }else if(op == 'D') {
            if(cursor != lt.end()) cursor++;
        }else if(op == 'B'){
            if(cursor != lt.begin()){
            cursor--;
            cursor = lt.erase(cursor);}
        }else if(op == 'P'){
            char add;
            cin>>add;
            lt.insert(cursor, add);
        } 
    }

    for( auto c : lt){
        cout<<c;
    }
    return 0;
}