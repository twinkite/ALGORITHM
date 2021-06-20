#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[10];
    fill(arr, arr+10, 0);
    int N;
    cin>>N;
    while(N>0){
        arr[N%10]++;
        N/=10;
    }
    int max=0;
    int temp=arr[6]+arr[9];
    if(temp%2!=0) temp+=1;
    arr[6]=temp/2; arr[9]=0;
    for(int i=0;i<10;i++){
        if(arr[i]>max) max=arr[i];
    }
    if(max==0) max=1;
    cout<<max;
    return 0;
}