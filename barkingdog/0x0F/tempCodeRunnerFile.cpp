#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, curcnt, maxcnt=0;
    long long maxval=0, curval=0;

    cin>>N;
    
    vector<long long> v(N);

    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    curval=v[0]; maxval=v[0]; curcnt=1; maxcnt=1;
    for(int i=1;i<N;i++){
        if(curval!=v[i]){
            if(maxcnt<curcnt){
                maxval=curval;
                maxcnt=maxcnt;
            }
            curval=v[i];
            curcnt=1;
        }else if(curval==v[i]){
            curcnt++;
        }
    }
    if(curcnt>maxcnt) maxval=curval;
    cout<<maxval;

    return 0;
}