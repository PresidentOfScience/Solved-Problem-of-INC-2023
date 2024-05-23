#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

#define ll long long

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	string ins2[n];
	string ans[n];
	int curr = 0, ansCurr = 0;
	for (int i = 0; i < n; i++){
		string team, ins;
		cin >> team >> ins;
		if (i < m) ins2[curr++] = ins;
		else{
			bool can = 1;
			for (int j = 0; j < curr; j++){
				if (ins == ins2[j]){
					can = 0;
					break;
				}
			}
			if (can && ansCurr < k){
				ans[ansCurr++] = team;
				ins2[curr++] = ins;
			}
		}
	}
	cout << ansCurr << endl;
	for (int i = 0; i < ansCurr; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
