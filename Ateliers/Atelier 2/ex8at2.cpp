#include <iostream>
using namespace std;

class Voiture {
private:
    string marque, modele;
    int annee;
    float kilometrage, vitesse;
public:
    Voiture() { marque = "Inconnue"; modele = "Inconnu"; annee = 0; kilometrage = 0; vitesse = 0; }
    Voiture(string m, string mod, int a, float km, float v) { marque = m; modele = mod; annee = a; kilometrage = km; vitesse = v; }
    void accelerer(float v) { vitesse += v; }
    void freiner(float v) { vitesse -= v; if (vitesse < 0)vitesse = 0; }
    void avancer(float d) { kilometrage += d; }
    void afficherInfo() {
        cout << "Marque:" << marque << "\nModele:" << modele << "\nAnnee:" << annee << "\nKm:" << kilometrage << "\nVitesse:" << vitesse << endl;
    }
    ~Voiture() { cout << "Voiture detruite" << endl; }
};

int main() {
    Voiture v1("Toyota", "Corolla", 2020, 50000, 0);
    v1.accelerer(50);
    v1.avancer(120);
    v1.freiner(30);
    v1.afficherInfo();
    return 0;
}