#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

#define ll long long

using namespace std;

int dp[101][101][101];

int solve(int arr[], int curr, int m, int k, int ans, int n){
	if ((m <= 0 && k <= 0) || curr >= n) return ans;
	int first = ans;
	int second = ans;
	if (dp[curr][m][k] != 0) return dp[curr][m][k];
	if (m >= arr[curr]) first = solve(arr, curr + 1, m - arr[curr], k, ans + 1, n);
	if (k) second = solve(arr, curr + 1, m, k - 1, ans + 1, n);
	return dp[curr][m][k] = max(first, second);
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << solve(nums, 0, m, k, 0, n);
	return 0;
}
