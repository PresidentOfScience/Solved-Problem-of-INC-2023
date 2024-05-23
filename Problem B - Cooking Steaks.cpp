#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	long long int n;
	cin >> n;
	long long int time[n];
	time[0] = 0;
	for (int i = 1; i < n; i++) cin >> time[i];
	long long int doneness[n];
	for (int i = 0; i < n; i++) cin >> doneness[i];
	long long int need[n];
	for (int i = 0; i < n; i++) cin >> need[i];
	long long int ans = 0, steakNeeded = 0;
	
	for (int i = n - 1; i >= 0; i--){
		if (doneness[i] >= need[i]){
			doneness[i] -= need[i];
			need[i] = 0;
			if (steakNeeded > 0) steakNeeded -= min(steakNeeded, doneness[i]);
		}
		else{
			need[i] -= doneness[i];
			doneness[i] = 0;
			steakNeeded += need[i];
		}
		ans += time[i] * steakNeeded;
	}
	steakNeeded > 0 ? cout << "-1\n" : cout << ans << endl;
	return 0;
}
