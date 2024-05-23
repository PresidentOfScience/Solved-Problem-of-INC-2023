#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	int max = 0, ans = 0;
	sort(nums, nums + n);
	for (int i = 0; i < n - 2; i++){
		for (int j  = i + 1; j < n - 1; j++){
			for (int k = j + 1; k < n; k++){
				if (nums[k] - nums[i] <= m){
					ans++;
					if (nums[i] + nums[j] + nums[k] >= max){
						max = nums[i] + nums[j] + nums[k];
					}
				}
			}
		}
	}
	ans ? cout << ans << " " << max << endl : cout << "-1\n";
	
	return 0;
}
