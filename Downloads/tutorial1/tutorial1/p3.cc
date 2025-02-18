#include<iostream>
#include<string>
#include "power.cc"

using namespace std;


int main(){
	int n1 = 0;
    int n2 = 0;
    int result = 0;
	cout << "Please enter two integers: ";
	cin >> n1;
    cin >> n2;
    power(n1, n2, result);
	cout << "" << n1 << " to the power of " << n2 << " is " << result << "!";
	return 0;
}
