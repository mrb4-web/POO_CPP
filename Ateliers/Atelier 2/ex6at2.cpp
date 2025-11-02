
#include <iostream>
using namespace std;

// Version avec pointeurs (style C)
void incrementer(int* x) {
    (*x)++;
}

void permuter(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Version avec références (style C++)
void incrementer(int& x) {
    x++;
}

void permuter(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // Test avec pointeurs
    cout << " Version avec pointeurs" << endl;
    int x = 5, y = 10;
    cout << "Avant : x = " << x << ", y = " << y << endl;
    
    incrementer(&x);
    permuter(&x, &y);
    
    cout << "Après : x = " << x << ", y = " << y << endl;
    
    // Test avec références
    cout << "\n Version avec références" << endl;
    int a = 5, b = 10;
    cout << "Avant : a = " << a << ", b = " << b << endl;
    
    incrementer(a);
    permuter(a, b);
    
    cout << "Après : a = " << a << ", b = " << b << endl;
    
    return 0;
}
