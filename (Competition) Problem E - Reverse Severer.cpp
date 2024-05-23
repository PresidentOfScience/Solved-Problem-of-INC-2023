#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

#define ll long long

using namespace std;

int main(){
	int n;
	string text;
	cin >> n;
	cin >> text;
	int q;
	cin >> q;
	while(q--){
		string find;
		cin >> find;
		int start = 0;
		bool can = 1;
		for (int i = 0; i < n; i++){
			if (find.substr(start, i - start + 1).compare(text.substr(n - i - 1, i - start + 1)) == 0){
				start = i + 1;
			}
		}
		if (start != n) can = 0;
		can ? cout << "YES" << endl : cout << "NO" << endl;
	}
	
	return 0;
}
