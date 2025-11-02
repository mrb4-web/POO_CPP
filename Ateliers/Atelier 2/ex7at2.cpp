#include <iostream>
using namespace std;

void permuter(char& a, char& b) { char tmp = a; a = b; b = tmp; }

void permutations(string s, int i, int n) {
    if (i == n) cout << s << endl;
    else {
        for (int j = i; j <= n; j++) {
            permuter(s[i], s[j]);
            permutations(s, i + 1, n);
            permuter(s[i], s[j]);
        }
    }
}

int main() {
    string mot;
    cin >> mot;
    permutations(mot, 0, mot.size() - 1);
    return 0;
}