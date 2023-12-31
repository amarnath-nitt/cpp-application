#include <iostream>
using namespace std;
int main(){
    int a = 5;
    cout << "size of int: " << sizeof(a) << endl;

    char ch = 'a';
    cout << "size of char: " << sizeof(ch) << endl;

    float f = 5.5;
    cout << "size of float: " << sizeof(f) << endl;

    bool bl = true;
    cout << "size of bool: " << sizeof(bl) << endl;

    long long  l = 5;
    cout << "size of long long: " << sizeof(l) << endl;

    double d = 5.5;
    cout << "size of double: " << sizeof(d) << endl;

    long double ld = 5.5;
    cout<< "size of long double: " << sizeof(ld) << endl;

    long long int ll = 55;
    cout<< "size of long long int: " << sizeof(ll) << endl;
}