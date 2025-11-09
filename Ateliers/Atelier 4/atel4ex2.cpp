#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client {
private:
    string nom;
    string CIN;
    int idClient;
public:
    Client(string n, string c, int id) : nom(n), CIN(c), idClient(id) {}
    string getNom() const { return nom; }
    string getCIN() const { return CIN; }
    int getIdClient() const { return idClient; }
};

class CompteBancaire {
private:
    int numCompte;
    double solde;
    string codeSecret;
    Client& proprietaire;

    friend class AgentBancaire;

public:
    CompteBancaire(int num, double soldeInit, string code, Client& client)
        : numCompte(num), solde(soldeInit), codeSecret(code), proprietaire(client) {}

    int getNumCompte() const { return numCompte; }
    double getSolde() const { return solde; }
    Client& getClient() const { return proprietaire; }

    void depot(double montant) {
        if (montant > 0) solde += montant;
    }

    bool retrait(double montant) {
        if (montant > 0 && solde >= montant) {
            solde -= montant;
            return true;
        }
        return false;
    }
};

class AgentBancaire {
public:

    string consulterCodeSecret(const CompteBancaire& compte) {
        return compte.codeSecret;
    }


    bool transferer(CompteBancaire& source, CompteBancaire& destination, double montant) {
        if (source.retrait(montant)) {
            destination.depot(montant);
            return true;
        }
        return false;
    }
};

class Banque {
private:
    vector<Client> clients;
    vector<CompteBancaire> comptes;
    AgentBancaire agent;


    CompteBancaire* trouverCompte(int numCompte) {
        for (auto& compte : comptes) {
            if (compte.getNumCompte() == numCompte) {
                return &compte;
            }
        }
        return nullptr;
    }

public:
    // Ajouter client
    void ajouterClient(const string& nom, const string& CIN, int id) {
        clients.emplace_back(nom, CIN, id);
    }

    // Ajouter compte associé au client via idClient
    void ajouterCompte(int numCompte, double solde, string codeSecret, int idClient) {
        // Trouver client
        for (auto& client : clients) {
            if (client.getIdClient() == idClient) {
                comptes.emplace_back(numCompte, solde, codeSecret, client);
                return;
            }
        }
        cout << "Client ID " << idClient << " non trouvé\n";
    }

    void afficherDetailsComptes() const {
        cout << "Rapport d'audit des comptes :\n";
        for (const auto& compte : comptes) {
            cout << "Compte n°: " << compte.getNumCompte()
                 << ", Propriétaire: " << compte.getClient().getNom()
                 << ", Solde: " << compte.getSolde() << "\n";
        }
    }

    bool depot(int numCompte, double montant) {
        CompteBancaire* compte = trouverCompte(numCompte);
        if (compte != nullptr) {
            compte->depot(montant);
            return true;
        }
        return false;
    }

    bool retrait(int numCompte, double montant) {
        CompteBancaire* compte = trouverCompte(numCompte);
        if (compte != nullptr) {
            return compte->retrait(montant);
        }
        return false;
    }

    bool transfer(int numCompteSource, int numCompteDest, double montant) {
        CompteBancaire* source = trouverCompte(numCompteSource);
        CompteBancaire* dest = trouverCompte(numCompteDest);
        if (source != nullptr && dest != nullptr) {
            return agent.transferer(*source, *dest, montant);
        }
        return false;
    }

    void afficherCodeSecret(int numCompte) {
        CompteBancaire* compte = trouverCompte(numCompte);
        if (compte != nullptr) {
            cout << "Code secret du compte " << numCompte << " : " << agent.consulterCodeSecret(*compte) << "\n";
        } else {
            cout << "Compte non trouvé\n";
        }
    }
};

int main() {
    Banque banque;

    // Créer clients
    banque.ajouterClient("Dupont", "CIN001", 1);
    banque.ajouterClient("Martin", "CIN002", 2);

    // Créer comptes
    banque.ajouterCompte(1001, 5000.0, "codeSecret1", 1);
    banque.ajouterCompte(1002, 3000.0, "codeSecret2", 2);

    // Simuler opérations
    banque.depot(1001, 2000);
    banque.retrait(1002, 500);
    banque.transfer(1001, 1002, 1000);

    // Afficher rapport d'audit
    banque.afficherDetailsComptes();

    // Afficher code secret (via agent)
    banque.afficherCodeSecret(1001);

    return 0;
}
