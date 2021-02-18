#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPowerof2(int n){
	return (n && !(n&(n-1)));
}
int main(){
	// int n = 12;   // Not power of 2
	int n = 64;   // Power of 2
	if(isPowerof2(n)){
		cout<< "Given number is power of 2"<<endl;
	}
	else{
		cout<< "Given number is not power of 2"<<endl;
	}
	return 0;
}