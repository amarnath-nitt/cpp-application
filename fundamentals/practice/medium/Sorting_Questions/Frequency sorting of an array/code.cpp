#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
#define ll long long int
using namespace std;
void frequencySort(vector<int>v, int n){
	map<int,int>m;
	for(int i=0; i<n; i++){
		m[v[i]]+=1;
	}
	vector<pair<int,int>>V;
	for(auto &x:m){
		V.push_back(x);
	}
	sort(V.begin(), V.end(),[](const pair<int,int>&a, const pair<int,int>&b){
		if(a.second==b.second){
			return a.first<b.first;
		}
		else{
			return a.second>b.second;
		}
	});
	for(int i=0; i<V.size(); i++){
		for(int j=0; j<V[i].second; j++){
			cout<< V[i].first<<" ";
		}
	}
	cout<< endl;
}
int main(){
	int n = 5;
	vector<int>v={5,5,4,6,4};
	cout<< "Array before sorting: "<<endl;
	for(auto &x:v){
		cout<< x<< " ";
	}
	cout<< "\nArray after frequency sorting: "<<endl;
	frequencySort(v,n);
	return 0;
}