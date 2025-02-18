#include<iostream>
#include<string>

using namespace std;

void power(int a, int b, int& c) {
    c = a;
    for (int i = 1; i < b; ++i) {
        c = c * a;
    }
}