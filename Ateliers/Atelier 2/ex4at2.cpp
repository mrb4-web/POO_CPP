#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "taille du tableau : ";
    cin >> n;

    int* t = new int[n];
    for (int i = 0; i < n; i++) cin >> t[i];

    int* carre = new int[n];
    for (int i = 0; i < n; i++) carre[i] = t[i] * t[i];

    delete[] t;
    for (int i = 0; i < n; i++) cout << carre[i] << " ";
    delete[] carre;
    return 0;
}