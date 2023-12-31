#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
#define ll long long int
using namespace std;
ll getWays(ll n, vector<ll>coins){
	ll m = coins.size();
	ll table[n+1][m];
	for(int i=0; i<m; i++){
		table[0][i]=1;
	}
	for(ll i=1; i<n+1; i++){
		for(ll j=0; j<m; j++){
			ll x = (i-coins[j]>=0)?table[i-coins[j]][j]:0;
			ll y = (j>=1)?table[i][j-1]:0;
			table[i][j]=x+y;
		}
	}
	return table[n][m-1];
}
int main(){
	ll n=10;
	vector<ll>coins={2,5,3,6};
	ll N = getWays(n,coins);
	cout<< "Total number of ways: "<<N<<endl;
	return 0;
}