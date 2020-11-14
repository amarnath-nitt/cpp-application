#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
#define ll long long int
using namespace std;
void fibSeries(ll n){
	vector<ll>v(n+1);
	v[0]=0;
	v[1]=1;
	for(ll i=2; i<n+1; i++){
		v[i]=v[i-1]+v[i-2];
	}
    for(ll i=0; i<n; i++){
    	cout<< v[i]<< " ";
    }
    cout<<endl;
}
int main(){
	ll n=10;
	cout<< "Fibonacci Series: ";
	fibSeries(n);
	return 0;
}