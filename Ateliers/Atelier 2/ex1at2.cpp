#include<iostream>
using namespace std;
int n=1;
void nbr_appell() {
	cout<< "appel numero " << n << endl;
	n++;
}
int main() {
	nbr_appell();
	nbr_appell();
	nbr_appell();
    
	return 0;
}