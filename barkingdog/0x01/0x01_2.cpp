#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, temp, res=0;
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>temp;
        v[i]=temp;
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(v[i]+v[j]==100) res=1;
        }
    }
    cout<<res;
}