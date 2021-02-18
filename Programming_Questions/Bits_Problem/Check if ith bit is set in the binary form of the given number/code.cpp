#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(int n, int i){
	if(n&(1<<i)){
		return true;
	}
	else{
		return false;
	}

	// Other Method

	// string str = bitset<64>(n).to_string();
	// if(str[str.length()-i]=='1'){
	// 	return true;
	// }
	// else{
	// 	return false;
	// }
}
int main(){
	//int n = 14; // "Yes"
	int n = 4; // "No"
	int i = 2;
	if(check(n,i)){
		cout<< "Yes, ith bit is set in given number"<<endl;
	}
	else{
		cout<< "No, ith bit is set in given number"<<endl;
	}
	return 0;
}