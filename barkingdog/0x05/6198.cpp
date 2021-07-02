#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, temp, res;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	stack<ll> s;
	for(int i=0;i<N;i++){
		cin>>temp;
		while(!s.empty() && s.top() <= temp) s.pop();
		res += (ll)s.size();
		s.push(temp);
	}
	cout<<res;
	return 0;
}