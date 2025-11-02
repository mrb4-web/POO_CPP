#include <iostream>
using namespace std;

int multiple2(int n) { return n % 2 == 0; }
int multiple3(int n) { return n % 3 == 0; }

int main() {
    int n;
    cout << "donnez un entier : ";
    cin >> n;

    if (multiple2(n)) cout << "il est pair" << endl;
    if (multiple3(n)) cout << "il est multiple de 3" << endl;
    if (multiple2(n) && multiple3(n)) cout << "il est divisible par 6" << endl;

    return 0;
}