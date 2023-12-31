#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> productArray(vector<int>v, int n){
	if(n==1){
		v[0]=0;
		return v;
	}
	vector<int>arr(n,1);
	int temp=1;
	for(int i=0; i<n; i++){
		arr[i] =temp;
		temp *= v[i];
	}
	temp=1;
	for(int i=n-1;i >=0; i--){
		arr[i] *=temp;
		temp *=v[i];
	}
	return arr;
}
int main(){
	vector<int>v={10,3,5,6,2};
	v = productArray(v,v.size());
	for(auto x:v){
		cout<< x<<  " ";
	}
	cout<<endl;
	return 0;
}