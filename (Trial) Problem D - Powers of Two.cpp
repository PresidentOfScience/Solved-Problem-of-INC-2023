#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

int addPow(int pows[], int index, int value){
	pows[index] += value;
	if (pows[index] == 0) return -1;
	else if (pows[index] == 1 || pows[index] == -1) return 1;
	else{
		int curr = pows[index];
		pows[index] = 0;
		return addPow(pows, index + 1, curr / 2) - 1;
	}
}

int main(){
	int q;
	cin >> q;
	int pows[200100], amount = 0, index;
	char temp;
	memset(pows, 0, sizeof(pows));
	while(q--){
		cin >> temp >> index;
		amount += addPow(pows, index, temp == '-' ? -1 : 1);
		amount == 0 ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}
