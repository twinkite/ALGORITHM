#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, temp, res=0;
    cin>>n;
    vector<int> arr(1000001);
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
        cin>>temp;
        v[i]=temp;
        arr[temp]++;
    }
    
    cin>>x;
    for(int i=0;i<n;i++){
        if(x-v[i]<=100000 && arr[x-v[i]]==1) res++;
    }

    cout<<res;
    return 0;
}