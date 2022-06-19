#include <iostream>
#include <string>
using namespace std;

int N, sum = 0, idx=0;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>t;
        sum+=t;
    }

    s+= to_string(sum/N);
    if(sum%N != 0) {s+='.';}
    if(sum%N == 0) {s+=".0";}
    while((sum%N!=0) && idx < 4){
        s += to_string(sum/N);
        sum = sum%N;
        idx++;
    }
    cout<<s;

    return 0;
}