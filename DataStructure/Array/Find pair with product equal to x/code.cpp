#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isProduct(int arr[], int n, int x){
	unordered_set<int>st;
	for(int i=0; i<n; i++){
	 if(arr[0]==0){
		if(x==0){
			return true;
		}
		else{
			continue;
		}
	 }
	 if(x%arr[i]==0){
	 	if(st.find(x/arr[i])!=st.end()){
	 		return true;
	 	}
	 	st.insert(arr[i]);
	 }
  }
  return false;
}
int main(){
	int n = 4;
	//int arr[4] = {10,20,30,40}; // "Yes"
	int arr[4] = {10,20,30,50}; // "No"
	int x = 400;
	if(isProduct(arr, n, x)){
		cout<< "Yes"<<endl;
	}
	else{
		cout<< "No"<<endl;
	}
	return 0;
}