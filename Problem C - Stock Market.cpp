#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

#define ll long long

using namespace std;

int main(){
	ll n, p, x;
	cin >> n >> p >> x;
	ll nums[n + 1], temp;
	nums[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> temp;
		nums[i] = nums[i - 1] + temp;
	}
	
	ll ans = 1e9 + 1;
	for (int i = 0; i < n; i++){
		if (p + nums[i] >= x){
			temp = (p + nums[i] - x) % nums[n] + x;
			ans = min(ans, temp);
		}
	}
	
	cout << (ans == 1e9 + 1 ? -1 : ans) << endl;
	
	return 0;
}
