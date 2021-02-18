#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const char hashTable[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printWordUtil(int num[], int curr_dig, char res[], int n){
    if(curr_dig == n){
        cout<< res << " ";
    }
    for(int i=0; i<strlen(hashTable[num[curr_dig]]); i++){
        res[curr_dig]=hashTable[num[curr_dig]][i];
        printWordUtil(num, curr_dig+1, res, n);
        
        if(num[curr_dig]==1 || num[curr_dig]==0){
            return;
        }
    }
}
void printWord(int num[], int n){
    char res[n+1];
    res[n]='\0';
    printWordUtil(num, 0, res, n);
}
int main() {
	int num[]={2,3,4};
	printWord(num, 3);
	return 0;
}