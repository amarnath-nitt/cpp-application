#include <iostream>
#include "pattern.cpp"
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    Solution *solution = new Solution();
    solution->printEqulateralTriangle(n);
}