#include <iostream>
#include "personnage.h" //Ne pas oublier

using namespace std;

int main()
{
    Personnage david, goliath("Epée aiguisée",20);
    Personnage allan("Epée aiguisée",20);
    Personnage ymap(allan); // Création de yamp en copiant les attributs de Allan
    //Création de 2 objets de type Personnage :allan et ymap

    goliath.attaquer(david); //goliath attaque david
    david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david); //goliath attaque david
    david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);

    return 0;
}