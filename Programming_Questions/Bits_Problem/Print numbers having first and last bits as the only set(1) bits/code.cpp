#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
#define ll long long int
using namespace std;
bool onlyFirstAndLastSet(int n){
    if(n==1){
        return true;
    }
    if(n==2){
        return false;
    }
    return (((n-1)&(n-2))==0);
}
int main() {
	int n=10;
	//cin>>n;
	for(int i=1; i<=n; i++){
	    if(onlyFirstAndLastSet(i)){
	        cout<< i<< " ";
	    }
	    else{
	        continue;
	    }
	}
	cout<< endl;
	return 0;
}