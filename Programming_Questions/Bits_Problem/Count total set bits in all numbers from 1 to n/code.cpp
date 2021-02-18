#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
	n++;
	int powerOf2=2;
	int count = n/2;
	while(powerOf2<=n){
		int total = n/powerOf2;
		count += (total/2)*powerOf2;
		count += (total & 1)? (n%powerOf2):0;
		powerOf2<<=1;
	}
	return count;
}
int main(){
	//int n=3; // count = 4
	//int n=6; // count = 9
	int n=8; // count = 13

	cout<<"Total number of set bits: "<< countSetBits(n)<<endl;
	return 0;
}