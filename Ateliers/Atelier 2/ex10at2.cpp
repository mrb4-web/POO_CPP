
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class nbr_cpmlx {
private:
    float reel;
    float imag;
public:
    // Constructeurs
    nbr_cpmlx(float r = 0, float i = 0) {
        reel = r;
        imag = i;
    }
    
    void afficher() {
        if (imag >= 0)
            cout << reel << " + " << imag << "i";
        else
            cout << reel << " - " << -imag << "i";
    }
    
    // Méthodes qui retournent de nouveaux objets (ne modifient pas l'original)
    nbr_cpmlx addition(nbr_cpmlx c) {
        return nbr_cpmlx(reel + c.reel, imag + c.imag);
    }
    
    nbr_cpmlx soustraction(nbr_cpmlx c) {
        return nbr_cpmlx(reel - c.reel, imag - c.imag);
    }
    
    nbr_cpmlx multiplication(nbr_cpmlx c) {
        float r = reel * c.reel - imag * c.imag;
        float i = reel * c.imag + imag * c.reel;
        return nbr_cpmlx(r, i);
    }
    
    nbr_cpmlx division(nbr_cpmlx c) {
        float denom = c.reel * c.reel + c.imag * c.imag;
        if (denom == 0) {
            cout << "Erreur: Division par zero!" << endl;
            return nbr_cpmlx(0, 0);
        }
        float r = (reel * c.reel + imag * c.imag) / denom;
        float i = (imag * c.reel - reel * c.imag) / denom;
        return nbr_cpmlx(r, i);
    }
    
    bool egalite(nbr_cpmlx c) {
        return (reel == c.reel && imag == c.imag);
    }
};

void afficherMenu() {
    cout << "\n=== MENU OPERATIONS COMPLEXES ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Egalite" << endl;
    cout << "6. Quitter" << endl;
    cout << "Votre choix: ";
}

int main() {
    float r1, i1, r2, i2;
    int choix;
    
    do {
        // Saisie des nombres complexes
        cout << "\n--- Premier nombre complexe ---" << endl;
        cout << "Partie reelle: ";
        cin >> r1;
        cout << "Partie imaginaire: ";
        cin >> i1;
        
        cout << "\n--- Deuxieme nombre complexe ---" << endl;
        cout << "Partie reelle: ";
        cin >> r2;
        cout << "Partie imaginaire: ";
        cin >> i2;
        
        nbr_cpmlx c1(r1, i1);
        nbr_cpmlx c2(r2, i2);
        nbr_cpmlx resultat;
        
        // Affichage des nombres
        cout << "\nNombres saisis:" << endl;
        cout << "c1 = "; c1.afficher(); cout << endl;
        cout << "c2 = "; c2.afficher(); cout << endl;
        
        afficherMenu();
        cin >> choix;
        
        switch(choix) {
            case 1:
                resultat = c1.addition(c2);
                cout << "\nAddition: ";
                c1.afficher(); cout << " + "; c2.afficher(); 
                cout << " = "; resultat.afficher(); cout << endl;
                break;
                
            case 2:
                resultat = c1.soustraction(c2);
                cout << "\nSoustraction: ";
                c1.afficher(); cout << " - "; c2.afficher(); 
                cout << " = "; resultat.afficher(); cout << endl;
                break;
                
            case 3:
                resultat = c1.multiplication(c2);
                cout << "\nMultiplication: ";
                c1.afficher(); cout << " * "; c2.afficher(); 
                cout << " = "; resultat.afficher(); cout << endl;
                break;
                
            case 4:
                resultat = c1.division(c2);
                cout << "\nDivision: ";
                c1.afficher(); cout << " / "; c2.afficher(); 
                cout << " = "; resultat.afficher(); cout << endl;
                break;
                
            case 5:
                cout << "\nEgalite: ";
                c1.afficher(); cout << " et "; c2.afficher();
                if (c1.egalite(c2))
                    cout << " sont EGAUX" << endl;
                else
                    cout << " sont DIFFERENTS" << endl;
                break;
                
            case 6:
                cout << "Au revoir!" << endl;
                break;
                
            default:
                cout << "Choix invalide!" << endl;
                break;
        }
        
        if (choix != 6) {
            cout << "\nAppuyez sur Entree pour continuer...";
            cin.ignore();
            cin.get();
        }
        
    } while (choix != 6);
    
    return 0;
}
