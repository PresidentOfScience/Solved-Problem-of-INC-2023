#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>
#include<queue>

#define ll long long

using namespace std;

bool sortColumn(vector<ll>& v1, vector<ll>& v2)
{
    return v1[0] < v2[0];
}

int main(){
	ll n, m;
	cin >> n >> m;
	
	priority_queue<ll> queue;
	
	vector<vector<ll> > stuff(n, vector<ll>(2));
	vector<ll> horse(m);
	for (ll i = 0; i < n; i++) {
		ll weight, val;
		cin >> stuff[i][0] >> stuff[i][1];
	}
	sort(stuff.begin(), stuff.end(), sortColumn);

	for (ll i = 0; i < m; i++) cin >> horse[i];
	sort(horse.begin(), horse.end());
	ll ans = 0;
	
	ll curPos = 0;
	
	for (ll i = 0; i < m; i++){
		while(curPos < n && stuff[curPos][0] <= horse[i]){
			queue.push(stuff[curPos++][1]);
		}
		if (!queue.empty()){
			ans += queue.top();
			queue.pop();
		}	
	}
	
	cout << ans << endl;
	
	return 0;
}
