#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printClosest(int arr[][2], int n,  int k){
	map<int,int>mp;
	for(int i=0; i<n; i++){
		int x = arr[i][0];
		int y = arr[i][1];
		mp.insert({x*x+y*y,i});
	}
	for(auto it=mp.begin(); it!=mp.end() && k>0; it++, k--){
		cout<< arr[it->second][0] << " "<< arr[it->second][1]<<endl;
	}

}
int main(){
	int n = 5;
	int arr[5][2]={
                         {1,3},
                         {-2,5},
                         {-4,0},
                         {2,-5},
                         {-1,-2}
                        };

    int k=2;
    printClosest(arr,n, k);
    return 0;
}