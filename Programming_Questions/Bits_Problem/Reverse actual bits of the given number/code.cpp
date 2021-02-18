#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int reverseBits(int n){
	int rev=0;
	while(n>0){
		rev<<=1;
        if(n&1==1){
        	rev^=1;
        }
		n>>=1;
	}
	return rev;
}
int main(){
	//int n = 11; // O/P = 13;
	int n = 14; // O/P = 7
	cout<< reverseBits(n)<<endl;
	return 0;
}