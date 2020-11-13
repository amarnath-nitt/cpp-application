#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;
vector<int> BinaryRepresentation(int n){
    vector<int>v;
    while(n>0){
        int r = n%2;
        v.push_back(r);
        n = n/2;
    }
    
    reverse(v.begin(),v.end());
    return v;
}
int BinaryToDecimal(vector<int>v){
    int sum=0;
    int n = v.size();
    for(int i=n-1; i>=0; i--){
        sum+= v[i]*(pow(2,n-1-i));
    }
    return sum;
}
vector<int>ToggleBits(vector<int>v){
    int n = v.size();
    for(int i=1; i<n-1; i++){
        if(v[i]==0){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
    }
    return v;
}
int main() {
	int n=10;
	//cin>>n;
	cout<< "Before Toggling number: "<< n<<endl;
	vector<int>v=BinaryRepresentation(n);
	vector<int>t=ToggleBits(v);
	int N = BinaryToDecimal(t);
	cout<< "After Toggling number: "<< N<<endl;
	return 0;
}