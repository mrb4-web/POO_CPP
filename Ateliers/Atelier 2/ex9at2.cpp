#include<iostream>
#include<string>
using namespace std;
class vecteur3d {
	private:
	float x, y, z;
	public:
		void vecteur() {}
		void afficher(float a, float b, float c) {
			x = a;
			y = b;
			z = c;
			cout<<"Vecteur cree: ("<<x<<","<<y<<","<<z<<")"<<endl;
		}
		void somme(float a, float b, float c) {
			x += a;
			y += b;
			z += c;
			cout<<"Somme: ("<<x<<","<<y<<","<<z<<")"<<endl;
		}
		void produit_scalaire(float a, float b, float c) {
			float produit = x * a + y * b + z * c;
			cout<<"Produit scalaire: "<<produit<<endl;
		}
		void coincide(float a, float b, float c) {
			if (x == a && y == b && z == c) {
				cout<<"Les vecteurs coincident."<<endl;
			} else {
				cout<<"Les vecteurs ne coincident pas."<<endl;
			}
		}
		float norme(float a,float b,float c) {
			float norme1 = sqrt(x * x + y * y + z * z);
			float norme2 = sqrt(a * a + b * b + c * c);
			return norme1, norme2;
		}
		void normax(float norme1,float norme2) {
			if (norme1 > norme2) {
				cout<<"Le plus grande norme est: "<<norme1<<endl;
			} else if (norme2 > norme1) {
				cout<<"Le plus grande norme est:"<<norme2<<endl;
			} else 
				cout<<"Les deux vecteurs ont la meme norme."<<endl;
			}
};
		int main() {
			vecteur3d v1, v2;
			float x1, y1, z1, x2, y2, z2;
			cout<<"Entrez les composantes du premier vecteur (x y z): ";
			cin>>x1>>y1>>z1;
			v1.afficher(x1, y1, z1);
			cout<<"Entrez les composantes du deuxieme vecteur (x y z): ";
			cin>>x2>>y2>>z2;
			v2.afficher(x2, y2, z2);
			v1.somme(x2, y2, z2);
			v1.produit_scalaire(x2, y2, z2);
			v1.coincide(x2, y2, z2);
			float norme1 = v1.norme(x1, y1, z1);
			float norme2 = v2.norme(x2, y2, z2);
			v1.normax(norme1, norme2);

			return 0;
		}