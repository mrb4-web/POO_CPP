#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ressource {
protected:
    int id;
    string auteur;
    string titre;
    int anne;
public:
    Ressource(int Id, string Au, string T, int ann)
        : id(Id), auteur(Au), titre(T), anne(ann) {}

    virtual void afficher() const {
        cout << "ID: " << id << endl;
        cout << "Auteur: " << auteur << endl;
        cout << "Titre: " << titre << endl;
        cout << "Année: " << anne << endl;
    }

    virtual void telecharger() const {
        cout << "Téléchargement en cours..." << endl;
    }

    int getId() const { return id; }
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return anne; }

    bool operator==(const Ressource& other) const {
        return this->id == other.id;
    }

    virtual ~Ressource() {}
};

class Telechargeable {
public:
    virtual void telecharger() const = 0;
    virtual void afficherMessage() const {
        cout << "Votre fichier est prêt." << endl;
    }
    virtual ~Telechargeable() {}
};

class Livre : public Ressource, public Telechargeable {
    int nbrPages;
public:
    Livre(int Id, string Au, string T, int ann, int Nb)
        : Ressource(Id, Au, T, ann), nbrPages(Nb) {}

    void afficher() const override {
        Ressource::afficher();
        cout << "Nombre de pages: " << nbrPages << endl;
    }

    void telecharger() const override {
        cout << "Le livre \"" << titre << "\" est en cours de téléchargement..." << endl;
    }
};

class Magazine : public Ressource, public Telechargeable {
    int nbrPages;
public:
    Magazine(int Id, string Au, string T, int ann, int Nb)
        : Ressource(Id, Au, T, ann), nbrPages(Nb) {}

    void afficher() const override {
        Ressource::afficher();
        cout << "Nombre de pages: " << nbrPages << endl;
    }

    void telecharger() const override {
        cout << "Le magazine \"" << titre << "\" est en cours de téléchargement..." << endl;
    }
};

class Video : public Ressource, public Telechargeable {
    float duree;
public:
    Video(int Id, string Au, string T, int ann, float dur)
        : Ressource(Id, Au, T, ann), duree(dur) {}

    void afficher() const override {
        Ressource::afficher();
        cout << "Durée: " << duree << " minutes" << endl;
    }

    void telecharger() const override {
        cout << "La vidéo \"" << titre << "\" est en cours de téléchargement..." << endl;
    }
};

class Mediatheque {
    vector<Ressource*> ressources;
public:
    void ajouter(Ressource* r) {
        ressources.push_back(r);
    }

    void afficherTous() const {
        for (Ressource* r : ressources) {
            r->afficher();
            cout << "---------------------------" << endl;
        }
    }

    Ressource* rechercher(const string& titre) const {
        for (auto r : ressources)
            if (r->getTitre() == titre)
                return r;
        return nullptr;
    }

    vector<Ressource*> rechercher(int annee) const {
        vector<Ressource*> res;
        for (auto r : ressources)
            if (r->getAnnee() == annee)
                res.push_back(r);
        return res;
    }

    vector<Ressource*> rechercher(const string& auteur, int annee) const {
        vector<Ressource*> res;
        for (auto r : ressources)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                res.push_back(r);
        return res;
    }

    ~Mediatheque() {
        for (auto r : ressources)
            delete r;
    }
};

int main() {
    Mediatheque mediatheque;

    Livre* livre1 = new Livre(1, "Antoine de Saint-Exupéry", "Le Petit Prince", 1943, 96);
    Magazine* mag1 = new Magazine(2, "Various", "National Geographic", 2023, 120);
    Video* vid1 = new Video(3, "BBC", "Planet Earth", 2006, 550.0f);

    mediatheque.ajouter(livre1);
    mediatheque.ajouter(mag1);
    mediatheque.ajouter(vid1);

    cout << "=== Toutes les ressources ===" << endl;
    mediatheque.afficherTous();

    cout << "=== Téléchargements ===" << endl;
    livre1->telecharger();
    mag1->telecharger();
    vid1->telecharger();

    cout << "\n=== Recherche par titre: 'Le Petit Prince' ===" << endl;
    Ressource* found = mediatheque.rechercher("Le Petit Prince");
    if (found) {
        found->afficher();
        found->telecharger();
    } else {
        cout << "Ressource non trouvée." << endl;
    }

    cout << "\n=== Comparaison de ressources ===" << endl;
    if (*livre1 == *mag1)
        cout << "Livre1 et Mag1 ont le même ID." << endl;
    else
        cout << "Livre1 et Mag1 ont des IDs différents." << endl;

    return 0;
}
