#include <iostream>
using namespace std;

int main() {
    cout << "enter 10 entiers" << endl;
    int tab[10];
    for (int i = 0; i < 10; i++) cin >> tab[i];

    int min = tab[0], max = tab[0];
    for (int i = 1; i < 10; i++) {
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
    }
    cout << "min = " << min << ", max = " << max << endl;
    return 0;
}