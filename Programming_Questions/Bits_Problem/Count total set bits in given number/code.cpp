#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
	int count=0;
	while(n){
		n = n&(n-1);
		count+=1;
	}
	return count;
}
int main(){
	//int n=4; // count = 1
	int n=14; //connt = 3
	cout<< "Total number of set bits: "<< countSetBits(n)<<endl;
	return 0;
}