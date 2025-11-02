#include<iostream>
using namespace std;
int main(){
    int a;
    int& ref_a=a; 
    int *p_a=&a;
    cout << "Variable a :" << endl;
    cout << "  Valeur : " << a << endl;
    cout << "  Adresse : " << &a << endl << endl;
    
    cout << "Référence ref_a :" << endl;
    cout << "  Valeur : " << ref_a << endl;
    cout << "  Adresse : " << &ref_a << endl << endl;
    
    cout << "Pointeur p_a :" << endl;
    cout << "  Valeur (adresse stockée) : " << p_a << endl;
    cout << "  Adresse du pointeur : " << &p_a << endl;
    cout << "  Valeur pointée : " << *p_a << endl;
    return 0;
}