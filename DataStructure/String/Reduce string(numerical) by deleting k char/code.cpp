#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string reducedString(string str, int k){
	vector<int>v;
	for(int i=0; i<str.length(); i++){
		v.push_back((int)str[i]-'0');
	}
	while(k--){
		auto it = max_element(v.begin(),v.end());
		v.erase(it);
	}
	string str1="";
	for(auto x:v){
		str1 += to_string(x);
	}
	return str1;
}
int main(){
	string str = "765028321"; // O/p = 0221
	string str1 = str;
	int k=5;
	str = reducedString(str, k);
	cout<< "Before: "<<str1<<endl;
	cout<< "After: "<< str<<endl;
	return 0;
}